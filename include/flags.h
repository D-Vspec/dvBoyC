#ifndef FLAGS_H
#define FLAGS_H

#include "cpu.h"

#define FLAG_Z 0x80
#define FLAG_N 0x40
#define FLAG_H 0x20
#define FLAG_C 0x10

static inline void set_flag(CPU* cpu, uint8_t flag) {
    cpu->f |= flag;
}
static inline void clear_flag(CPU* cpu, uint8_t flag) {
    cpu->f &= ~flag;
}
static inline int is_flag_set(CPU* cpu, uint8_t flag) {
    return (cpu->f & flag) != 0;
}


#endif