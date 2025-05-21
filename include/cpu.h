#ifndef CPU_H
#define CPU_H

#include <stdint.h>

typedef struct {
    uint8_t a;
    uint8_t f;
    uint8_t b;
    uint8_t c;
    uint8_t d;
    uint8_t e;
    uint8_t h;
    uint8_t l;

    uint16_t sp; 
    uint16_t pc;

    uint8_t ime; 
    int cycles;
} CPU;

uint16_t get_af(CPU* cpu);
uint16_t get_bc(CPU* cpu);
uint16_t get_de(CPU* cpu);
uint16_t get_hl(CPU* cpu);

void set_af(CPU* cpu, uint16_t val);
void set_bc(CPU* cpu, uint16_t val);
void set_de(CPU* cpu, uint16_t val);
void set_hl(CPU* cpu, uint16_t val);

void cpu_init(CPU* cpu);

#endif
