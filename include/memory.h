#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>
#include "timer.h" // Add timer.h for Timer struct

typedef struct {
  uint8_t data[0x10000];
  // Pointers to timer and interrupt flag owned by CPU for memory-mapped IO
  Timer* timer;
  uint8_t* IF; // Interrupt Flag register (0xFF0F)
  uint8_t* IE; // Interrupt Enable register (0xFFFF)
} Memory;

// Initialize memory and set pointers to timer + IF so reads/writes can map registers
void memory_init(Memory* RAM, Timer* timer, uint8_t* IF, uint8_t* IE);
uint8_t read_memory_byte(Memory* RAM, uint16_t address);
void write_memory_byte(Memory* RAM, uint16_t address, uint8_t value);
uint16_t read_memory_word(Memory* RAM, uint16_t address);
void write_memory_word(Memory* RAM, uint16_t address, uint16_t value);
int load_rom(Memory* memory, const char* filename);

#endif /* ifndef MEMORY_H */
