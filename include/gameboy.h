#ifndef GAMEBOY_H
#define GAMEBOY_H

#include "cpu.h"
#include "flags.h"
#include "memory.h"
#include "instructions.h"

typedef struct {
    CPU cpu;
    Memory mem;
} GameBoy;

void gameboy_init(GameBoy* gb);

#endif