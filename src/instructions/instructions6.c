#include "instructionsList.h"
#include "flags.h"
#include "cpu.h"
#include "memory.h"

// 0xC0: RET NZ
void ret_nz(Memory* mem, CPU* cpu) {
    if (!(cpu->f & FLAG_Z)) {
        uint16_t addr = read_memory_word(mem, cpu->sp);
        cpu->sp += 2;
        cpu->pc = addr;
    }
}

// 0xC1: POP BC
void pop_bc(Memory* mem, CPU* cpu) {
    cpu->c = read_memory_byte(mem, cpu->sp);
    cpu->b = read_memory_byte(mem, cpu->sp + 1);
    cpu->sp += 2;
}

// 0xC2: JP NZ,nn
void jp_nz_nn(Memory* mem, CPU* cpu) {
    uint16_t addr = read_memory_word(mem, cpu->pc + 1);
    if (!(cpu->f & FLAG_Z)) {
        cpu->pc = addr;
    } else {
        cpu->pc += 3;
    }
}

// 0xC3: JP nn
void jp_nn(Memory* mem, CPU* cpu) {
    uint16_t addr = read_memory_word(mem, cpu->pc + 1);
    cpu->pc = addr;
}

// 0xC4: CALL NZ,nn
void call_nz_nn(Memory* mem, CPU* cpu) {
    uint16_t addr = read_memory_word(mem, cpu->pc + 1);
    if (!(cpu->f & FLAG_Z)) {
        cpu->sp -= 2;
        write_memory_word(mem, cpu->sp, cpu->pc + 3);
        cpu->pc = addr;
    } 
}

// 0xC5: PUSH BC
void push_bc(Memory* mem, CPU* cpu) {
    cpu->sp -= 2;
    write_memory_byte(mem, cpu->sp, cpu->c);
    write_memory_byte(mem, cpu->sp + 1, cpu->b);
}

// 0xC6: ADD A,n
void add_a_n(Memory* mem, CPU* cpu) {
    uint8_t value = read_memory_byte(mem, cpu->pc + 1);
    uint16_t result = cpu->a + value;
    clear_flag(cpu, FLAG_N);
    (((cpu->a & 0xF) + (value & 0xF)) > 0xF) ? set_flag(cpu, FLAG_H) : clear_flag(cpu, FLAG_H);
    (result > 0xFF) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
    cpu->a = (uint8_t)result;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
    cpu->pc += 2;
}

// 0xC7: RST 00H
void rst_00h(Memory* mem, CPU* cpu) {
    cpu->sp -= 2;
    write_memory_word(mem, cpu->sp, cpu->pc + 1);
    cpu->pc = 0x00;
}

// 0xC8: RET Z
void ret_z(Memory* mem, CPU* cpu) {
    if (cpu->f & FLAG_Z) {
        uint16_t addr = read_memory_word(mem, cpu->sp);
        cpu->sp += 2;
        cpu->pc = addr;
    }
}

// 0xC9: RET
void ret(Memory* mem, CPU* cpu) {
    uint16_t addr = read_memory_word(mem, cpu->sp);
    cpu->sp += 2;
    cpu->pc = addr;
}

// 0xCA: JP Z,nn
void jp_z_nn(Memory* mem, CPU* cpu) {
    uint16_t addr = read_memory_word(mem, cpu->pc + 1);
    if (cpu->f & FLAG_Z) {
        cpu->pc = addr;
    } else {
        cpu->pc += 3;
    }
}

// 0xCB: PREFIX CB (handled elsewhere)
void prefix_cb(Memory* mem, CPU* cpu) {
    // CB-prefixed instructions handled in a separate table
}

// 0xCC: CALL Z,nn
void call_z_nn(Memory* mem, CPU* cpu) {
    uint16_t addr = read_memory_word(mem, cpu->pc + 1);
    if (cpu->f & FLAG_Z) {
        cpu->sp -= 2;
        write_memory_word(mem, cpu->sp, cpu->pc + 3);
        cpu->pc = addr;
    } else {
        cpu->pc += 3;
    }
}

// 0xCD: CALL nn
void call_nn(Memory* mem, CPU* cpu) {
    uint16_t addr = read_memory_word(mem, cpu->pc + 1);
    cpu->sp -= 2;
    write_memory_word(mem, cpu->sp, cpu->pc + 3);
    cpu->pc = addr;
}

// 0xCE: ADC A,n
void adc_a_n(Memory* mem, CPU* cpu) {
    uint8_t value = read_memory_byte(mem, cpu->pc + 1);
    uint8_t carry = (cpu->f & FLAG_C) ? 1 : 0;
    uint16_t result = cpu->a + value + carry;
    clear_flag(cpu, FLAG_N);
    (((cpu->a & 0xF) + (value & 0xF) + carry) > 0xF) ? set_flag(cpu, FLAG_H) : clear_flag(cpu, FLAG_H);
    (result > 0xFF) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
    cpu->a = (uint8_t)result;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
    cpu->pc += 2;
}

// 0xCF: RST 08H
void rst_08h(Memory* mem, CPU* cpu) {
    cpu->sp -= 2;
    write_memory_word(mem, cpu->sp, cpu->pc + 1);
    cpu->pc = 0x08;
}

// 0xD0: RET NC
void ret_nc(Memory* mem, CPU* cpu) {
    if (!(cpu->f & FLAG_C)) {
        uint16_t addr = read_memory_word(mem, cpu->sp);
        cpu->sp += 2;
        cpu->pc = addr;
    }
}

// 0xD1: POP DE
void pop_de(Memory* mem, CPU* cpu) {
    cpu->e = read_memory_byte(mem, cpu->sp);
    cpu->d = read_memory_byte(mem, cpu->sp + 1);
    cpu->sp += 2;
}

// 0xD2: JP NC,nn
void jp_nc_nn(Memory* mem, CPU* cpu) {
    uint16_t addr = read_memory_word(mem, cpu->pc + 1);
    if (!(cpu->f & FLAG_C)) {
        cpu->pc = addr;
    } else {
        cpu->pc += 3;
    }
}

// 0xD3: (Unused)
void unused_d3(Memory* mem, CPU* cpu) { /* Unused opcode */ }

// 0xD4: CALL NC,nn
void call_nc_nn(Memory* mem, CPU* cpu) {
    uint16_t addr = read_memory_word(mem, cpu->pc + 1);
    if (!(cpu->f & FLAG_C)) {
        cpu->sp -= 2;
        write_memory_word(mem, cpu->sp, cpu->pc + 3);
        cpu->pc = addr;
    } else {
        cpu->pc += 3;
    }
}

// 0xD5: PUSH DE
void push_de(Memory* mem, CPU* cpu) {
    cpu->sp -= 2;
    write_memory_byte(mem, cpu->sp, cpu->e);
    write_memory_byte(mem, cpu->sp + 1, cpu->d);
}

// 0xD6: SUB n
void sub_n(Memory* mem, CPU* cpu) {
    uint8_t value = read_memory_byte(mem, cpu->pc + 1);
    uint8_t result = cpu->a - value;
    set_flag(cpu, FLAG_N);
    ((value & 0xF) > (cpu->a & 0xF)) ? set_flag(cpu, FLAG_H) : clear_flag(cpu, FLAG_H);
    (value > cpu->a) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
    cpu->a = result;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
    cpu->pc += 2;
}

// 0xD7: RST 10H
void rst_10h(Memory* mem, CPU* cpu) {
    cpu->sp -= 2;
    write_memory_word(mem, cpu->sp, cpu->pc + 1);
    cpu->pc = 0x10;
}

// 0xD8: RET C
void ret_c(Memory* mem, CPU* cpu) {
    if (cpu->f & FLAG_C) {
        uint16_t addr = read_memory_word(mem, cpu->sp);
        cpu->sp += 2;
        cpu->pc = addr;
    }
}

// 0xD9: RETI
void reti(Memory* mem, CPU* cpu) {
    uint16_t addr = read_memory_word(mem, cpu->sp);
    cpu->sp += 2;
    cpu->pc = addr;
    // Set IME (interrupt master enable) here if needed
}

// 0xDA: JP C,nn
void jp_c_nn(Memory* mem, CPU* cpu) {
    uint16_t addr = read_memory_word(mem, cpu->pc + 1);
    if (cpu->f & FLAG_C) {
        cpu->pc = addr;
    } else {
        cpu->pc += 3;
    }
}

// 0xDB: (Unused)
void unused_db(Memory* mem, CPU* cpu) { /* Unused opcode */ }

// 0xDC: CALL C,nn
void call_c_nn(Memory* mem, CPU* cpu) {
    uint16_t addr = read_memory_word(mem, cpu->pc + 1);
    if (cpu->f & FLAG_C) {
        cpu->sp -= 2;
        write_memory_word(mem, cpu->sp, cpu->pc + 3);
        cpu->pc = addr;
    } else {
        cpu->pc += 3;
    }
}

// 0xDD: (Unused)
void unused_dd(Memory* mem, CPU* cpu) { /* Unused opcode */ }

// 0xDE: SBC A,n
void sbc_a_n(Memory* mem, CPU* cpu) {
    uint8_t value = read_memory_byte(mem, cpu->pc + 1);
    uint8_t carry = (cpu->f & FLAG_C) ? 1 : 0;
    uint8_t result = cpu->a - value - carry;
    set_flag(cpu, FLAG_N);
    (((value & 0xF) + carry) > (cpu->a & 0xF)) ? set_flag(cpu, FLAG_H) : clear_flag(cpu, FLAG_H);
    ((value + carry) > cpu->a) ? set_flag(cpu, FLAG_C) : clear_flag(cpu, FLAG_C);
    cpu->a = result;
    (cpu->a == 0) ? set_flag(cpu, FLAG_Z) : clear_flag(cpu, FLAG_Z);
    cpu->pc += 2;
}

// 0xDF: RST 18H
void rst_18h(Memory* mem, CPU* cpu) {
    cpu->sp -= 2;
    write_memory_word(mem, cpu->sp, cpu->pc + 1);
    cpu->pc = 0x18;
}
