#include "instructions.h"
#include "flags.h"
#include "cpu.h"
#include "memory.h"

// Register-to-register load instructions (0x40-0x7F)

// 0x80: ADD A,B
void add_a_b(Memory* mem, CPU* cpu) {
    uint8_t value = cpu->b;
    uint16_t result = cpu->a + value;
    clear_flag(cpu, FLAG_N);
    ( ((cpu->a & 0xF) + (value & 0xF)) > 0xF ) ? set_flag(cpu, FLAG_H) : clear_flag(cpu, FLAG_H);
    (result > 0xFF) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
    cpu->a = (uint8_t)result;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
}

// 0x81: ADD A,C
void add_a_c(Memory* mem, CPU* cpu) {
    uint8_t value = cpu->c;
    uint16_t result = cpu->a + value;
    clear_flag(cpu, FLAG_N);
    ( ((cpu->a & 0xF) + (value & 0xF)) > 0xF ) ? set_flag(cpu, FLAG_H) : clear_flag(cpu, FLAG_H);
    (result > 0xFF) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
    cpu->a = (uint8_t)result;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
}

// 0x82: ADD A,D
void add_a_d(Memory* mem, CPU* cpu) {
    uint8_t value = cpu->d;
    uint16_t result = cpu->a + value;
    clear_flag(cpu, FLAG_N);
    ( ((cpu->a & 0xF) + (value & 0xF)) > 0xF ) ? set_flag(cpu, FLAG_H) : clear_flag(cpu, FLAG_H);
    (result > 0xFF) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
    cpu->a = (uint8_t)result;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
}

// 0x83: ADD A,E
void add_a_e(Memory* mem, CPU* cpu) {
    uint8_t value = cpu->e;
    uint16_t result = cpu->a + value;
    clear_flag(cpu, FLAG_N);
    ( ((cpu->a & 0xF) + (value & 0xF)) > 0xF ) ? set_flag(cpu, FLAG_H) : clear_flag(cpu, FLAG_H);
    (result > 0xFF) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
    cpu->a = (uint8_t)result;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
}

// 0x84: ADD A,H
void add_a_h(Memory* mem, CPU* cpu) {
    uint8_t value = cpu->h;
    uint16_t result = cpu->a + value;
    clear_flag(cpu, FLAG_N);
    ( ((cpu->a & 0xF) + (value & 0xF)) > 0xF ) ? set_flag(cpu, FLAG_H) : clear_flag(cpu, FLAG_H);
    (result > 0xFF) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
    cpu->a = (uint8_t)result;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
}

// 0x85: ADD A,L
void add_a_l(Memory* mem, CPU* cpu) {
    uint8_t value = cpu->l;
    uint16_t result = cpu->a + value;
    clear_flag(cpu, FLAG_N);
    ( ((cpu->a & 0xF) + (value & 0xF)) > 0xF ) ? set_flag(cpu, FLAG_H) : clear_flag(cpu, FLAG_H);
    (result > 0xFF) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
    cpu->a = (uint8_t)result;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
}

// 0x86: ADD A,(HL)
void add_a_hl(Memory* mem, CPU* cpu) {
    uint8_t value = read_memory_byte(mem, get_hl(cpu));
    uint16_t result = cpu->a + value;
    clear_flag(cpu, FLAG_N);
    ( ((cpu->a & 0xF) + (value & 0xF)) > 0xF ) ? set_flag(cpu, FLAG_H) : clear_flag(cpu, FLAG_H);
    (result > 0xFF) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
    cpu->a = (uint8_t)result;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
}

// 0x87: ADD A,A
void add_a_a(Memory* mem, CPU* cpu) {
    uint8_t value = cpu->a;
    uint16_t result = cpu->a + value;
    clear_flag(cpu, FLAG_N);
    ( ((cpu->a & 0xF) + (value & 0xF)) > 0xF ) ? set_flag(cpu, FLAG_H) : clear_flag(cpu, FLAG_H);
    (result > 0xFF) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
    cpu->a = (uint8_t)result;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
}

// 0x88: ADC A,B
void adc_a_b(Memory* mem, CPU* cpu) {
    uint8_t value = cpu->b;
    uint8_t carry = (cpu->f & FLAG_C) ? 1 : 0;
    uint16_t result = cpu->a + value + carry;
    clear_flag(cpu, FLAG_N);
    ( ((cpu->a & 0xF) + (value & 0xF) + carry) > 0xF ) ? set_flag(cpu, FLAG_H) : clear_flag(cpu, FLAG_H);
    (result > 0xFF) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
    cpu->a = (uint8_t)result;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
}

// 0x89: ADC A,C
void adc_a_c(Memory* mem, CPU* cpu) {
    uint8_t value = cpu->c;
    uint8_t carry = (cpu->f & FLAG_C) ? 1 : 0;
    uint16_t result = cpu->a + value + carry;
    clear_flag(cpu, FLAG_N);
    ( ((cpu->a & 0xF) + (value & 0xF) + carry) > 0xF ) ? set_flag(cpu, FLAG_H) : clear_flag(cpu, FLAG_H);
    (result > 0xFF) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
    cpu->a = (uint8_t)result;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
}

// 0x8A: ADC A,D
void adc_a_d(Memory* mem, CPU* cpu) {
    uint8_t value = cpu->d;
    uint8_t carry = (cpu->f & FLAG_C) ? 1 : 0;
    uint16_t result = cpu->a + value + carry;
    clear_flag(cpu, FLAG_N);
    ( ((cpu->a & 0xF) + (value & 0xF) + carry) > 0xF ) ? set_flag(cpu, FLAG_H) : clear_flag(cpu, FLAG_H);
    (result > 0xFF) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
    cpu->a = (uint8_t)result;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
}

// 0x8B: ADC A,E
void adc_a_e(Memory* mem, CPU* cpu) {
    uint8_t value = cpu->e;
    uint8_t carry = (cpu->f & FLAG_C) ? 1 : 0;
    uint16_t result = cpu->a + value + carry;
    clear_flag(cpu, FLAG_N);
    ( ((cpu->a & 0xF) + (value & 0xF) + carry) > 0xF ) ? set_flag(cpu, FLAG_H) : clear_flag(cpu, FLAG_H);
    (result > 0xFF) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
    cpu->a = (uint8_t)result;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
}

// 0x8C: ADC A,H
void adc_a_h(Memory* mem, CPU* cpu) {
    uint8_t value = cpu->h;
    uint8_t carry = (cpu->f & FLAG_C) ? 1 : 0;
    uint16_t result = cpu->a + value + carry;
    clear_flag(cpu, FLAG_N);
    ( ((cpu->a & 0xF) + (value & 0xF) + carry) > 0xF ) ? set_flag(cpu, FLAG_H) : clear_flag(cpu, FLAG_H);
    (result > 0xFF) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
    cpu->a = (uint8_t)result;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
}

// 0x8D: ADC A,L
void adc_a_l(Memory* mem, CPU* cpu) {
    uint8_t value = cpu->l;
    uint8_t carry = (cpu->f & FLAG_C) ? 1 : 0;
    uint16_t result = cpu->a + value + carry;
    clear_flag(cpu, FLAG_N);
    ( ((cpu->a & 0xF) + (value & 0xF) + carry) > 0xF ) ? set_flag(cpu, FLAG_H) : clear_flag(cpu, FLAG_H);
    (result > 0xFF) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
    cpu->a = (uint8_t)result;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
}

// 0x8E: ADC A,(HL)
void adc_a_hl(Memory* mem, CPU* cpu) {
    uint8_t value = read_memory_byte(mem, get_hl(cpu));
    uint8_t carry = (cpu->f & FLAG_C) ? 1 : 0;
    uint16_t result = cpu->a + value + carry;
    clear_flag(cpu, FLAG_N);
    ( ((cpu->a & 0xF) + (value & 0xF) + carry) > 0xF ) ? set_flag(cpu, FLAG_H) : clear_flag(cpu, FLAG_H);
    (result > 0xFF) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
    cpu->a = (uint8_t)result;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
}

// 0x8F: ADC A,A
void adc_a_a(Memory* mem, CPU* cpu) {
    uint8_t value = cpu->a;
    uint8_t carry = (cpu->f & FLAG_C) ? 1 : 0;
    uint16_t result = cpu->a + value + carry;
    clear_flag(cpu, FLAG_N);
    (((cpu->a & 0xF) + (value & 0xF) + carry) > 0xF) ? set_flag(cpu, FLAG_H) : clear_flag(cpu, FLAG_H);
    (result > 0xFF) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
    cpu->a = (uint8_t)result;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
}

// 0x90: SUB B
void sub_b(Memory* mem, CPU* cpu) {
    uint8_t value = cpu->b;
    uint8_t result = cpu->a - value;
    set_flag(cpu, FLAG_N);
    ((value & 0xF) > (cpu->a & 0xF)) ? set_flag(cpu, FLAG_H) : clear_flag(cpu, FLAG_H);
    (value > cpu->a) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
    cpu->a = result;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
}

// 0x91: SUB C
void sub_c(Memory* mem, CPU* cpu) {
    uint8_t value = cpu->c;
    uint8_t result = cpu->a - value;
    set_flag(cpu, FLAG_N);
    ((value & 0xF) > (cpu->a & 0xF)) ? set_flag(cpu, FLAG_H) : clear_flag(cpu, FLAG_H);
    (value > cpu->a) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
    cpu->a = result;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
}

// 0x92: SUB D
void sub_d(Memory* mem, CPU* cpu) {
    uint8_t value = cpu->d;
    uint8_t result = cpu->a - value;
    set_flag(cpu, FLAG_N);
    ((value & 0xF) > (cpu->a & 0xF)) ? set_flag(cpu, FLAG_H) : clear_flag(cpu, FLAG_H);
    (value > cpu->a) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
    cpu->a = result;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
}

// 0x93: SUB E
void sub_e(Memory* mem, CPU* cpu) {
    uint8_t value = cpu->e;
    uint8_t result = cpu->a - value;
    set_flag(cpu, FLAG_N);
    ((value & 0xF) > (cpu->a & 0xF)) ? set_flag(cpu, FLAG_H) : clear_flag(cpu, FLAG_H);
    (value > cpu->a) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
    cpu->a = result;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
}

// 0x94: SUB H
void sub_h(Memory* mem, CPU* cpu) {
    uint8_t value = cpu->h;
    uint8_t result = cpu->a - value;
    set_flag(cpu, FLAG_N);
    ((value & 0xF) > (cpu->a & 0xF)) ? set_flag(cpu, FLAG_H) : clear_flag(cpu, FLAG_H);
    (value > cpu->a) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
    cpu->a = result;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
}

// 0x95: SUB L
void sub_l(Memory* mem, CPU* cpu) {
    uint8_t value = cpu->l;
    uint8_t result = cpu->a - value;
    set_flag(cpu, FLAG_N);
    ((value & 0xF) > (cpu->a & 0xF)) ? set_flag(cpu, FLAG_H) : clear_flag(cpu, FLAG_H);
    (value > cpu->a) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
    cpu->a = result;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
}

// 0x96: SUB (HL)
void sub_hl(Memory* mem, CPU* cpu) {
    uint8_t value = read_memory_byte(mem, get_hl(cpu));
    uint8_t result = cpu->a - value;
    set_flag(cpu, FLAG_N);
    ((value & 0xF) > (cpu->a & 0xF)) ? set_flag(cpu, FLAG_H) : clear_flag(cpu, FLAG_H);
    (value > cpu->a) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
    cpu->a = result;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
}

// 0x97: SUB A
void sub_a(Memory* mem, CPU* cpu) {
    uint8_t value = cpu->a;
    uint8_t result = cpu->a - value;
    set_flag(cpu, FLAG_N);
    ((value & 0xF) > (cpu->a & 0xF)) ? set_flag(cpu, FLAG_H) : clear_flag(cpu, FLAG_H);
    (value > cpu->a) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
    cpu->a = result;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
}

// 0x98: SBC A,B
void sbc_a_b(Memory* mem, CPU* cpu) {
    uint8_t value = cpu->b;
    uint8_t carry = (cpu->f & FLAG_C) ? 1 : 0;
    uint8_t result = cpu->a - value - carry;
    set_flag(cpu, FLAG_N);
    (((value & 0xF) + carry) > (cpu->a & 0xF)) ? set_flag(cpu, FLAG_H) : clear_flag(cpu, FLAG_H);
    ((value + carry) > cpu->a) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
    cpu->a = result;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
}

// 0x99: SBC A,C
void sbc_a_c(Memory* mem, CPU* cpu) {
    uint8_t value = cpu->c;
    uint8_t carry = (cpu->f & FLAG_C) ? 1 : 0;
    uint8_t result = cpu->a - value - carry;
    set_flag(cpu, FLAG_N);
    (((value & 0xF) + carry) > (cpu->a & 0xF)) ? set_flag(cpu, FLAG_H) : clear_flag(cpu, FLAG_H);
    ((value + carry) > cpu->a) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
    cpu->a = result;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
}

// 0x9A: SBC A,D
void sbc_a_d(Memory* mem, CPU* cpu) {
    uint8_t value = cpu->d;
    uint8_t carry = (cpu->f & FLAG_C) ? 1 : 0;
    uint8_t result = cpu->a - value - carry;
    set_flag(cpu, FLAG_N);
    (((value & 0xF) + carry) > (cpu->a & 0xF)) ? set_flag(cpu, FLAG_H) : clear_flag(cpu, FLAG_H);
    ((value + carry) > cpu->a) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
    cpu->a = result;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
}

// 0x9B: SBC A,E
void sbc_a_e(Memory* mem, CPU* cpu) {
    uint8_t value = cpu->e;
    uint8_t carry = (cpu->f & FLAG_C) ? 1 : 0;
    uint8_t result = cpu->a - value - carry;
    set_flag(cpu, FLAG_N);
    (((value & 0xF) + carry) > (cpu->a & 0xF)) ? set_flag(cpu, FLAG_H) : clear_flag(cpu, FLAG_H);
    ((value + carry) > cpu->a) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
    cpu->a = result;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
}

// 0x9C: SBC A,H
void sbc_a_h(Memory* mem, CPU* cpu) {
    uint8_t value = cpu->h;
    uint8_t carry = (cpu->f & FLAG_C) ? 1 : 0;
    uint8_t result = cpu->a - value - carry;
    set_flag(cpu, FLAG_N);
    (((value & 0xF) + carry) > (cpu->a & 0xF)) ? set_flag(cpu, FLAG_H) : clear_flag(cpu, FLAG_H);
    ((value + carry) > cpu->a) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
    cpu->a = result;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
}

// 0x9D: SBC A,L
void sbc_a_l(Memory* mem, CPU* cpu) {
    uint8_t value = cpu->l;
    uint8_t carry = (cpu->f & FLAG_C) ? 1 : 0;
    uint8_t result = cpu->a - value - carry;
    set_flag(cpu, FLAG_N);
    (((value & 0xF) + carry) > (cpu->a & 0xF)) ? set_flag(cpu, FLAG_H) : clear_flag(cpu, FLAG_H);
    ((value + carry) > cpu->a) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
    cpu->a = result;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
}

// 0x9E: SBC A,(HL)
void sbc_a_hl(Memory* mem, CPU* cpu) {
    uint8_t value = read_memory_byte(mem, get_hl(cpu));
    uint8_t carry = (cpu->f & FLAG_C) ? 1 : 0;
    uint8_t result = cpu->a - value - carry;
    set_flag(cpu, FLAG_N);
    (((value & 0xF) + carry) > (cpu->a & 0xF)) ? set_flag(cpu, FLAG_H) : clear_flag(cpu, FLAG_H);
    ((value + carry) > cpu->a) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
    cpu->a = result;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
}

// 0x9F: SBC A,A
void sbc_a_a(Memory* mem, CPU* cpu) {
    uint8_t value = cpu->a;
    uint8_t carry = (cpu->f & FLAG_C) ? 1 : 0;
    uint8_t result = cpu->a - value - carry;
    set_flag(cpu, FLAG_N);
    (((value & 0xF) + carry) > (cpu->a & 0xF)) ? set_flag(cpu, FLAG_H) : clear_flag(cpu, FLAG_H);
    ((value + carry) > cpu->a) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
    cpu->a = result;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
}