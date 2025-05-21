#include "gameboy.h"
#include "cpu.h"
#include "flags.h"
#include "memory.h"
#include "instructions.h"

#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>

const int FRAME_DURATION_MS = 1000 / 60;
const int cyclesPerFrame = 4194304 / 60;

void gameboy_init(GameBoy* gb) {
    cpu_init(&gb->cpu);
    memory_init(&gb->mem);
    init_opcode_table();
}

uint8_t fetch_opcode(GameBoy* gb) {
    return read_memory_byte(&gb->mem, gb->cpu.pc);
}

void execute_opcode(GameBoy* gb, uint8_t opcode) {
    Opcode op = opcode_table[opcode];
    op.handler(&gb->mem, &gb->cpu);
    gb->cpu.pc += op.bytes;
    gb->cpu.cycles += op.cycles;
}

void gameboy_run(GameBoy* gb) { 
    struct timeval stop, start;
    int currentTime = 0;

    while(gb->running) {
        while(gb->cpu.cycles <= cyclesPerFrame) {

            gettimeofday(&start, NULL);
            
            uint8_t opcode = fetch_opcode(gb);
            execute_opcode(gb, opcode);

            gettimeofday(&stop, NULL);
            currentTime += (stop.tv_sec - start.tv_sec) * 1000 + stop.tv_usec - start.tv_usec;
            printf("took %lu ms\n", (stop.tv_sec - start.tv_sec) * 1000 + stop.tv_usec - start.tv_usec);
        }

        int remainingTime = FRAME_DURATION_MS - currentTime;
        usleep(remainingTime > 0 ? remainingTime*1000 : 0); 
        currentTime = 0;
        gb->cpu.cycles = 0;
    }
}
