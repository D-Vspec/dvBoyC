#include "instructions.h"
#include "flags.h"
#include "memory.h"
#include <stdio.h>

Opcode opcode_table[256];

void init_opcode_table(void) {

    printf("Initializing opcode table...\n");

    opcode_table[0x00] = (Opcode){ nop, 1, 4, "NOP" };
    opcode_table[0x01] = (Opcode){ ld_bc_d16, 3, 12, "LD BC,d16" };
    opcode_table[0x02] = (Opcode){ ld_bc_a, 1, 8, "LD (BC),A" };
    opcode_table[0x03] = (Opcode){ inc_bc, 1, 8, "INC BC" };
    opcode_table[0x04] = (Opcode){ inc_b, 1, 4, "INC B" };
    opcode_table[0x05] = (Opcode){ dec_b, 1, 4, "DEC B" };
    opcode_table[0x06] = (Opcode){ ld_b_d8, 2, 8, "LD B,d8" };
    opcode_table[0x07] = (Opcode){ rlca, 1, 4, "RLCA" };
    opcode_table[0x08] = (Opcode){ ld_a16_sp, 3, 20, "LD (a16),SP" };
    opcode_table[0x09] = (Opcode){ add_hl_bc, 1, 8, "ADD HL,BC" };
    opcode_table[0x0A] = (Opcode){ ld_a_bc, 1, 8, "LD A,(BC)" };
    opcode_table[0x0B] = (Opcode){ dec_bc, 1, 8, "DEC BC" };
    opcode_table[0x0C] = (Opcode){ inc_c, 1, 4, "INC C" };
    opcode_table[0x0D] = (Opcode){ dec_c, 1, 4, "DEC C" };
    opcode_table[0x0E] = (Opcode){ ld_c_d8, 2, 8, "LD C,d8" };
    opcode_table[0x0F] = (Opcode){ rrca, 1, 4, "RRCA" };
}

void nop(Memory* mem, CPU* cpu) {
}

void ld_bc_d16(Memory* mem, CPU* cpu) {
    uint8_t low  = read_memory_byte(mem, cpu->pc + 1);
    uint8_t high = read_memory_byte(mem, cpu->pc + 2);
    set_bc(cpu, (high << 8) | low);
}

void ld_bc_a(Memory* mem, CPU* cpu) {
    write_memory_byte(mem, get_bc(cpu), cpu->a);
}

void inc_bc(Memory* mem, CPU* cpu) {
    uint16_t value = get_bc(cpu);
    set_bc(cpu, value + 1);
}

void inc_b(Memory* mem, CPU* cpu) {
    uint8_t result = cpu->b + 1;

    if ((cpu->b & 0x0F) == 0x0F) {
        set_flag(cpu, FLAG_H);
    } else {
        clear_flag(cpu, FLAG_H);
    }

    cpu->b = result;

    if (cpu->b == 0) {
        set_flag(cpu, FLAG_Z);
    } else {
        clear_flag(cpu, FLAG_Z);
    }

    clear_flag(cpu, FLAG_N);
}

void dec_b(Memory* mem, CPU* cpu) {
    uint8_t result = cpu->b - 1;
    
    if ((cpu->b & 0x0F) == 0x00) {
        set_flag(cpu, FLAG_H);
    } else {
        clear_flag(cpu, FLAG_H);
    }
    
    cpu->b = result;
    
    if (cpu->b == 0) {
        set_flag(cpu, FLAG_Z);
    } else {
        clear_flag(cpu, FLAG_Z);
    }
    
    set_flag(cpu, FLAG_N);
}

void ld_b_d8(Memory* mem, CPU* cpu) {
    cpu->b = read_memory_byte(mem, cpu->pc + 1);
}

void rlca(Memory* mem, CPU* cpu) {
    uint8_t carry = (cpu->a & 0x80) >> 7;
    
    cpu->a = (cpu->a << 1) | carry;
    
    clear_flag(cpu, FLAG_Z);
    clear_flag(cpu, FLAG_N);
    clear_flag(cpu, FLAG_H);
    
    if (carry) {
        set_flag(cpu, FLAG_C);
    } else {
        clear_flag(cpu, FLAG_C);
    }
}

void ld_a16_sp(Memory* mem, CPU* cpu) {
    uint8_t low = read_memory_byte(mem, cpu->pc + 1);
    uint8_t high = read_memory_byte(mem, cpu->pc + 2);
    uint16_t address = (high << 8) | low;
    
    write_memory_byte(mem, address, cpu->sp & 0xFF);
    write_memory_byte(mem, address + 1, (cpu->sp >> 8) & 0xFF);
    
}

void add_hl_bc(Memory* mem, CPU* cpu) {
    uint16_t hl = get_hl(cpu);
    uint16_t bc = get_bc(cpu);
    uint32_t result = hl + bc;
    
    clear_flag(cpu, FLAG_N);
    
    if (((hl & 0x0FFF) + (bc & 0x0FFF)) > 0x0FFF) {
        set_flag(cpu, FLAG_H);
    } else {
        clear_flag(cpu, FLAG_H);
    }
    
    if (result > 0xFFFF) {
        set_flag(cpu, FLAG_C);
    } else {
        clear_flag(cpu, FLAG_C);
    }
    
    set_hl(cpu, (uint16_t)result);
}

void ld_a_bc(Memory* mem, CPU* cpu) {
    cpu->a = read_memory_byte(mem, get_bc(cpu));
}

void dec_bc(Memory* mem, CPU* cpu) {
    uint16_t value = get_bc(cpu);
    set_bc(cpu, value - 1);
}

void inc_c(Memory* mem, CPU* cpu) {
    uint8_t result = cpu->c + 1;
    
    if ((cpu->c & 0x0F) == 0x0F) {
        set_flag(cpu, FLAG_H);
    } else {
        clear_flag(cpu, FLAG_H);
    }
    
    cpu->c = result;
    
    if (cpu->c == 0) {
        set_flag(cpu, FLAG_Z);
    } else {
        clear_flag(cpu, FLAG_Z);
    }
    
    clear_flag(cpu, FLAG_N);
}

void dec_c(Memory* mem, CPU* cpu) {
    uint8_t result = cpu->c - 1;
    
    if ((cpu->c & 0x0F) == 0x00) {
        set_flag(cpu, FLAG_H);
    } else {
        clear_flag(cpu, FLAG_H);
    }
    
    cpu->c = result;
    
    if (cpu->c == 0) {
        set_flag(cpu, FLAG_Z);
    } else {
        clear_flag(cpu, FLAG_Z);
    }
    
    set_flag(cpu, FLAG_N);
}

void ld_c_d8(Memory* mem, CPU* cpu) {
    cpu->c = read_memory_byte(mem, cpu->pc + 1);
}

void rrca(Memory* mem, CPU* cpu) {
    uint8_t carry = cpu->a & 0x01;
    
    cpu->a = (carry << 7) | (cpu->a >> 1);
    
    clear_flag(cpu, FLAG_Z);
    clear_flag(cpu, FLAG_N);
    clear_flag(cpu, FLAG_H);
    
    if (carry) {
        set_flag(cpu, FLAG_C);
    } else {
        clear_flag(cpu, FLAG_C);
    }
}