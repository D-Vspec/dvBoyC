#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>

typedef struct {
  uint8_t data[0x10000];
} Memory;

void memory_init(Memory* RAM);
uint8_t read_memory_byte(Memory* RAM, uint16_t address);
void write_memory_byte(Memory* RAM, uint16_t address, uint8_t value);

#endif /* ifndef MEMORY_H */
