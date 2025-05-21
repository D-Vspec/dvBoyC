#ifndef GAMEBOY_H
#define GAMEBOY_H

#include "cpu.h"
#include "flags.h"
#include "memory.h"
#include "instructions.h"

typedef struct {
    CPU cpu;
    Memory mem;

    uint8_t running;
} GameBoy;

void gameboy_init(GameBoy* gb);
void gameboy_run(GameBoy* gb);

#endif