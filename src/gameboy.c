#include "gameboy.h"
#include "cpu.h"
#include "memory.h"
#include "instructions.h"
#include "timer.h"

#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>

const double FRAME_DURATION_MS = 1000.0 / 60.0;
const int cyclesPerFrame = 4194304 / 60;
int debug = 0;

void gameboy_init(GameBoy* gb, const char* rom_filename) {
    cpu_init(&gb->cpu);
    memory_init(&gb->mem);
    load_rom(&gb->mem, rom_filename);
    init_regular_opcode_table();
    init_cb_opcode_table();
}

uint8_t fetch_opcode(GameBoy* gb) {
    printf("PC at: 0x%02X\n", gb->cpu.pc);
    return read_memory_byte(&gb->mem, gb->cpu.pc);
}

void execute_opcode(GameBoy* gb, uint8_t opcode) {
    Opcode op;
    if (opcode == 0xCB) {
        opcode = read_memory_byte(&gb->mem, gb->cpu.pc + 1);
        gb->cpu.pc++;
        op = cb_opcode_table[opcode];
    } else {
        op = regular_opcode_table[opcode];
    }
    printf("0x%02X  %s\n", opcode, op.mnemonic);     
    uint16_t old_pc = gb->cpu.pc;
    op.handler(&gb->mem, &gb->cpu);
    
    if (gb->cpu.pc == old_pc) {
        gb->cpu.pc += op.bytes;
    }

    if (old_pc == gb->cpu.pc && op.bytes == 0) {
        printf("Warning: PC did not advance and instruction length is 0. Possible infinite loop or jump?\n");
        debug = 1;
    }

    gb->cpu.cycles += op.cycles;

    if (opcode == 0x39) debug = 1;
    if(debug) usleep(1000000);
}

void gameboy_run(GameBoy* gb) {
    
    printf("Starting gameboy_run...\n");
    int frameCount = 0;
    struct timeval frame_start, current_time;
    struct timeval time_start, time_last_checkpoint, time_fin;
    long frame_time_us;
    
    gettimeofday(&time_start, NULL);
    gettimeofday(&time_last_checkpoint, NULL);  
    gb->running = 1;

    while (gb->running) {
        gettimeofday(&frame_start, NULL);
        gb->cpu.cycles = 0;

        while (gb->cpu.cycles < cyclesPerFrame) {
            // Update timer using the Timer struct and IF in Memory
            timer_update(&gb->cpu.timer, 1, &gb->cpu.IF);
            uint8_t opcode = fetch_opcode(gb);
            execute_opcode(gb, opcode);
        }

        frameCount++;

        gettimeofday(&current_time, NULL);
        frame_time_us = (current_time.tv_sec - frame_start.tv_sec) * 1000000 + (current_time.tv_usec - frame_start.tv_usec);

        // long target_frame_time_us = 16600;
        long target_frame_time_us = FRAME_DURATION_MS * 1000; 

        if (frame_time_us < target_frame_time_us) {
            usleep(target_frame_time_us - frame_time_us);
        } else {
            printf("wtf happened here? frame time: %ld us\n", frame_time_us);
        }

        if (frameCount % 60 == 0) {
            gettimeofday(&time_fin, NULL);

            long batch_time_us = (time_fin.tv_sec - time_last_checkpoint.tv_sec) * 1000000 + (time_fin.tv_usec - time_last_checkpoint.tv_usec);

            double avg_frame_time_ms = batch_time_us / 60.0 / 1000.0;
            printf("Batch time: %f s", batch_time_us/1000000.0);
            printf("Frames %d–%d: avg frame time = %.2f ms\n", frameCount - 59, frameCount, avg_frame_time_ms);

            time_last_checkpoint = time_fin;
        }
    }
}
