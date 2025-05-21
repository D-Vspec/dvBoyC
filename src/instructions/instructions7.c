#include "instructions.h"
#include "flags.h"
#include "cpu.h"
#include "memory.h"

// 0xE0: LDH (a8),A
void ldh_a8_a(Memory* mem, CPU* cpu) {
    uint8_t a8 = read_memory_byte(mem, cpu->pc + 1);
    write_memory_byte(mem, 0xFF00 + a8, cpu->a);
    cpu->pc += 2;
}

// 0xE1: POP HL
void pop_hl(Memory* mem, CPU* cpu) {
    cpu->l = read_memory_byte(mem, cpu->sp);
    cpu->h = read_memory_byte(mem, cpu->sp + 1);
    cpu->sp += 2;
}

// 0xE2: LD (C),A
void ld__c_a(Memory* mem, CPU* cpu) {
    write_memory_byte(mem, 0xFF00 + cpu->c, cpu->a);
    cpu->pc++;
}

// 0xE3: (Unused)
void unused_e3(Memory* mem, CPU* cpu) { /* Unused opcode */ }

// 0xE4: (Unused)
void unused_e4(Memory* mem, CPU* cpu) { /* Unused opcode */ }

// 0xE5: PUSH HL
void push_hl(Memory* mem, CPU* cpu) {
    cpu->sp -= 2;
    write_memory_byte(mem, cpu->sp, cpu->l);
    write_memory_byte(mem, cpu->sp + 1, cpu->h);
}

// 0xE6: AND n
void and_n(Memory* mem, CPU* cpu) {
    uint8_t value = read_memory_byte(mem, cpu->pc + 1);
    cpu->a &= value;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
    clear_flag(cpu, FLAG_N);
    set_flag(cpu, FLAG_H);
    clear_flag(cpu, FLAG_C);
    cpu->pc += 2;
}

// 0xE7: RST 20H
void rst_20h(Memory* mem, CPU* cpu) {
    cpu->sp -= 2;
    write_memory_word(mem, cpu->sp, cpu->pc + 1);
    cpu->pc = 0x20;
}

// 0xE8: ADD SP,s8
void add_sp_s8(Memory* mem, CPU* cpu) {
    int8_t s8 = (int8_t)read_memory_byte(mem, cpu->pc + 1);
    uint16_t sp = cpu->sp;
    uint16_t result = sp + s8;
    clear_flag(cpu, FLAG_Z);
    clear_flag(cpu, FLAG_N);
    (((sp & 0xF) + (s8 & 0xF)) > 0xF) ? set_flag(cpu, FLAG_H) : clear_flag(cpu, FLAG_H);
    (((sp & 0xFF) + (s8 & 0xFF)) > 0xFF) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
    cpu->sp = result;
    cpu->pc += 2;
}

// 0xE9: JP (HL)
void jp_hl(Memory* mem, CPU* cpu) {
    cpu->pc = get_hl(cpu);
}

// 0xEA: LD (a16),A
void ld_a16_a(Memory* mem, CPU* cpu) {
    uint16_t addr = read_memory_word(mem, cpu->pc + 1);
    write_memory_byte(mem, addr, cpu->a);
    cpu->pc += 3;
}

// 0xEB: (Unused)
void unused_eb(Memory* mem, CPU* cpu) { /* Unused opcode */ }

// 0xEC: (Unused)
void unused_ec(Memory* mem, CPU* cpu) { /* Unused opcode */ }

// 0xED: (Unused)
void unused_ed(Memory* mem, CPU* cpu) { /* Unused opcode */ }

// 0xEE: XOR n
void xor_n(Memory* mem, CPU* cpu) {
    uint8_t value = read_memory_byte(mem, cpu->pc + 1);
    cpu->a ^= value;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
    clear_flag(cpu, FLAG_N);
    clear_flag(cpu, FLAG_H);
    clear_flag(cpu, FLAG_C);
    cpu->pc += 2;
}

// 0xEF: RST 28H
void rst_28h(Memory* mem, CPU* cpu) {
    cpu->sp -= 2;
    write_memory_word(mem, cpu->sp, cpu->pc + 1);
    cpu->pc = 0x28;
}

// 0xF0: LDH A,(a8)
void ldh_a_a8(Memory* mem, CPU* cpu) {
    uint8_t a8 = read_memory_byte(mem, cpu->pc + 1);
    cpu->a = read_memory_byte(mem, 0xFF00 + a8);
    cpu->pc += 2;
}

// 0xF1: POP AF
void pop_af(Memory* mem, CPU* cpu) {
    cpu->f = read_memory_byte(mem, cpu->sp);
    cpu->a = read_memory_byte(mem, cpu->sp + 1);
    cpu->sp += 2;
}

// 0xF2: LD A,(C)
void ld_a__c(Memory* mem, CPU* cpu) {
    cpu->a = read_memory_byte(mem, 0xFF00 + cpu->c);
    cpu->pc++;
}

// 0xF3: DI
void di(Memory* mem, CPU* cpu) {
    // Disable interrupts (IME = 0)
    cpu->ime = 0;
    cpu->pc++;
}

// 0xF4: (Unused)
void unused_f4(Memory* mem, CPU* cpu) { /* Unused opcode */ }

// 0xF5: PUSH AF
void push_af(Memory* mem, CPU* cpu) {
    cpu->sp -= 2;
    write_memory_byte(mem, cpu->sp, cpu->f);
    write_memory_byte(mem, cpu->sp + 1, cpu->a);
}

// 0xF6: OR n
void or_n(Memory* mem, CPU* cpu) {
    uint8_t value = read_memory_byte(mem, cpu->pc + 1);
    cpu->a |= value;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
    clear_flag(cpu, FLAG_N);
    clear_flag(cpu, FLAG_H);
    clear_flag(cpu, FLAG_C);
    cpu->pc += 2;
}

// 0xF7: RST 30H
void rst_30h(Memory* mem, CPU* cpu) {
    cpu->sp -= 2;
    write_memory_word(mem, cpu->sp, cpu->pc + 1);
    cpu->pc = 0x30;
}

// 0xF8: LD HL,SP+s8
void ld_hl_sp_s8(Memory* mem, CPU* cpu) {
    int8_t s8 = (int8_t)read_memory_byte(mem, cpu->pc + 1);
    uint16_t sp = cpu->sp;
    uint16_t result = sp + s8;
    clear_flag(cpu, FLAG_Z);
    clear_flag(cpu, FLAG_N);
    (((sp & 0xF) + (s8 & 0xF)) > 0xF) ? set_flag(cpu, FLAG_H) : clear_flag(cpu, FLAG_H);
    (((sp & 0xFF) + (s8 & 0xFF)) > 0xFF) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
    cpu->h = (result >> 8) & 0xFF;
    cpu->l = result & 0xFF;
    cpu->pc += 2;
}

// 0xF9: LD SP,HL
void ld_sp_hl(Memory* mem, CPU* cpu) {
    cpu->sp = get_hl(cpu);
    cpu->pc++;
}

// 0xFA: LD A,(a16)
void ld_a_a16(Memory* mem, CPU* cpu) {
    uint16_t addr = read_memory_word(mem, cpu->pc + 1);
    cpu->a = read_memory_byte(mem, addr);
    cpu->pc += 3;
}

// 0xFB: EI
void ei(Memory* mem, CPU* cpu) {
    // Enable interrupts (IME = 1)
    cpu->ime = 1;
    cpu->pc++;
}

// 0xFC: (Unused)
void unused_fc(Memory* mem, CPU* cpu) { /* Unused opcode */ }

// 0xFD: (Unused)
void unused_fd(Memory* mem, CPU* cpu) { /* Unused opcode */ }

// 0xFE: CP n
void cp_n(Memory* mem, CPU* cpu) {
    uint8_t value = read_memory_byte(mem, cpu->pc + 1);
    uint8_t result = cpu->a - value;
    set_flag(cpu, FLAG_N);
    ((value & 0xF) > (cpu->a & 0xF)) ? set_flag(cpu, FLAG_H) : clear_flag(cpu, FLAG_H);
    (value > cpu->a) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
    (result == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
    cpu->pc += 2;
}

// 0xFF: RST 38H
void rst_38h(Memory* mem, CPU* cpu) {
    cpu->sp -= 2;
    write_memory_word(mem, cpu->sp, cpu->pc + 1);
    cpu->pc = 0x38;
}
