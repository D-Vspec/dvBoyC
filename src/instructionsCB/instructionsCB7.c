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

// SET: Set bit n in value
static uint8_t setb(uint8_t bitnum, uint8_t val) {
    return val | (1 << bitnum);
}

// 0xC0-0xC7: SET 0,r
void cb_set_0_b(Memory* mem, CPU* cpu) { REG_B = setb(0, REG_B); }
void cb_set_0_c(Memory* mem, CPU* cpu) { REG_C = setb(0, REG_C); }
void cb_set_0_d(Memory* mem, CPU* cpu) { REG_D = setb(0, REG_D); }
void cb_set_0_e(Memory* mem, CPU* cpu) { REG_E = setb(0, REG_E); }
void cb_set_0_h(Memory* mem, CPU* cpu) { REG_H = setb(0, REG_H); }
void cb_set_0_l(Memory* mem, CPU* cpu) { REG_L = setb(0, REG_L); }
void cb_set_0_hlm(Memory* mem, CPU* cpu) { uint8_t v = setb(0, REG_HLm); REG_HLm_SET(v); }
void cb_set_0_a(Memory* mem, CPU* cpu) { REG_A = setb(0, REG_A); }
// 0xC8-0xCF: SET 1,r
void cb_set_1_b(Memory* mem, CPU* cpu) { REG_B = setb(1, REG_B); }
void cb_set_1_c(Memory* mem, CPU* cpu) { REG_C = setb(1, REG_C); }
void cb_set_1_d(Memory* mem, CPU* cpu) { REG_D = setb(1, REG_D); }
void cb_set_1_e(Memory* mem, CPU* cpu) { REG_E = setb(1, REG_E); }
void cb_set_1_h(Memory* mem, CPU* cpu) { REG_H = setb(1, REG_H); }
void cb_set_1_l(Memory* mem, CPU* cpu) { REG_L = setb(1, REG_L); }
void cb_set_1_hlm(Memory* mem, CPU* cpu) { uint8_t v = setb(1, REG_HLm); REG_HLm_SET(v); }
void cb_set_1_a(Memory* mem, CPU* cpu) { REG_A = setb(1, REG_A); }
// 0xD0-0xD7: SET 2,r
void cb_set_2_b(Memory* mem, CPU* cpu) { REG_B = setb(2, REG_B); }
void cb_set_2_c(Memory* mem, CPU* cpu) { REG_C = setb(2, REG_C); }
void cb_set_2_d(Memory* mem, CPU* cpu) { REG_D = setb(2, REG_D); }
void cb_set_2_e(Memory* mem, CPU* cpu) { REG_E = setb(2, REG_E); }
void cb_set_2_h(Memory* mem, CPU* cpu) { REG_H = setb(2, REG_H); }
void cb_set_2_l(Memory* mem, CPU* cpu) { REG_L = setb(2, REG_L); }
void cb_set_2_hlm(Memory* mem, CPU* cpu) { uint8_t v = setb(2, REG_HLm); REG_HLm_SET(v); }
void cb_set_2_a(Memory* mem, CPU* cpu) { REG_A = setb(2, REG_A); }
// 0xD8-0xDF: SET 3,r
void cb_set_3_b(Memory* mem, CPU* cpu) { REG_B = setb(3, REG_B); }
void cb_set_3_c(Memory* mem, CPU* cpu) { REG_C = setb(3, REG_C); }
void cb_set_3_d(Memory* mem, CPU* cpu) { REG_D = setb(3, REG_D); }
void cb_set_3_e(Memory* mem, CPU* cpu) { REG_E = setb(3, REG_E); }
void cb_set_3_h(Memory* mem, CPU* cpu) { REG_H = setb(3, REG_H); }
void cb_set_3_l(Memory* mem, CPU* cpu) { REG_L = setb(3, REG_L); }
void cb_set_3_hlm(Memory* mem, CPU* cpu) { uint8_t v = setb(3, REG_HLm); REG_HLm_SET(v); }
void cb_set_3_a(Memory* mem, CPU* cpu) { REG_A = setb(3, REG_A); }
