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

// Helper for RLC
static uint8_t rlc(uint8_t val, CPU* cpu) {
    uint8_t res = (val << 1) | (val >> 7);
    (res == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
    clear_flag(cpu, FLAG_N);
    clear_flag(cpu, FLAG_H);
    (val & 0x80) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
    return res;
}
// Helper for RRC
static uint8_t rrc(uint8_t val, CPU* cpu) {
    uint8_t res = (val >> 1) | ((val & 0x01) << 7);
    (res == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
    clear_flag(cpu, FLAG_N);
    clear_flag(cpu, FLAG_H);
    (val & 0x01) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
    return res;
}
// Helper for RL
static uint8_t rl(uint8_t val, CPU* cpu) {
    uint8_t old_carry = (cpu->f & FLAG_C) ? 1 : 0;
    uint8_t new_carry = (val & 0x80) >> 7;
    uint8_t res = (val << 1) | old_carry;
    (res == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
    clear_flag(cpu, FLAG_N);
    clear_flag(cpu, FLAG_H);
    new_carry ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
    return res;
}
// Helper for RR
static uint8_t rr(uint8_t val, CPU* cpu) {
    uint8_t old_carry = (cpu->f & FLAG_C) ? 1 : 0;
    uint8_t new_carry = val & 0x01;
    uint8_t res = (old_carry << 7) | (val >> 1);
    (res == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
    clear_flag(cpu, FLAG_N);
    clear_flag(cpu, FLAG_H);
    new_carry ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
    return res;
}

// 0x00-0x07: RLC r
void cb_rlc_b(Memory* mem, CPU* cpu) { REG_B = rlc(REG_B, cpu); }
void cb_rlc_c(Memory* mem, CPU* cpu) { REG_C = rlc(REG_C, cpu); }
void cb_rlc_d(Memory* mem, CPU* cpu) { REG_D = rlc(REG_D, cpu); }
void cb_rlc_e(Memory* mem, CPU* cpu) { REG_E = rlc(REG_E, cpu); }
void cb_rlc_h(Memory* mem, CPU* cpu) { REG_H = rlc(REG_H, cpu); }
void cb_rlc_l(Memory* mem, CPU* cpu) { REG_L = rlc(REG_L, cpu); }
void cb_rlc_hlm(Memory* mem, CPU* cpu) { uint8_t v = rlc(REG_HLm, cpu); REG_HLm_SET(v); }
void cb_rlc_a(Memory* mem, CPU* cpu) { REG_A = rlc(REG_A, cpu); }
// 0x08-0x0F: RRC r
void cb_rrc_b(Memory* mem, CPU* cpu) { REG_B = rrc(REG_B, cpu); }
void cb_rrc_c(Memory* mem, CPU* cpu) { REG_C = rrc(REG_C, cpu); }
void cb_rrc_d(Memory* mem, CPU* cpu) { REG_D = rrc(REG_D, cpu); }
void cb_rrc_e(Memory* mem, CPU* cpu) { REG_E = rrc(REG_E, cpu); }
void cb_rrc_h(Memory* mem, CPU* cpu) { REG_H = rrc(REG_H, cpu); }
void cb_rrc_l(Memory* mem, CPU* cpu) { REG_L = rrc(REG_L, cpu); }
void cb_rrc_hlm(Memory* mem, CPU* cpu) { uint8_t v = rrc(REG_HLm, cpu); REG_HLm_SET(v); }
void cb_rrc_a(Memory* mem, CPU* cpu) { REG_A = rrc(REG_A, cpu); }
// 0x10-0x17: RL r
void cb_rl_b(Memory* mem, CPU* cpu) { REG_B = rl(REG_B, cpu); }
void cb_rl_c(Memory* mem, CPU* cpu) { REG_C = rl(REG_C, cpu); }
void cb_rl_d(Memory* mem, CPU* cpu) { REG_D = rl(REG_D, cpu); }
void cb_rl_e(Memory* mem, CPU* cpu) { REG_E = rl(REG_E, cpu); }
void cb_rl_h(Memory* mem, CPU* cpu) { REG_H = rl(REG_H, cpu); }
void cb_rl_l(Memory* mem, CPU* cpu) { REG_L = rl(REG_L, cpu); }
void cb_rl_hlm(Memory* mem, CPU* cpu) { uint8_t v = rl(REG_HLm, cpu); REG_HLm_SET(v); }
void cb_rl_a(Memory* mem, CPU* cpu) { REG_A = rl(REG_A, cpu); }
// 0x18-0x1F: RR r
void cb_rr_b(Memory* mem, CPU* cpu) { REG_B = rr(REG_B, cpu); }
void cb_rr_c(Memory* mem, CPU* cpu) { REG_C = rr(REG_C, cpu); }
void cb_rr_d(Memory* mem, CPU* cpu) { REG_D = rr(REG_D, cpu); }
void cb_rr_e(Memory* mem, CPU* cpu) { REG_E = rr(REG_E, cpu); }
void cb_rr_h(Memory* mem, CPU* cpu) { REG_H = rr(REG_H, cpu); }
void cb_rr_l(Memory* mem, CPU* cpu) { REG_L = rr(REG_L, cpu); }
void cb_rr_hlm(Memory* mem, CPU* cpu) { uint8_t v = rr(REG_HLm, cpu); REG_HLm_SET(v); }
void cb_rr_a(Memory* mem, CPU* cpu) { REG_A = rr(REG_A, cpu); }

