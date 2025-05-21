#include "instructionsList.h"
#include "flags.h"
#include "cpu.h"
#include "memory.h"

// 0x40: LD B,B
void ld_b_b(Memory* mem, CPU* cpu) {
    // No operation needed since B is loaded with its own value
}

// 0x41: LD B,C
void ld_b_c(Memory* mem, CPU* cpu) {
    cpu->b = cpu->c;
}

// 0x42: LD B,D
void ld_b_d(Memory* mem, CPU* cpu) {
    cpu->b = cpu->d;
}

// 0x43: LD B,E
void ld_b_e(Memory* mem, CPU* cpu) {
    cpu->b = cpu->e;
}

// 0x44: LD B,H
void ld_b_h(Memory* mem, CPU* cpu) {
    cpu->b = cpu->h;
}

// 0x45: LD B,L
void ld_b_l(Memory* mem, CPU* cpu) {
    cpu->b = cpu->l;
}

// 0x46: LD B,(HL)
void ld_b_hl(Memory* mem, CPU* cpu) {
    cpu->b = read_memory_byte(mem, get_hl(cpu));
}

// 0x47: LD B,A
void ld_b_a(Memory* mem, CPU* cpu) {
    cpu->b = cpu->a;
}

// 0x48: LD C,B
void ld_c_b(Memory* mem, CPU* cpu) {
    cpu->c = cpu->b;
}

// 0x49: LD C,C
void ld_c_c(Memory* mem, CPU* cpu) {
    // No operation needed since C is loaded with its own value
}

// 0x4A: LD C,D
void ld_c_d(Memory* mem, CPU* cpu) {
    cpu->c = cpu->d;
}

// 0x4B: LD C,E
void ld_c_e(Memory* mem, CPU* cpu) {
    cpu->c = cpu->e;
}

// 0x4C: LD C,H
void ld_c_h(Memory* mem, CPU* cpu) {
    cpu->c = cpu->h;
}

// 0x4D: LD C,L
void ld_c_l(Memory* mem, CPU* cpu) {
    cpu->c = cpu->l;
}

// 0x4E: LD C,(HL)
void ld_c_hl(Memory* mem, CPU* cpu) {
    cpu->c = read_memory_byte(mem, get_hl(cpu));
}

// 0x4F: LD C,A
void ld_c_a(Memory* mem, CPU* cpu) {
    cpu->c = cpu->a;
}

// 0x50: LD D,B
void ld_d_b(Memory* mem, CPU* cpu) {
    cpu->d = cpu->b;
}

// 0x51: LD D,C
void ld_d_c(Memory* mem, CPU* cpu) {
    cpu->d = cpu->c;
}

// 0x52: LD D,D
void ld_d_d(Memory* mem, CPU* cpu) {
    // No operation needed since D is loaded with its own value
}

// 0x53: LD D,E
void ld_d_e(Memory* mem, CPU* cpu) {
    cpu->d = cpu->e;
}

// 0x54: LD D,H
void ld_d_h(Memory* mem, CPU* cpu) {
    cpu->d = cpu->h;
}

// 0x55: LD D,L
void ld_d_l(Memory* mem, CPU* cpu) {
    cpu->d = cpu->l;
}

// 0x56: LD D,(HL)
void ld_d_hl(Memory* mem, CPU* cpu) {
    cpu->d = read_memory_byte(mem, get_hl(cpu));
}

// 0x57: LD D,A
void ld_d_a(Memory* mem, CPU* cpu) {
    cpu->d = cpu->a;
}

// 0x58: LD E,B
void ld_e_b(Memory* mem, CPU* cpu) {
    cpu->e = cpu->b;
}

// 0x59: LD E,C
void ld_e_c(Memory* mem, CPU* cpu) {
    cpu->e = cpu->c;
}

// 0x5A: LD E,D
void ld_e_d(Memory* mem, CPU* cpu) {
    cpu->e = cpu->d;
}

// 0x5B: LD E,E
void ld_e_e(Memory* mem, CPU* cpu) {
    // No operation needed since E is loaded with its own value
}

// 0x5C: LD E,H
void ld_e_h(Memory* mem, CPU* cpu) {
    cpu->e = cpu->h;
}

// 0x5D: LD E,L
void ld_e_l(Memory* mem, CPU* cpu) {
    cpu->e = cpu->l;
}

// 0x5E: LD E,(HL)
void ld_e_hl(Memory* mem, CPU* cpu) {
    cpu->e = read_memory_byte(mem, get_hl(cpu));
}

// 0x5F: LD E,A
void ld_e_a(Memory* mem, CPU* cpu) {
    cpu->e = cpu->a;
}

// 0x60: LD H,B
void ld_h_b(Memory* mem, CPU* cpu) {
    cpu->h = cpu->b;
}

// 0x61: LD H,C
void ld_h_c(Memory* mem, CPU* cpu) {
    cpu->h = cpu->c;
}

// 0x62: LD H,D
void ld_h_d(Memory* mem, CPU* cpu) {
    cpu->h = cpu->d;
}

// 0x63: LD H,E
void ld_h_e(Memory* mem, CPU* cpu) {
    cpu->h = cpu->e;
}

// 0x64: LD H,H
void ld_h_h(Memory* mem, CPU* cpu) {
    // No operation needed since H is loaded with its own value
}

// 0x65: LD H,L
void ld_h_l(Memory* mem, CPU* cpu) {
    cpu->h = cpu->l;
}

// 0x66: LD H,(HL)
void ld_h_hl(Memory* mem, CPU* cpu) {
    cpu->h = read_memory_byte(mem, get_hl(cpu));
}

// 0x67: LD H,A
void ld_h_a(Memory* mem, CPU* cpu) {
    cpu->h = cpu->a;
}

// 0x68: LD L,B
void ld_l_b(Memory* mem, CPU* cpu) {
    cpu->l = cpu->b;
}

// 0x69: LD L,C
void ld_l_c(Memory* mem, CPU* cpu) {
    cpu->l = cpu->c;
}

// 0x6A: LD L,D
void ld_l_d(Memory* mem, CPU* cpu) {
    cpu->l = cpu->d;
}

// 0x6B: LD L,E
void ld_l_e(Memory* mem, CPU* cpu) {
    cpu->l = cpu->e;
}

// 0x6C: LD L,H
void ld_l_h(Memory* mem, CPU* cpu) {
    cpu->l = cpu->h;
}

// 0x6D: LD L,L
void ld_l_l(Memory* mem, CPU* cpu) {
    // No operation needed since L is loaded with its own value
}

// 0x6E: LD L,(HL)
void ld_l_hl(Memory* mem, CPU* cpu) {
    cpu->l = read_memory_byte(mem, get_hl(cpu));
}

// 0x6F: LD L,A
void ld_l_a(Memory* mem, CPU* cpu) {
    cpu->l = cpu->a;
}

// 0x70: LD (HL),B
void ld_hl_b(Memory* mem, CPU* cpu) {
    write_memory_byte(mem, get_hl(cpu), cpu->b);
}

// 0x71: LD (HL),C
void ld_hl_c(Memory* mem, CPU* cpu) {
    write_memory_byte(mem, get_hl(cpu), cpu->c);
}

// 0x72: LD (HL),D
void ld_hl_d(Memory* mem, CPU* cpu) {
    write_memory_byte(mem, get_hl(cpu), cpu->d);
}

// 0x73: LD (HL),E
void ld_hl_e(Memory* mem, CPU* cpu) {
    write_memory_byte(mem, get_hl(cpu), cpu->e);
}

// 0x74: LD (HL),H
void ld_hl_h(Memory* mem, CPU* cpu) {
    write_memory_byte(mem, get_hl(cpu), cpu->h);
}

// 0x75: LD (HL),L
void ld_hl_l(Memory* mem, CPU* cpu) {
    write_memory_byte(mem, get_hl(cpu), cpu->l);
}

// // 0x76: HALT
// void halt(Memory* mem, CPU* cpu) {
//     cpu->halted = 1;
// }

// 0x77: LD (HL),A
void ld_hl_a(Memory* mem, CPU* cpu) {
    write_memory_byte(mem, get_hl(cpu), cpu->a);
}

// 0x78: LD A,B
void ld_a_b(Memory* mem, CPU* cpu) {
    cpu->a = cpu->b;
}

// 0x79: LD A,C
void ld_a_c(Memory* mem, CPU* cpu) {
    cpu->a = cpu->c;
}

// 0x7A: LD A,D
void ld_a_d(Memory* mem, CPU* cpu) {
    cpu->a = cpu->d;
}

// 0x7B: LD A,E
void ld_a_e(Memory* mem, CPU* cpu) {
    cpu->a = cpu->e;
}

// 0x7C: LD A,H
void ld_a_h(Memory* mem, CPU* cpu) {
    cpu->a = cpu->h;
}

// 0x7D: LD A,L
void ld_a_l(Memory* mem, CPU* cpu) {
    cpu->a = cpu->l;
}

// 0x7E: LD A,(HL)
void ld_a_hl(Memory* mem, CPU* cpu) {
    cpu->a = read_memory_byte(mem, get_hl(cpu));
}

// 0x7F: LD A,A
void ld_a_a(Memory* mem, CPU* cpu) {
    // No operation needed since A is loaded with its own value
}