#include "memory.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>

void memory_init(Memory* RAM){
  memset(RAM->data, 0, sizeof(RAM->data));
  printf("Initialized empty RAM\n");
}

uint8_t read_memory_byte(Memory* RAM, uint16_t address){
  return RAM->data[address];
}

void write_memory_byte(Memory* RAM, uint16_t address, uint8_t value){
  RAM->data[address] = value;
} 