#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "cpu.h"
#include "memory.h"

// Define function pointer type for instruction handlers
typedef void (*InstructionHandler)(Memory* mem, CPU* cpu);

// Define opcode structure
typedef struct {
    InstructionHandler handler;  // Function pointer to instruction handler
    uint8_t bytes;              // Instruction length in bytes
    uint8_t cycles;             // Base cycles for instruction
    const char* mnemonic;       // Human-readable name
} Opcode;

// Declare the opcode table
extern Opcode opcode_table[256];

// Initialize the opcode table
void init_opcode_table(void);

// Opcode handler functions
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

#endif /* INSTRUCTIONS_H */
