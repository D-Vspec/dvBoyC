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

// 0xE0-0xE7: SET 4,r
void cb_set_4_b(Memory* mem, CPU* cpu) { REG_B = setb(4, REG_B); }
void cb_set_4_c(Memory* mem, CPU* cpu) { REG_C = setb(4, REG_C); }
void cb_set_4_d(Memory* mem, CPU* cpu) { REG_D = setb(4, REG_D); }
void cb_set_4_e(Memory* mem, CPU* cpu) { REG_E = setb(4, REG_E); }
void cb_set_4_h(Memory* mem, CPU* cpu) { REG_H = setb(4, REG_H); }
void cb_set_4_l(Memory* mem, CPU* cpu) { REG_L = setb(4, REG_L); }
void cb_set_4_hlm(Memory* mem, CPU* cpu) { uint8_t v = setb(4, REG_HLm); REG_HLm_SET(v); }
void cb_set_4_a(Memory* mem, CPU* cpu) { REG_A = setb(4, REG_A); }
// 0xE8-0xEF: SET 5,r
void cb_set_5_b(Memory* mem, CPU* cpu) { REG_B = setb(5, REG_B); }
void cb_set_5_c(Memory* mem, CPU* cpu) { REG_C = setb(5, REG_C); }
void cb_set_5_d(Memory* mem, CPU* cpu) { REG_D = setb(5, REG_D); }
void cb_set_5_e(Memory* mem, CPU* cpu) { REG_E = setb(5, REG_E); }
void cb_set_5_h(Memory* mem, CPU* cpu) { REG_H = setb(5, REG_H); }
void cb_set_5_l(Memory* mem, CPU* cpu) { REG_L = setb(5, REG_L); }
void cb_set_5_hlm(Memory* mem, CPU* cpu) { uint8_t v = setb(5, REG_HLm); REG_HLm_SET(v); }
void cb_set_5_a(Memory* mem, CPU* cpu) { REG_A = setb(5, REG_A); }
// 0xF0-0xF7: SET 6,r
void cb_set_6_b(Memory* mem, CPU* cpu) { REG_B = setb(6, REG_B); }
void cb_set_6_c(Memory* mem, CPU* cpu) { REG_C = setb(6, REG_C); }
void cb_set_6_d(Memory* mem, CPU* cpu) { REG_D = setb(6, REG_D); }
void cb_set_6_e(Memory* mem, CPU* cpu) { REG_E = setb(6, REG_E); }
void cb_set_6_h(Memory* mem, CPU* cpu) { REG_H = setb(6, REG_H); }
void cb_set_6_l(Memory* mem, CPU* cpu) { REG_L = setb(6, REG_L); }
void cb_set_6_hlm(Memory* mem, CPU* cpu) { uint8_t v = setb(6, REG_HLm); REG_HLm_SET(v); }
void cb_set_6_a(Memory* mem, CPU* cpu) { REG_A = setb(6, REG_A); }
// 0xF8-0xFF: SET 7,r
void cb_set_7_b(Memory* mem, CPU* cpu) { REG_B = setb(7, REG_B); }
void cb_set_7_c(Memory* mem, CPU* cpu) { REG_C = setb(7, REG_C); }
void cb_set_7_d(Memory* mem, CPU* cpu) { REG_D = setb(7, REG_D); }
void cb_set_7_e(Memory* mem, CPU* cpu) { REG_E = setb(7, REG_E); }
void cb_set_7_h(Memory* mem, CPU* cpu) { REG_H = setb(7, REG_H); }
void cb_set_7_l(Memory* mem, CPU* cpu) { REG_L = setb(7, REG_L); }
void cb_set_7_hlm(Memory* mem, CPU* cpu) { uint8_t v = setb(7, REG_HLm); REG_HLm_SET(v); }
void cb_set_7_a(Memory* mem, CPU* cpu) { REG_A = setb(7, REG_A); }
