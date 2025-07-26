#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "cpu.h"
#include "memory.h"

typedef void (*InstructionHandler)(Memory* mem, CPU* cpu);

typedef struct {
    InstructionHandler handler;
    uint8_t bytes;
    uint8_t cycles;
    const char* mnemonic;
} Opcode;

extern Opcode regular_opcode_table[256];
extern Opcode cb_opcode_table[256];

void init_regular_opcode_table(void);
void init_cb_opcode_table(void);

#endif