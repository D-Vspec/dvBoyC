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

// BIT: Test bit n in value
static void bit(uint8_t bitnum, uint8_t val, CPU* cpu) {
    (val & (1 << bitnum)) ? clear_flag(cpu, FLAG_Z) : set_flag(cpu, FLAG_Z);
    clear_flag(cpu, FLAG_N);
    set_flag(cpu, FLAG_H);
}

// 0x60-0x67: BIT 4,r
void cb_bit_4_b(Memory* mem, CPU* cpu) { bit(4, REG_B, cpu); }
void cb_bit_4_c(Memory* mem, CPU* cpu) { bit(4, REG_C, cpu); }
void cb_bit_4_d(Memory* mem, CPU* cpu) { bit(4, REG_D, cpu); }
void cb_bit_4_e(Memory* mem, CPU* cpu) { bit(4, REG_E, cpu); }
void cb_bit_4_h(Memory* mem, CPU* cpu) { bit(4, REG_H, cpu); }
void cb_bit_4_l(Memory* mem, CPU* cpu) { bit(4, REG_L, cpu); }
void cb_bit_4_hlm(Memory* mem, CPU* cpu) { bit(4, REG_HLm, cpu); }
void cb_bit_4_a(Memory* mem, CPU* cpu) { bit(4, REG_A, cpu); }
// 0x68-0x6F: BIT 5,r
void cb_bit_5_b(Memory* mem, CPU* cpu) { bit(5, REG_B, cpu); }
void cb_bit_5_c(Memory* mem, CPU* cpu) { bit(5, REG_C, cpu); }
void cb_bit_5_d(Memory* mem, CPU* cpu) { bit(5, REG_D, cpu); }
void cb_bit_5_e(Memory* mem, CPU* cpu) { bit(5, REG_E, cpu); }
void cb_bit_5_h(Memory* mem, CPU* cpu) { bit(5, REG_H, cpu); }
void cb_bit_5_l(Memory* mem, CPU* cpu) { bit(5, REG_L, cpu); }
void cb_bit_5_hlm(Memory* mem, CPU* cpu) { bit(5, REG_HLm, cpu); }
void cb_bit_5_a(Memory* mem, CPU* cpu) { bit(5, REG_A, cpu); }
// 0x70-0x77: BIT 6,r
void cb_bit_6_b(Memory* mem, CPU* cpu) { bit(6, REG_B, cpu); }
void cb_bit_6_c(Memory* mem, CPU* cpu) { bit(6, REG_C, cpu); }
void cb_bit_6_d(Memory* mem, CPU* cpu) { bit(6, REG_D, cpu); }
void cb_bit_6_e(Memory* mem, CPU* cpu) { bit(6, REG_E, cpu); }
void cb_bit_6_h(Memory* mem, CPU* cpu) { bit(6, REG_H, cpu); }
void cb_bit_6_l(Memory* mem, CPU* cpu) { bit(6, REG_L, cpu); }
void cb_bit_6_hlm(Memory* mem, CPU* cpu) { bit(6, REG_HLm, cpu); }
void cb_bit_6_a(Memory* mem, CPU* cpu) { bit(6, REG_A, cpu); }
// 0x78-0x7F: BIT 7,r
void cb_bit_7_b(Memory* mem, CPU* cpu) { bit(7, REG_B, cpu); }
void cb_bit_7_c(Memory* mem, CPU* cpu) { bit(7, REG_C, cpu); }
void cb_bit_7_d(Memory* mem, CPU* cpu) { bit(7, REG_D, cpu); }
void cb_bit_7_e(Memory* mem, CPU* cpu) { bit(7, REG_E, cpu); }
void cb_bit_7_h(Memory* mem, CPU* cpu) { bit(7, REG_H, cpu); }
void cb_bit_7_l(Memory* mem, CPU* cpu) { bit(7, REG_L, cpu); }
void cb_bit_7_hlm(Memory* mem, CPU* cpu) { bit(7, REG_HLm, cpu); }
void cb_bit_7_a(Memory* mem, CPU* cpu) { bit(7, REG_A, cpu); }
