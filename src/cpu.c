#include "cpu.h"
#include <stdio.h>

uint16_t get_af(CPU* cpu) {
    return (cpu->a << 8) | (cpu->f & 0xF0);
}
void set_af(CPU* cpu, uint16_t val) {
    cpu->a = val >> 8;
    cpu->f = val & 0xF0;
}

uint16_t get_bc(CPU* cpu) {
    return (cpu->b << 8) | cpu->c;
}
void set_bc(CPU* cpu, uint16_t val) {
    cpu->b = val >> 8;
    cpu->c = val & 0xFF;
}

uint16_t get_de(CPU* cpu) {
    return (cpu->d << 8) | cpu->e;
}
void set_de(CPU* cpu, uint16_t val) {
    cpu->d = val >> 8;
    cpu->e = val & 0xFF;
}

uint16_t get_hl(CPU* cpu) {
    return (cpu->h << 8) | cpu->l;
}
void set_hl(CPU* cpu, uint16_t val) {
    cpu->h = val >> 8;
    cpu->l = val & 0xFF;
}

void inc_hl(CPU* cpu) {
    uint16_t value = get_hl(cpu);
    set_hl(cpu, value + 1);
}

void dec_hl(CPU* cpu) {
    uint16_t value = get_hl(cpu);
    set_hl(cpu, value - 1);
}

void cpu_init(CPU* cpu) {
    cpu->a = 0x01;
    cpu->f = 0xB0;
    cpu->b = 0x00;
    cpu->c = 0x13;
    cpu->d = 0x00;
    cpu->e = 0xD8;
    cpu->h = 0x01;
    cpu->l = 0x4D;
    cpu->sp = 0xFFFE;
    cpu->pc = 0x0100;

    printf("CPU initialized\n");
}


