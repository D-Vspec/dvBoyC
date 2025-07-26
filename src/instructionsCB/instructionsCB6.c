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
// SET: Set bit n in value
static uint8_t setb(uint8_t bitnum, uint8_t val) {
    return val | (1 << bitnum);
}

// 0xA0-0xA7: RES 4,r
void cb_res_4_b(Memory* mem, CPU* cpu) { REG_B = res(4, REG_B); }
void cb_res_4_c(Memory* mem, CPU* cpu) { REG_C = res(4, REG_C); }
void cb_res_4_d(Memory* mem, CPU* cpu) { REG_D = res(4, REG_D); }
void cb_res_4_e(Memory* mem, CPU* cpu) { REG_E = res(4, REG_E); }
void cb_res_4_h(Memory* mem, CPU* cpu) { REG_H = res(4, REG_H); }
void cb_res_4_l(Memory* mem, CPU* cpu) { REG_L = res(4, REG_L); }
void cb_res_4_hlm(Memory* mem, CPU* cpu) { uint8_t v = res(4, REG_HLm); REG_HLm_SET(v); }
void cb_res_4_a(Memory* mem, CPU* cpu) { REG_A = res(4, REG_A); }
// 0xA8-0xAF: RES 5,r
void cb_res_5_b(Memory* mem, CPU* cpu) { REG_B = res(5, REG_B); }
void cb_res_5_c(Memory* mem, CPU* cpu) { REG_C = res(5, REG_C); }
void cb_res_5_d(Memory* mem, CPU* cpu) { REG_D = res(5, REG_D); }
void cb_res_5_e(Memory* mem, CPU* cpu) { REG_E = res(5, REG_E); }
void cb_res_5_h(Memory* mem, CPU* cpu) { REG_H = res(5, REG_H); }
void cb_res_5_l(Memory* mem, CPU* cpu) { REG_L = res(5, REG_L); }
void cb_res_5_hlm(Memory* mem, CPU* cpu) { uint8_t v = res(5, REG_HLm); REG_HLm_SET(v); }
void cb_res_5_a(Memory* mem, CPU* cpu) { REG_A = res(5, REG_A); }
// 0xB0-0xB7: RES 6,r
void cb_res_6_b(Memory* mem, CPU* cpu) { REG_B = res(6, REG_B); }
void cb_res_6_c(Memory* mem, CPU* cpu) { REG_C = res(6, REG_C); }
void cb_res_6_d(Memory* mem, CPU* cpu) { REG_D = res(6, REG_D); }
void cb_res_6_e(Memory* mem, CPU* cpu) { REG_E = res(6, REG_E); }
void cb_res_6_h(Memory* mem, CPU* cpu) { REG_H = res(6, REG_H); }
void cb_res_6_l(Memory* mem, CPU* cpu) { REG_L = res(6, REG_L); }
void cb_res_6_hlm(Memory* mem, CPU* cpu) { uint8_t v = res(6, REG_HLm); REG_HLm_SET(v); }
void cb_res_6_a(Memory* mem, CPU* cpu) { REG_A = res(6, REG_A); }
// 0xB8-0xBF: RES 7,r
void cb_res_7_b(Memory* mem, CPU* cpu) { REG_B = res(7, REG_B); }
void cb_res_7_c(Memory* mem, CPU* cpu) { REG_C = res(7, REG_C); }
void cb_res_7_d(Memory* mem, CPU* cpu) { REG_D = res(7, REG_D); }
void cb_res_7_e(Memory* mem, CPU* cpu) { REG_E = res(7, REG_E); }
void cb_res_7_h(Memory* mem, CPU* cpu) { REG_H = res(7, REG_H); }
void cb_res_7_l(Memory* mem, CPU* cpu) { REG_L = res(7, REG_L); }
void cb_res_7_hlm(Memory* mem, CPU* cpu) { uint8_t v = res(7, REG_HLm); REG_HLm_SET(v); }
void cb_res_7_a(Memory* mem, CPU* cpu) { REG_A = res(7, REG_A); }
