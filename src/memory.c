#include "memory.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

void memory_init(Memory* RAM, Timer* timer, uint8_t* IF, uint8_t* IE){
  memset(RAM->data, 0, sizeof(RAM->data));
  RAM->timer = timer;
  RAM->IF = IF;
  RAM->IE = IE;
  printf("Initialized empty RAM\n");
}

int load_rom(Memory* RAM, const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Error: Could not open ROM file %s\n", filename);
        return 0;
    }
    
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    if (file_size > 0x8000) {
        printf("Warning: ROM size %ld bytes exceeds 32KB, truncating\n", file_size);
        file_size = 0x8000;
    }
    
    size_t bytes_read = fread(&RAM->data[0x0000], 1, file_size, file);
    fclose(file);
    
    if (bytes_read != file_size) {
        printf("Error: Could not read ROM file completely\n");
        return 0;
    }
    
    printf("Loaded ROM: %s (%ld bytes) into address 0x0000-0x%04X\n", 
           filename, file_size, (unsigned int)(file_size - 1));
    
    printf("ROM Title: ");
    for (int i = 0x0134; i < 0x0143; i++) {
        if (RAM->data[i] != 0) {
            printf("%c", RAM->data[i]);
        }
    }
    printf("\n");
    
    return 1;
}

uint8_t read_memory_byte(Memory* RAM, uint16_t address){
  // Timer registers
  if (address == 0xFF04) { // DIV upper 8 bits
    return (uint8_t)((RAM->timer->div >> 8) & 0xFF);
  } else if (address == 0xFF05) { // TIMA
    return RAM->timer->tima;
  } else if (address == 0xFF06) { // TMA
    return RAM->timer->tma;
  } else if (address == 0xFF07) { // TAC (lower 3 bits relevant)
    return RAM->timer->tac | 0xF8; // upper bits always read as 1 on DMG
  } else if (address == 0xFF0F) { // IF
    return *(RAM->IF) | 0xE0; // upper 3 bits set
  } else if (address == 0xFFFF) { // IE
    return *(RAM->IE) | 0xE0; // upper 3 bits set
  }
  return RAM->data[address];
}

void write_memory_byte(Memory* RAM, uint16_t address, uint8_t value){
  if (address == 0xFF04) { // DIV reset
    RAM->timer->div = 0; // reset divider
    RAM->timer->div_counter = 0;
    return;
  } else if (address == 0xFF05) { // TIMA
    RAM->timer->tima = value;
    return;
  } else if (address == 0xFF06) { // TMA
    RAM->timer->tma = value;
    return;
  } else if (address == 0xFF07) { // TAC
    RAM->timer->tac = value & 0x07; // only lower 3 bits
    return;
  } else if (address == 0xFF0F) { // IF
    *(RAM->IF) = value & 0x1F; // only lower 5 bits used
    return;
  } else if (address == 0xFFFF) { // IE
    *(RAM->IE) = value & 0x1F;
    return;
  }
  RAM->data[address] = value;
}

uint16_t read_memory_word(Memory* RAM, uint16_t address){
    return (uint16_t)read_memory_byte(RAM, address) | ((uint16_t)read_memory_byte(RAM, address + 1) << 8);
}

void write_memory_word(Memory* RAM, uint16_t address, uint16_t value){
    write_memory_byte(RAM, address, (uint8_t)(value & 0xFF));
    write_memory_byte(RAM, address + 1, (uint8_t)((value >> 8) & 0xFF));
}