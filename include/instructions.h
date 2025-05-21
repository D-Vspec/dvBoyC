#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "cpu.h"
#include "memory.h"

typedef void (*InstructionHandler)(Memory* mem, CPU* cpu);

// Define opcode structure
typedef struct {
    InstructionHandler handler;  // Function pointer to instruction handler
    uint8_t bytes;              // Instruction length in bytes
    uint8_t cycles;             // Base cycles for instruction
    const char* mnemonic;       // Human-readable name
} Opcode;

extern Opcode opcode_table[256];

void init_opcode_table(void);

void nop(Memory* mem, CPU* cpu);
void ld_bc_d16(Memory* mem, CPU* cpu);
void ld_bc_a(Memory* mem, CPU* cpu);
void inc_bc(Memory* mem, CPU* cpu);
void inc_b(Memory* mem, CPU* cpu);
void dec_b(Memory* mem, CPU* cpu);
void ld_b_d8(Memory* mem, CPU* cpu);
void rlca(Memory* mem, CPU* cpu);
void ld_a16_sp(Memory* mem, CPU* cpu);
void add_hl_bc(Memory* mem, CPU* cpu);
void ld_a_bc(Memory* mem, CPU* cpu);
void dec_bc(Memory* mem, CPU* cpu);
void inc_c(Memory* mem, CPU* cpu);
void dec_c(Memory* mem, CPU* cpu);
void ld_c_d8(Memory* mem, CPU* cpu);
void rrca(Memory* mem, CPU* cpu);

#endif 
