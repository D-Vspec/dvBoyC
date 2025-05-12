#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>

typedef struct {
  uint8_t data[0x10000];
} Memory;

void memory_init(Memory* RAM);

#endif /* ifndef MEMORY_H */
