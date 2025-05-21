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

extern Opcode opcode_table[256];

void init_opcode_table(void);

// 0x00 - 0x0F
void nop(Memory*, CPU*);
void ld_bc_d16(Memory*, CPU*);
void ld_bc_a(Memory*, CPU*);
void inc_bc(Memory*, CPU*);
void inc_b(Memory*, CPU*);
void dec_b(Memory*, CPU*);
void ld_b_d8(Memory*, CPU*);
void rlca(Memory*, CPU*);
void ld_a16_sp(Memory*, CPU*);
void add_hl_bc(Memory*, CPU*);
void ld_a_bc(Memory*, CPU*);
void dec_bc(Memory*, CPU*);
void inc_c(Memory*, CPU*);
void dec_c(Memory*, CPU*);
void ld_c_d8(Memory*, CPU*);
void rrca(Memory*, CPU*);

// 0x10 - 0x1F
void ld_de_d16(Memory*, CPU*);
void ld_de_a(Memory*, CPU*);
void inc_de(Memory*, CPU*);
void inc_d(Memory*, CPU*);
void dec_d(Memory*, CPU*);
void ld_d_d8(Memory*, CPU*);
void rla(Memory*, CPU*);
void jr_s8(Memory*, CPU*);
void add_hl_de(Memory*, CPU*);
void ld_a_de(Memory*, CPU*);
void dec_de(Memory*, CPU*);
void inc_e(Memory*, CPU*);
void dec_e(Memory*, CPU*);
void ld_e_d8(Memory*, CPU*);
void rra(Memory*, CPU*);

// 0x20 - 0x2F
void jr_nz_s8(Memory*, CPU*);
void ld_hl_d16(Memory*, CPU*);
void ld_hli_a(Memory*, CPU*);
void inc_hl(Memory*, CPU*);
void inc_h(Memory*, CPU*);
void dec_h(Memory*, CPU*);
void ld_h_d8(Memory*, CPU*);
void daa(Memory*, CPU*);
void jr_z_s8(Memory*, CPU*);
void add_hl_hl(Memory*, CPU*);
void ld_a_hli(Memory*, CPU*);
void dec_hl(Memory*, CPU*);
void inc_l(Memory*, CPU*);
void dec_l(Memory*, CPU*);
void ld_l_d8(Memory*, CPU*);
void cpl(Memory*, CPU*);

// 0x30 - 0x3F
void jr_nc_s8(Memory*, CPU*);
void ld_sp_d16(Memory*, CPU*);
void ld_hld_a(Memory*, CPU*);
void inc_sp(Memory*, CPU*);
void inc_hlm(Memory*, CPU*);
void dec_hlm(Memory*, CPU*);
void ld_hl_d8(Memory*, CPU*);
void scf(Memory*, CPU*);
void jr_c_s8(Memory*, CPU*);
void add_hl_sp(Memory*, CPU*);
void ld_a_hld(Memory*, CPU*);
void dec_sp(Memory*, CPU*);
void inc_a(Memory*, CPU*);
void dec_a(Memory*, CPU*);
void ld_a_d8(Memory*, CPU*);
void ccf(Memory*, CPU*);

// 0x40 - 0x7F (register-to-register and memory loads)
void ld_b_b(Memory*, CPU*);
void ld_b_c(Memory*, CPU*);
void ld_b_d(Memory*, CPU*);
void ld_b_e(Memory*, CPU*);
void ld_b_h(Memory*, CPU*);
void ld_b_l(Memory*, CPU*);
void ld_b_hl(Memory*, CPU*);
void ld_b_a(Memory*, CPU*);
void ld_c_b(Memory*, CPU*);
void ld_c_c(Memory*, CPU*);
void ld_c_d(Memory*, CPU*);
void ld_c_e(Memory*, CPU*);
void ld_c_h(Memory*, CPU*);
void ld_c_l(Memory*, CPU*);
void ld_c_hl(Memory*, CPU*);
void ld_c_a(Memory*, CPU*);
void ld_d_b(Memory*, CPU*);
void ld_d_c(Memory*, CPU*);
void ld_d_d(Memory*, CPU*);
void ld_d_e(Memory*, CPU*);
void ld_d_h(Memory*, CPU*);
void ld_d_l(Memory*, CPU*);
void ld_d_hl(Memory*, CPU*);
void ld_d_a(Memory*, CPU*);
void ld_e_b(Memory*, CPU*);
void ld_e_c(Memory*, CPU*);
void ld_e_d(Memory*, CPU*);
void ld_e_e(Memory*, CPU*);
void ld_e_h(Memory*, CPU*);
void ld_e_l(Memory*, CPU*);
void ld_e_hl(Memory*, CPU*);
void ld_e_a(Memory*, CPU*);
void ld_h_b(Memory*, CPU*);
void ld_h_c(Memory*, CPU*);
void ld_h_d(Memory*, CPU*);
void ld_h_e(Memory*, CPU*);
void ld_h_h(Memory*, CPU*);
void ld_h_l(Memory*, CPU*);
void ld_h_hl(Memory*, CPU*);
void ld_h_a(Memory*, CPU*);
void ld_l_b(Memory*, CPU*);
void ld_l_c(Memory*, CPU*);
void ld_l_d(Memory*, CPU*);
void ld_l_e(Memory*, CPU*);
void ld_l_h(Memory*, CPU*);
void ld_l_l(Memory*, CPU*);
void ld_l_hl(Memory*, CPU*);
void ld_l_a(Memory*, CPU*);
void ld_hl_b(Memory*, CPU*);
void ld_hl_c(Memory*, CPU*);
void ld_hl_d(Memory*, CPU*);
void ld_hl_e(Memory*, CPU*);
void ld_hl_h(Memory*, CPU*);
void ld_hl_l(Memory*, CPU*);
void ld_hl_a(Memory*, CPU*);
void ld_a_b(Memory*, CPU*);
void ld_a_c(Memory*, CPU*);
void ld_a_d(Memory*, CPU*);
void ld_a_e(Memory*, CPU*);
void ld_a_h(Memory*, CPU*);
void ld_a_l(Memory*, CPU*);
void ld_a_hl(Memory*, CPU*);
void ld_a_a(Memory*, CPU*);

#endif