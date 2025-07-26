#include "instructionsCBList.h"
#include "flags.h"
#include "memory.h"
#include "cpu.h"

// Helper macros for register access
#define REG_B cpu->b
#define REG_C cpu->c
#define REG_D cpu->d
#define REG_E cpu->e
#define REG_H cpu->h
#define REG_L cpu->l
#define REG_A cpu->a
#define REG_HLm read_memory_byte(mem, get_hl(cpu))
#define REG_HLm_SET(val) write_memory_byte(mem, get_hl(cpu), (val))

// SLA: Shift Left Arithmetic
static uint8_t sla(uint8_t val, CPU* cpu) {
    (val & 0x80) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
    uint8_t res = val << 1;
    (res == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
    clear_flag(cpu, FLAG_N);
    clear_flag(cpu, FLAG_H);
    return res;
}
// SRA: Shift Right Arithmetic
static uint8_t sra(uint8_t val, CPU* cpu) {
    (val & 0x01) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
    uint8_t res = (val >> 1) | (val & 0x80);
    (res == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
    clear_flag(cpu, FLAG_N);
    clear_flag(cpu, FLAG_H);
    return res;
}
// SWAP: Swap upper and lower nibbles
static uint8_t swap(uint8_t val, CPU* cpu) {
    uint8_t res = (val << 4) | (val >> 4);
    (res == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
    clear_flag(cpu, FLAG_N);
    clear_flag(cpu, FLAG_H);
    clear_flag(cpu, FLAG_C);
    return res;
}
// SRL: Shift Right Logical
static uint8_t srl(uint8_t val, CPU* cpu) {
    (val & 0x01) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
    uint8_t res = val >> 1;
    (res == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
    clear_flag(cpu, FLAG_N);
    clear_flag(cpu, FLAG_H);
    return res;
}

// 0x20-0x27: SLA r
void cb_sla_b(Memory* mem, CPU* cpu) { REG_B = sla(REG_B, cpu); }
void cb_sla_c(Memory* mem, CPU* cpu) { REG_C = sla(REG_C, cpu); }
void cb_sla_d(Memory* mem, CPU* cpu) { REG_D = sla(REG_D, cpu); }
void cb_sla_e(Memory* mem, CPU* cpu) { REG_E = sla(REG_E, cpu); }
void cb_sla_h(Memory* mem, CPU* cpu) { REG_H = sla(REG_H, cpu); }
void cb_sla_l(Memory* mem, CPU* cpu) { REG_L = sla(REG_L, cpu); }
void cb_sla_hlm(Memory* mem, CPU* cpu) { uint8_t v = sla(REG_HLm, cpu); REG_HLm_SET(v); }
void cb_sla_a(Memory* mem, CPU* cpu) { REG_A = sla(REG_A, cpu); }
// 0x28-0x2F: SRA r
void cb_sra_b(Memory* mem, CPU* cpu) { REG_B = sra(REG_B, cpu); }
void cb_sra_c(Memory* mem, CPU* cpu) { REG_C = sra(REG_C, cpu); }
void cb_sra_d(Memory* mem, CPU* cpu) { REG_D = sra(REG_D, cpu); }
void cb_sra_e(Memory* mem, CPU* cpu) { REG_E = sra(REG_E, cpu); }
void cb_sra_h(Memory* mem, CPU* cpu) { REG_H = sra(REG_H, cpu); }
void cb_sra_l(Memory* mem, CPU* cpu) { REG_L = sra(REG_L, cpu); }
void cb_sra_hlm(Memory* mem, CPU* cpu) { uint8_t v = sra(REG_HLm, cpu); REG_HLm_SET(v); }
void cb_sra_a(Memory* mem, CPU* cpu) { REG_A = sra(REG_A, cpu); }
// 0x30-0x37: SWAP r
void cb_swap_b(Memory* mem, CPU* cpu) { REG_B = swap(REG_B, cpu); }
void cb_swap_c(Memory* mem, CPU* cpu) { REG_C = swap(REG_C, cpu); }
void cb_swap_d(Memory* mem, CPU* cpu) { REG_D = swap(REG_D, cpu); }
void cb_swap_e(Memory* mem, CPU* cpu) { REG_E = swap(REG_E, cpu); }
void cb_swap_h(Memory* mem, CPU* cpu) { REG_H = swap(REG_H, cpu); }
void cb_swap_l(Memory* mem, CPU* cpu) { REG_L = swap(REG_L, cpu); }
void cb_swap_hlm(Memory* mem, CPU* cpu) { uint8_t v = swap(REG_HLm, cpu); REG_HLm_SET(v); }
void cb_swap_a(Memory* mem, CPU* cpu) { REG_A = swap(REG_A, cpu); }
// 0x38-0x3F: SRL r
void cb_srl_b(Memory* mem, CPU* cpu) { REG_B = srl(REG_B, cpu); }
void cb_srl_c(Memory* mem, CPU* cpu) { REG_C = srl(REG_C, cpu); }
void cb_srl_d(Memory* mem, CPU* cpu) { REG_D = srl(REG_D, cpu); }
void cb_srl_e(Memory* mem, CPU* cpu) { REG_E = srl(REG_E, cpu); }
void cb_srl_h(Memory* mem, CPU* cpu) { REG_H = srl(REG_H, cpu); }
void cb_srl_l(Memory* mem, CPU* cpu) { REG_L = srl(REG_L, cpu); }
void cb_srl_hlm(Memory* mem, CPU* cpu) { uint8_t v = srl(REG_HLm, cpu); REG_HLm_SET(v); }
void cb_srl_a(Memory* mem, CPU* cpu) { REG_A = srl(REG_A, cpu); }
