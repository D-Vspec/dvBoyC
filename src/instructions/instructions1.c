#include "instructions.h"
#include "flags.h"
#include "cpu.h"
#include "memory.h"

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

void ld_de_d16(Memory* mem, CPU* cpu) {
    uint8_t low = read_memory_byte(mem, cpu->pc + 1);
    uint8_t high = read_memory_byte(mem, cpu->pc + 2);
    set_de(cpu, (high << 8) | low);
}

void ld_de_a(Memory* mem, CPU* cpu) {
    write_memory_byte(mem, get_de(cpu), cpu->a);
}

void inc_de(Memory* mem, CPU* cpu) {
    uint16_t value = get_de(cpu);
    set_de(cpu, value + 1);
}

void inc_d(Memory* mem, CPU* cpu) {
    uint8_t result = cpu->d + 1;
    
    if ((cpu->d & 0x0F) == 0x0F) {
        set_flag(cpu, FLAG_H);
    } else {
        clear_flag(cpu, FLAG_H);
    }
    
    cpu->d = result;
    
    if (cpu->d == 0) {
        set_flag(cpu, FLAG_Z);
    } else {
        clear_flag(cpu, FLAG_Z);
    }
    
    clear_flag(cpu, FLAG_N);
}

void dec_d(Memory* mem, CPU* cpu) {
    uint8_t result = cpu->d - 1;
    
    if ((cpu->d & 0x0F) == 0x00) {
        set_flag(cpu, FLAG_H);
    } else {
        clear_flag(cpu, FLAG_H);
    }
    
    cpu->d = result;
    
    if (cpu->d == 0) {
        set_flag(cpu, FLAG_Z);
    } else {
        clear_flag(cpu, FLAG_Z);
    }
    
    set_flag(cpu, FLAG_N);
}

void ld_d_d8(Memory* mem, CPU* cpu) {
    cpu->d = read_memory_byte(mem, cpu->pc + 1);
}

void rla(Memory* mem, CPU* cpu) {
    uint8_t old_carry = (cpu->f & FLAG_C) ? 1 : 0;
    uint8_t new_carry = (cpu->a & 0x80) >> 7;
    
    cpu->a = (cpu->a << 1) | old_carry;
    
    clear_flag(cpu, FLAG_Z);
    clear_flag(cpu, FLAG_N);
    clear_flag(cpu, FLAG_H);
    
    if (new_carry) {
        set_flag(cpu, FLAG_C);
    } else {
        clear_flag(cpu, FLAG_C);
    }
}

void jr_s8(Memory* mem, CPU* cpu) {
    int8_t offset = (int8_t)read_memory_byte(mem, cpu->pc + 1);
    cpu->pc += offset;
}
