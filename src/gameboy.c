#include "gameboy.h"
#include "cpu.h"
#include "flags.h"
#include "memory.h"
#include "instructions.h"

#include <stdio.h>

void gameboy_init(GameBoy* gb) {
    cpu_init(&gb->cpu);
    memory_init(&gb->mem);
    init_opcode_table();
}
