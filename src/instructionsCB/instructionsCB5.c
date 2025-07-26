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

// RES: Reset bit n in value
static uint8_t res(uint8_t bitnum, uint8_t val) {
    return val & ~(1 << bitnum);
}

// 0x80-0x87: RES 0,r
void cb_res_0_b(Memory* mem, CPU* cpu) { REG_B = res(0, REG_B); }
void cb_res_0_c(Memory* mem, CPU* cpu) { REG_C = res(0, REG_C); }
void cb_res_0_d(Memory* mem, CPU* cpu) { REG_D = res(0, REG_D); }
void cb_res_0_e(Memory* mem, CPU* cpu) { REG_E = res(0, REG_E); }
void cb_res_0_h(Memory* mem, CPU* cpu) { REG_H = res(0, REG_H); }
void cb_res_0_l(Memory* mem, CPU* cpu) { REG_L = res(0, REG_L); }
void cb_res_0_hlm(Memory* mem, CPU* cpu) { uint8_t v = res(0, REG_HLm); REG_HLm_SET(v); }
void cb_res_0_a(Memory* mem, CPU* cpu) { REG_A = res(0, REG_A); }
// 0x88-0x8F: RES 1,r
void cb_res_1_b(Memory* mem, CPU* cpu) { REG_B = res(1, REG_B); }
void cb_res_1_c(Memory* mem, CPU* cpu) { REG_C = res(1, REG_C); }
void cb_res_1_d(Memory* mem, CPU* cpu) { REG_D = res(1, REG_D); }
void cb_res_1_e(Memory* mem, CPU* cpu) { REG_E = res(1, REG_E); }
void cb_res_1_h(Memory* mem, CPU* cpu) { REG_H = res(1, REG_H); }
void cb_res_1_l(Memory* mem, CPU* cpu) { REG_L = res(1, REG_L); }
void cb_res_1_hlm(Memory* mem, CPU* cpu) { uint8_t v = res(1, REG_HLm); REG_HLm_SET(v); }
void cb_res_1_a(Memory* mem, CPU* cpu) { REG_A = res(1, REG_A); }
// 0x90-0x97: RES 2,r
void cb_res_2_b(Memory* mem, CPU* cpu) { REG_B = res(2, REG_B); }
void cb_res_2_c(Memory* mem, CPU* cpu) { REG_C = res(2, REG_C); }
void cb_res_2_d(Memory* mem, CPU* cpu) { REG_D = res(2, REG_D); }
void cb_res_2_e(Memory* mem, CPU* cpu) { REG_E = res(2, REG_E); }
void cb_res_2_h(Memory* mem, CPU* cpu) { REG_H = res(2, REG_H); }
void cb_res_2_l(Memory* mem, CPU* cpu) { REG_L = res(2, REG_L); }
void cb_res_2_hlm(Memory* mem, CPU* cpu) { uint8_t v = res(2, REG_HLm); REG_HLm_SET(v); }
void cb_res_2_a(Memory* mem, CPU* cpu) { REG_A = res(2, REG_A); }
// 0x98-0x9F: RES 3,r
void cb_res_3_b(Memory* mem, CPU* cpu) { REG_B = res(3, REG_B); }
void cb_res_3_c(Memory* mem, CPU* cpu) { REG_C = res(3, REG_C); }
void cb_res_3_d(Memory* mem, CPU* cpu) { REG_D = res(3, REG_D); }
void cb_res_3_e(Memory* mem, CPU* cpu) { REG_E = res(3, REG_E); }
void cb_res_3_h(Memory* mem, CPU* cpu) { REG_H = res(3, REG_H); }
void cb_res_3_l(Memory* mem, CPU* cpu) { REG_L = res(3, REG_L); }
void cb_res_3_hlm(Memory* mem, CPU* cpu) { uint8_t v = res(3, REG_HLm); REG_HLm_SET(v); }
void cb_res_3_a(Memory* mem, CPU* cpu) { REG_A = res(3, REG_A); }
