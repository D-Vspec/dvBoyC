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

// 0x40-0x47: BIT 0,r
void cb_bit_0_b(Memory* mem, CPU* cpu) { bit(0, REG_B, cpu); }
void cb_bit_0_c(Memory* mem, CPU* cpu) { bit(0, REG_C, cpu); }
void cb_bit_0_d(Memory* mem, CPU* cpu) { bit(0, REG_D, cpu); }
void cb_bit_0_e(Memory* mem, CPU* cpu) { bit(0, REG_E, cpu); }
void cb_bit_0_h(Memory* mem, CPU* cpu) { bit(0, REG_H, cpu); }
void cb_bit_0_l(Memory* mem, CPU* cpu) { bit(0, REG_L, cpu); }
void cb_bit_0_hlm(Memory* mem, CPU* cpu) { bit(0, REG_HLm, cpu); }
void cb_bit_0_a(Memory* mem, CPU* cpu) { bit(0, REG_A, cpu); }
// 0x48-0x4F: BIT 1,r
void cb_bit_1_b(Memory* mem, CPU* cpu) { bit(1, REG_B, cpu); }
void cb_bit_1_c(Memory* mem, CPU* cpu) { bit(1, REG_C, cpu); }
void cb_bit_1_d(Memory* mem, CPU* cpu) { bit(1, REG_D, cpu); }
void cb_bit_1_e(Memory* mem, CPU* cpu) { bit(1, REG_E, cpu); }
void cb_bit_1_h(Memory* mem, CPU* cpu) { bit(1, REG_H, cpu); }
void cb_bit_1_l(Memory* mem, CPU* cpu) { bit(1, REG_L, cpu); }
void cb_bit_1_hlm(Memory* mem, CPU* cpu) { bit(1, REG_HLm, cpu); }
void cb_bit_1_a(Memory* mem, CPU* cpu) { bit(1, REG_A, cpu); }
// 0x50-0x57: BIT 2,r
void cb_bit_2_b(Memory* mem, CPU* cpu) { bit(2, REG_B, cpu); }
void cb_bit_2_c(Memory* mem, CPU* cpu) { bit(2, REG_C, cpu); }
void cb_bit_2_d(Memory* mem, CPU* cpu) { bit(2, REG_D, cpu); }
void cb_bit_2_e(Memory* mem, CPU* cpu) { bit(2, REG_E, cpu); }
void cb_bit_2_h(Memory* mem, CPU* cpu) { bit(2, REG_H, cpu); }
void cb_bit_2_l(Memory* mem, CPU* cpu) { bit(2, REG_L, cpu); }
void cb_bit_2_hlm(Memory* mem, CPU* cpu) { bit(2, REG_HLm, cpu); }
void cb_bit_2_a(Memory* mem, CPU* cpu) { bit(2, REG_A, cpu); }
// 0x58-0x5F: BIT 3,r
void cb_bit_3_b(Memory* mem, CPU* cpu) { bit(3, REG_B, cpu); }
void cb_bit_3_c(Memory* mem, CPU* cpu) { bit(3, REG_C, cpu); }
void cb_bit_3_d(Memory* mem, CPU* cpu) { bit(3, REG_D, cpu); }
void cb_bit_3_e(Memory* mem, CPU* cpu) { bit(3, REG_E, cpu); }
void cb_bit_3_h(Memory* mem, CPU* cpu) { bit(3, REG_H, cpu); }
void cb_bit_3_l(Memory* mem, CPU* cpu) { bit(3, REG_L, cpu); }
void cb_bit_3_hlm(Memory* mem, CPU* cpu) { bit(3, REG_HLm, cpu); }
void cb_bit_3_a(Memory* mem, CPU* cpu) { bit(3, REG_A, cpu); }
