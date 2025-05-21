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

uint16_t read_memory_word(Memory* RAM, uint16_t address){
    return (uint16_t)RAM->data[address] | ((uint16_t)RAM->data[address + 1] << 8);
}

void write_memory_word(Memory* RAM, uint16_t address, uint16_t value){
    RAM->data[address] = (uint8_t)(value & 0xFF);
    RAM->data[address + 1] = (uint8_t)((value >> 8) & 0xFF);
}