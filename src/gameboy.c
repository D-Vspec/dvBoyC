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
int debug = 1;

void gameboy_init(GameBoy* gb, const char* rom_filename) {
    cpu_init(&gb->cpu);
    memory_init(&gb->mem, &gb->cpu.timer, &gb->cpu.IF, &gb->cpu.IE);
    load_rom(&gb->mem, rom_filename);
    init_regular_opcode_table();
    init_cb_opcode_table();
}

uint8_t fetch_opcode(GameBoy* gb) {
    if(debug) printf("PC at: 0x%04X\n", gb->cpu.pc);
    return read_memory_byte(&gb->mem, gb->cpu.pc);
}

static void service_interrupt(GameBoy* gb, uint16_t vector, uint8_t bit_mask) {
    gb->cpu.ime = 0; // disable IME
    gb->cpu.IF &= ~bit_mask; // acknowledge interrupt
    gb->cpu.sp -= 2;
    write_memory_word(&gb->mem, gb->cpu.sp, gb->cpu.pc);
    gb->cpu.pc = vector;
    gb->cpu.cycles += 20; 
}

static void handle_interrupts(GameBoy* gb) {
    CPU* cpu = &gb->cpu;
    if (cpu->ime == 0) return;
    uint8_t pending = cpu->IF & cpu->IE & 0x1F;
    if (!pending) return;
    if (pending & 0x01) { // VBlank
        service_interrupt(gb, 0x40, 0x01);
    } else if (pending & 0x02) { // LCD STAT
        service_interrupt(gb, 0x48, 0x02);
    } else if (pending & 0x04) { // Timer
        service_interrupt(gb, 0x50, 0x04);
    } else if (pending & 0x08) { // Serial
        service_interrupt(gb, 0x58, 0x08);
    } else if (pending & 0x10) { // Joypad
        service_interrupt(gb, 0x60, 0x10);
    }
}

static int execute_and_get_cycles(GameBoy* gb, uint8_t opcode) {
    Opcode op;
    if (opcode == 0xCB) {
        opcode = read_memory_byte(&gb->mem, gb->cpu.pc + 1);
        gb->cpu.pc++;
        op = cb_opcode_table[opcode];
    } else {
        op = regular_opcode_table[opcode];
    }
    
    if(debug) printf("0x%02X  %s\n", opcode, op.mnemonic);
    uint16_t old_pc = gb->cpu.pc;
    op.handler(&gb->mem, &gb->cpu);

    if (gb->cpu.pc == old_pc) {
        gb->cpu.pc += op.bytes;
    }

    if (old_pc == gb->cpu.pc && op.bytes == 0) {
        printf("Warning: PC did not advance and instruction length is 0. Possible infinite loop or jump?\n");
        debug = 1;
    }

    return op.cycles;
}

void gameboy_run(GameBoy* gb) {
    printf("Starting gameboy_run...\n");

    int frameCount = 0;
    
    struct timeval frame_start, current_time;
    struct timeval time_start, time_last_checkpoint, time_fin;
    
    long frame_time_us;

    if(debug) printf("Calculating timing parameters...\n");
    
    gettimeofday(&time_start, NULL);
    gettimeofday(&time_last_checkpoint, NULL);  
    gb->running = 1;

    if(debug) printf("Entering main emulation loop...\n");

    while (gb->running) {
        gettimeofday(&frame_start, NULL);
        int frameCycles = 0;

        if(debug) printf("Starting new frame %d\n", frameCount + 1);

        while (frameCycles < cyclesPerFrame) {
            // Apply delayed EI enable (EI sets ime_enable_pending=2; after next instruction executed IME=1)
            if (gb->cpu.ime_enable_pending) {
                gb->cpu.ime_enable_pending--;
                if (gb->cpu.ime_enable_pending == 0) {
                    gb->cpu.ime = 1;
                }
            }
            handle_interrupts(gb);
            uint8_t opcode = fetch_opcode(gb);
            int opCycles = execute_and_get_cycles(gb, opcode);
            timer_update(&gb->cpu.timer, opCycles, &gb->cpu.IF);
            frameCycles += opCycles;
        }

        frameCount++;

        gettimeofday(&current_time, NULL);
        frame_time_us = (current_time.tv_sec - frame_start.tv_sec) * 1000000 + (current_time.tv_usec - frame_start.tv_usec);

        long target_frame_time_us = FRAME_DURATION_MS * 1000; 

        if (frame_time_us < target_frame_time_us) {
            usleep(target_frame_time_us - frame_time_us);
        } else if(debug) {
            printf("Frame over time: %ld us\n", frame_time_us);
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
