#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>

typedef struct {
  uint8_t data[0x10000];
} Memory;

void memory_init(Memory* RAM);
uint8_t read_memory_byte(Memory* RAM, uint16_t address);
void write_memory_byte(Memory* RAM, uint16_t address, uint8_t value);
uint16_t read_memory_word(Memory* RAM, uint16_t address);
void write_memory_word(Memory* RAM, uint16_t address, uint16_t value);
int load_rom(Memory* memory, const char* filename);

#endif /* ifndef MEMORY_H */
