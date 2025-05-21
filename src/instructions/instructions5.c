#include "instructionsList.h"
#include "flags.h"
#include "cpu.h"
#include "memory.h"

// 0xA0: AND B
void and_b(Memory* mem, CPU* cpu) {
    cpu->a &= cpu->b;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
    clear_flag(cpu, FLAG_N);
    set_flag(cpu, FLAG_H);
    clear_flag(cpu, FLAG_C);
}
// 0xA1: AND C
void and_c(Memory* mem, CPU* cpu) {
    cpu->a &= cpu->c;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
    clear_flag(cpu, FLAG_N);
    set_flag(cpu, FLAG_H);
    clear_flag(cpu, FLAG_C);
}
// 0xA2: AND D
void and_d(Memory* mem, CPU* cpu) {
    cpu->a &= cpu->d;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
    clear_flag(cpu, FLAG_N);
    set_flag(cpu, FLAG_H);
    clear_flag(cpu, FLAG_C);
}
// 0xA3: AND E
void and_e(Memory* mem, CPU* cpu) {
    cpu->a &= cpu->e;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
    clear_flag(cpu, FLAG_N);
    set_flag(cpu, FLAG_H);
    clear_flag(cpu, FLAG_C);
}
// 0xA4: AND H
void and_h(Memory* mem, CPU* cpu) {
    cpu->a &= cpu->h;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
    clear_flag(cpu, FLAG_N);
    set_flag(cpu, FLAG_H);
    clear_flag(cpu, FLAG_C);
}
// 0xA5: AND L
void and_l(Memory* mem, CPU* cpu) {
    cpu->a &= cpu->l;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
    clear_flag(cpu, FLAG_N);
    set_flag(cpu, FLAG_H);
    clear_flag(cpu, FLAG_C);
}
// 0xA6: AND (HL)
void and_hl(Memory* mem, CPU* cpu) {
    cpu->a &= read_memory_byte(mem, get_hl(cpu));
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
    clear_flag(cpu, FLAG_N);
    set_flag(cpu, FLAG_H);
    clear_flag(cpu, FLAG_C);
}
// 0xA7: AND A
void and_a(Memory* mem, CPU* cpu) {
    cpu->a &= cpu->a;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
    clear_flag(cpu, FLAG_N);
    set_flag(cpu, FLAG_H);
    clear_flag(cpu, FLAG_C);
}
// 0xA8: XOR B
void xor_b(Memory* mem, CPU* cpu) {
    cpu->a ^= cpu->b;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
    clear_flag(cpu, FLAG_N);
    clear_flag(cpu, FLAG_H);
    clear_flag(cpu, FLAG_C);
}
// 0xA9: XOR C
void xor_c(Memory* mem, CPU* cpu) {
    cpu->a ^= cpu->c;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
    clear_flag(cpu, FLAG_N);
    clear_flag(cpu, FLAG_H);
    clear_flag(cpu, FLAG_C);
}
// 0xAA: XOR D
void xor_d(Memory* mem, CPU* cpu) {
    cpu->a ^= cpu->d;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
    clear_flag(cpu, FLAG_N);
    clear_flag(cpu, FLAG_H);
    clear_flag(cpu, FLAG_C);
}
// 0xAB: XOR E
void xor_e(Memory* mem, CPU* cpu) {
    cpu->a ^= cpu->e;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
    clear_flag(cpu, FLAG_N);
    clear_flag(cpu, FLAG_H);
    clear_flag(cpu, FLAG_C);
}
// 0xAC: XOR H
void xor_h(Memory* mem, CPU* cpu) {
    cpu->a ^= cpu->h;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
    clear_flag(cpu, FLAG_N);
    clear_flag(cpu, FLAG_H);
    clear_flag(cpu, FLAG_C);
}
// 0xAD: XOR L
void xor_l(Memory* mem, CPU* cpu) {
    cpu->a ^= cpu->l;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
    clear_flag(cpu, FLAG_N);
    clear_flag(cpu, FLAG_H);
    clear_flag(cpu, FLAG_C);
}
// 0xAE: XOR (HL)
void xor_hl(Memory* mem, CPU* cpu) {
    cpu->a ^= read_memory_byte(mem, get_hl(cpu));
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
    clear_flag(cpu, FLAG_N);
    clear_flag(cpu, FLAG_H);
    clear_flag(cpu, FLAG_C);
}
// 0xAF: XOR A
void xor_a(Memory* mem, CPU* cpu) {
    cpu->a ^= cpu->a;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
    clear_flag(cpu, FLAG_N);
    clear_flag(cpu, FLAG_H);
    clear_flag(cpu, FLAG_C);
}
// 0xB0: OR B
void or_b(Memory* mem, CPU* cpu) {
    cpu->a |= cpu->b;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
    clear_flag(cpu, FLAG_N);
    clear_flag(cpu, FLAG_H);
    clear_flag(cpu, FLAG_C);
}
// 0xB1: OR C
void or_c(Memory* mem, CPU* cpu) {
    cpu->a |= cpu->c;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
    clear_flag(cpu, FLAG_N);
    clear_flag(cpu, FLAG_H);
    clear_flag(cpu, FLAG_C);
}
// 0xB2: OR D
void or_d(Memory* mem, CPU* cpu) {
    cpu->a |= cpu->d;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
    clear_flag(cpu, FLAG_N);
    clear_flag(cpu, FLAG_H);
    clear_flag(cpu, FLAG_C);
}
// 0xB3: OR E
void or_e(Memory* mem, CPU* cpu) {
    cpu->a |= cpu->e;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
    clear_flag(cpu, FLAG_N);
    clear_flag(cpu, FLAG_H);
    clear_flag(cpu, FLAG_C);
}
// 0xB4: OR H
void or_h(Memory* mem, CPU* cpu) {
    cpu->a |= cpu->h;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
    clear_flag(cpu, FLAG_N);
    clear_flag(cpu, FLAG_H);
    clear_flag(cpu, FLAG_C);
}
// 0xB5: OR L
void or_l(Memory* mem, CPU* cpu) {
    cpu->a |= cpu->l;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
    clear_flag(cpu, FLAG_N);
    clear_flag(cpu, FLAG_H);
    clear_flag(cpu, FLAG_C);
}
// 0xB6: OR (HL)
void or_hl(Memory* mem, CPU* cpu) {
    cpu->a |= read_memory_byte(mem, get_hl(cpu));
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
    clear_flag(cpu, FLAG_N);
    clear_flag(cpu, FLAG_H);
    clear_flag(cpu, FLAG_C);
}
// 0xB7: OR A
void or_a(Memory* mem, CPU* cpu) {
    cpu->a |= cpu->a;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
    clear_flag(cpu, FLAG_N);
    clear_flag(cpu, FLAG_H);
    clear_flag(cpu, FLAG_C);
}
// 0xB8: CP B
void cp_b(Memory* mem, CPU* cpu) {
    uint8_t value = cpu->b;
    set_flag(cpu, FLAG_N);
    ((cpu->a - value) == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
    ((value & 0xF) > (cpu->a & 0xF)) ? set_flag(cpu, FLAG_H) : clear_flag(cpu, FLAG_H);
    (value > cpu->a) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
}
// 0xB9: CP C
void cp_c(Memory* mem, CPU* cpu) {
    uint8_t value = cpu->c;
    set_flag(cpu, FLAG_N);
    ((cpu->a - value) == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
    ((value & 0xF) > (cpu->a & 0xF)) ? set_flag(cpu, FLAG_H) : clear_flag(cpu, FLAG_H);
    (value > cpu->a) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
}
// 0xBA: CP D
void cp_d(Memory* mem, CPU* cpu) {
    uint8_t value = cpu->d;
    set_flag(cpu, FLAG_N);
    ((cpu->a - value) == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
    ((value & 0xF) > (cpu->a & 0xF)) ? set_flag(cpu, FLAG_H) : clear_flag(cpu, FLAG_H);
    (value > cpu->a) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
}
// 0xBB: CP E
void cp_e(Memory* mem, CPU* cpu) {
    uint8_t value = cpu->e;
    set_flag(cpu, FLAG_N);
    ((cpu->a - value) == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
    ((value & 0xF) > (cpu->a & 0xF)) ? set_flag(cpu, FLAG_H) : clear_flag(cpu, FLAG_H);
    (value > cpu->a) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
}
// 0xBC: CP H
void cp_h(Memory* mem, CPU* cpu) {
    uint8_t value = cpu->h;
    set_flag(cpu, FLAG_N);
    ((cpu->a - value) == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
    ((value & 0xF) > (cpu->a & 0xF)) ? set_flag(cpu, FLAG_H) : clear_flag(cpu, FLAG_H);
    (value > cpu->a) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
}
// 0xBD: CP L
void cp_l(Memory* mem, CPU* cpu) {
    uint8_t value = cpu->l;
    set_flag(cpu, FLAG_N);
    ((cpu->a - value) == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
    ((value & 0xF) > (cpu->a & 0xF)) ? set_flag(cpu, FLAG_H) : clear_flag(cpu, FLAG_H);
    (value > cpu->a) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
}
// 0xBE: CP (HL)
void cp_hl(Memory* mem, CPU* cpu) {
    uint8_t value = read_memory_byte(mem, get_hl(cpu));
    set_flag(cpu, FLAG_N);
    ((cpu->a - value) == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
    ((value & 0xF) > (cpu->a & 0xF)) ? set_flag(cpu, FLAG_H) : clear_flag(cpu, FLAG_H);
    (value > cpu->a) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
}
// 0xBF: CP A
void cp_a(Memory* mem, CPU* cpu) {
    uint8_t value = cpu->a;
    set_flag(cpu, FLAG_N);
    ((cpu->a - value) == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
    ((value & 0xF) > (cpu->a & 0xF)) ? set_flag(cpu, FLAG_H) : clear_flag(cpu, FLAG_H);
    (value > cpu->a) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
}
