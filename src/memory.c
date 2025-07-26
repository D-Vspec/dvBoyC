#include "memory.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

void memory_init(Memory* RAM){
  memset(RAM->data, 0, sizeof(RAM->data));
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