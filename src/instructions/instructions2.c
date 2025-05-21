#include "instructions.h"
#include "flags.h"
#include "cpu.h"
#include "memory.h"

// 0x19: ADD HL,DE
void add_hl_de(Memory* mem, CPU* cpu) {
    uint16_t hl = get_hl(cpu);
    uint16_t de = get_de(cpu);
    uint32_t result = hl + de;
    
    clear_flag(cpu, FLAG_N);
    
    if (((hl & 0x0FFF) + (de & 0x0FFF)) > 0x0FFF) {
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

// 0x1A: LD A,(DE)
void ld_a_de(Memory* mem, CPU* cpu) {
    cpu->a = read_memory_byte(mem, get_de(cpu));
}

// 0x1B: DEC DE
void dec_de(Memory* mem, CPU* cpu) {
    uint16_t value = get_de(cpu);
    set_de(cpu, value - 1);
}

// 0x1C: INC E
void inc_e(Memory* mem, CPU* cpu) {
    uint8_t result = cpu->e + 1;
    
    if ((cpu->e & 0x0F) == 0x0F) {
        set_flag(cpu, FLAG_H);
    } else {
        clear_flag(cpu, FLAG_H);
    }
    
    cpu->e = result;
    
    if (cpu->e == 0) {
        set_flag(cpu, FLAG_Z);
    } else {
        clear_flag(cpu, FLAG_Z);
    }
    
    clear_flag(cpu, FLAG_N);
}

// 0x1D: DEC E
void dec_e(Memory* mem, CPU* cpu) {
    uint8_t result = cpu->e - 1;
    
    if ((cpu->e & 0x0F) == 0x00) {
        set_flag(cpu, FLAG_H);
    } else {
        clear_flag(cpu, FLAG_H);
    }
    
    cpu->e = result;
    
    if (cpu->e == 0) {
        set_flag(cpu, FLAG_Z);
    } else {
        clear_flag(cpu, FLAG_Z);
    }
    
    set_flag(cpu, FLAG_N);
}

// 0x1E: LD E,d8
void ld_e_d8(Memory* mem, CPU* cpu) {
    cpu->e = read_memory_byte(mem, cpu->pc + 1);
}

// 0x1F: RRA
void rra(Memory* mem, CPU* cpu) {
    uint8_t old_carry = (cpu->f & FLAG_C) ? 1 : 0;
    uint8_t new_carry = cpu->a & 0x01;
    
    cpu->a = (old_carry << 7) | (cpu->a >> 1);
    
    clear_flag(cpu, FLAG_Z);
    clear_flag(cpu, FLAG_N);
    clear_flag(cpu, FLAG_H);
    
    if (new_carry) {
        set_flag(cpu, FLAG_C);
    } else {
        clear_flag(cpu, FLAG_C);
    }
}

// 0x20: JR NZ,s8
void jr_nz_s8(Memory* mem, CPU* cpu) {
    int8_t offset = (int8_t)read_memory_byte(mem, cpu->pc + 1);
    
    if (!(cpu->f & FLAG_Z)) {
        cpu->pc += offset;
        cpu->cycles += 4; // Add 4 cycles if branch taken
    }
}

// 0x21: LD HL,d16
void ld_hl_d16(Memory* mem, CPU* cpu) {
    uint8_t low = read_memory_byte(mem, cpu->pc + 1);
    uint8_t high = read_memory_byte(mem, cpu->pc + 2);
    set_hl(cpu, (high << 8) | low);
}

// 0x22: LD (HL+),A
void ld_hli_a(Memory* mem, CPU* cpu) {
    uint16_t addr = get_hl(cpu);
    write_memory_byte(mem, addr, cpu->a);
    set_hl(cpu, addr + 1);
}

// 0x23: INC HL
void inc_hl(Memory* mem, CPU* cpu) {
    uint16_t value = get_hl(cpu);
    set_hl(cpu, value + 1);
}

// 0x24: INC H
void inc_h(Memory* mem, CPU* cpu) {
    uint8_t result = cpu->h + 1;
    
    if ((cpu->h & 0x0F) == 0x0F) {
        set_flag(cpu, FLAG_H);
    } else {
        clear_flag(cpu, FLAG_H);
    }
    
    cpu->h = result;
    
    if (cpu->h == 0) {
        set_flag(cpu, FLAG_Z);
    } else {
        clear_flag(cpu, FLAG_Z);
    }
    
    clear_flag(cpu, FLAG_N);
}

// 0x25: DEC H
void dec_h(Memory* mem, CPU* cpu) {
    uint8_t result = cpu->h - 1;
    
    if ((cpu->h & 0x0F) == 0x00) {
        set_flag(cpu, FLAG_H);
    } else {
        clear_flag(cpu, FLAG_H);
    }
    
    cpu->h = result;
    
    if (cpu->h == 0) {
        set_flag(cpu, FLAG_Z);
    } else {
        clear_flag(cpu, FLAG_Z);
    }
    
    set_flag(cpu, FLAG_N);
}

// 0x26: LD H,d8
void ld_h_d8(Memory* mem, CPU* cpu) {
    cpu->h = read_memory_byte(mem, cpu->pc + 1);
}

// 0x27: DAA
void daa(Memory* mem, CPU* cpu) {
    uint8_t a = cpu->a;
    uint8_t correction = 0;
    
    if (cpu->f & FLAG_H || (!(cpu->f & FLAG_N) && (a & 0x0F) > 9)) {
        correction |= 0x06;
    }
    
    if (cpu->f & FLAG_C || (!(cpu->f & FLAG_N) && a > 0x99)) {
        correction |= 0x60;
        set_flag(cpu, FLAG_C);
    }
    
    if (cpu->f & FLAG_N) {
        cpu->a -= correction;
    } else {
        cpu->a += correction;
    }
    
    if (cpu->a == 0) {
        set_flag(cpu, FLAG_Z);
    } else {
        clear_flag(cpu, FLAG_Z);
    }
    
    clear_flag(cpu, FLAG_H);
}

// 0x28: JR Z,s8
void jr_z_s8(Memory* mem, CPU* cpu) {
    int8_t offset = (int8_t)read_memory_byte(mem, cpu->pc + 1);
    
    if (cpu->f & FLAG_Z) {
        cpu->pc += offset;
        cpu->cycles += 4; // Add 4 cycles if branch taken
    }
}

// 0x29: ADD HL,HL
void add_hl_hl(Memory* mem, CPU* cpu) {
    uint16_t hl = get_hl(cpu);
    uint32_t result = hl + hl;
    
    clear_flag(cpu, FLAG_N);
    
    if (((hl & 0x0FFF) + (hl & 0x0FFF)) > 0x0FFF) {
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

// 0x2A: LD A,(HL+)
void ld_a_hli(Memory* mem, CPU* cpu) {
    uint16_t addr = get_hl(cpu);
    cpu->a = read_memory_byte(mem, addr);
    set_hl(cpu, addr + 1);
}

// 0x2B: DEC HL
void dec_hl(Memory* mem, CPU* cpu) {
    uint16_t value = get_hl(cpu);
    set_hl(cpu, value - 1);
}

// 0x2C: INC L
void inc_l(Memory* mem, CPU* cpu) {
    uint8_t result = cpu->l + 1;
    
    if ((cpu->l & 0x0F) == 0x0F) {
        set_flag(cpu, FLAG_H);
    } else {
        clear_flag(cpu, FLAG_H);
    }
    
    cpu->l = result;
    
    if (cpu->l == 0) {
        set_flag(cpu, FLAG_Z);
    } else {
        clear_flag(cpu, FLAG_Z);
    }
    
    clear_flag(cpu, FLAG_N);
}

// 0x2D: DEC L
void dec_l(Memory* mem, CPU* cpu) {
    uint8_t result = cpu->l - 1;
    
    if ((cpu->l & 0x0F) == 0x00) {
        set_flag(cpu, FLAG_H);
    } else {
        clear_flag(cpu, FLAG_H);
    }
    
    cpu->l = result;
    
    if (cpu->l == 0) {
        set_flag(cpu, FLAG_Z);
    } else {
        clear_flag(cpu, FLAG_Z);
    }
    
    set_flag(cpu, FLAG_N);
}

// 0x2E: LD L,d8
void ld_l_d8(Memory* mem, CPU* cpu) {
    cpu->l = read_memory_byte(mem, cpu->pc + 1);
}

// 0x2F: CPL
void cpl(Memory* mem, CPU* cpu) {
    cpu->a = ~cpu->a;
    
    set_flag(cpu, FLAG_N);
    set_flag(cpu, FLAG_H);
}

// 0x30: JR NC,s8
void jr_nc_s8(Memory* mem, CPU* cpu) {
    int8_t offset = (int8_t)read_memory_byte(mem, cpu->pc + 1);
    
    if (!(cpu->f & FLAG_C)) {
        cpu->pc += offset;
        cpu->cycles += 4; // Add 4 cycles if branch taken
    }
}

// 0x31: LD SP,d16
void ld_sp_d16(Memory* mem, CPU* cpu) {
    uint8_t low = read_memory_byte(mem, cpu->pc + 1);
    uint8_t high = read_memory_byte(mem, cpu->pc + 2);
    cpu->sp = (high << 8) | low;
}

// 0x32: LD (HL-),A
void ld_hld_a(Memory* mem, CPU* cpu) {
    uint16_t addr = get_hl(cpu);
    write_memory_byte(mem, addr, cpu->a);
    set_hl(cpu, addr - 1);
}

// 0x33: INC SP
void inc_sp(Memory* mem, CPU* cpu) {
    cpu->sp++;
}

// 0x34: INC (HL)
void inc_hlm(Memory* mem, CPU* cpu) {
    uint16_t addr = get_hl(cpu);
    uint8_t value = read_memory_byte(mem, addr);
    uint8_t result = value + 1;
    
    if ((value & 0x0F) == 0x0F) {
        set_flag(cpu, FLAG_H);
    } else {
        clear_flag(cpu, FLAG_H);
    }
    
    write_memory_byte(mem, addr, result);
    
    if (result == 0) {
        set_flag(cpu, FLAG_Z);
    } else {
        clear_flag(cpu, FLAG_Z);
    }
    
    clear_flag(cpu, FLAG_N);
}

// 0x35: DEC (HL)
void dec_hlm(Memory* mem, CPU* cpu) {
    uint16_t addr = get_hl(cpu);
    uint8_t value = read_memory_byte(mem, addr);
    uint8_t result = value - 1;
    
    if ((value & 0x0F) == 0x00) {
        set_flag(cpu, FLAG_H);
    } else {
        clear_flag(cpu, FLAG_H);
    }
    
    write_memory_byte(mem, addr, result);
    
    if (result == 0) {
        set_flag(cpu, FLAG_Z);
    } else {
        clear_flag(cpu, FLAG_Z);
    }
    
    set_flag(cpu, FLAG_N);
}

// 0x36: LD (HL),d8
void ld_hl_d8(Memory* mem, CPU* cpu) {
    uint8_t value = read_memory_byte(mem, cpu->pc + 1);
    write_memory_byte(mem, get_hl(cpu), value);
}

// 0x37: SCF
void scf(Memory* mem, CPU* cpu) {
    clear_flag(cpu, FLAG_N);
    clear_flag(cpu, FLAG_H);
    set_flag(cpu, FLAG_C);
}

// 0x38: JR C,s8
void jr_c_s8(Memory* mem, CPU* cpu) {
    int8_t offset = (int8_t)read_memory_byte(mem, cpu->pc + 1);
    
    if (cpu->f & FLAG_C) {
        cpu->pc += offset;
        cpu->cycles += 4; // Add 4 cycles if branch taken
    }
}

// 0x39: ADD HL,SP
void add_hl_sp(Memory* mem, CPU* cpu) {
    uint16_t hl = get_hl(cpu);
    uint16_t sp = cpu->sp;
    uint32_t result = hl + sp;
    
    clear_flag(cpu, FLAG_N);
    
    if (((hl & 0x0FFF) + (sp & 0x0FFF)) > 0x0FFF) {
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

// 0x3A: LD A,(HL-)
void ld_a_hld(Memory* mem, CPU* cpu) {
    uint16_t addr = get_hl(cpu);
    cpu->a = read_memory_byte(mem, addr);
    set_hl(cpu, addr - 1);
}

// 0x3B: DEC SP
void dec_sp(Memory* mem, CPU* cpu) {
    cpu->sp--;
}

// 0x3C: INC A
void inc_a(Memory* mem, CPU* cpu) {
    uint8_t result = cpu->a + 1;
    
    if ((cpu->a & 0x0F) == 0x0F) {
        set_flag(cpu, FLAG_H);
    } else {
        clear_flag(cpu, FLAG_H);
    }
    
    cpu->a = result;
    
    if (cpu->a == 0) {
        set_flag(cpu, FLAG_Z);
    } else {
        clear_flag(cpu, FLAG_Z);
    }
    
    clear_flag(cpu, FLAG_N);
}

// 0x3D: DEC A
void dec_a(Memory* mem, CPU* cpu) {
    uint8_t result = cpu->a - 1;
    
    if ((cpu->a & 0x0F) == 0x00) {
        set_flag(cpu, FLAG_H);
    } else {
        clear_flag(cpu, FLAG_H);
    }
    
    cpu->a = result;
    
    if (cpu->a == 0) {
        set_flag(cpu, FLAG_Z);
    } else {
        clear_flag(cpu, FLAG_Z);
    }
    
    set_flag(cpu, FLAG_N);
}

// 0x3E: LD A,d8
void ld_a_d8(Memory* mem, CPU* cpu) {
    cpu->a = read_memory_byte(mem, cpu->pc + 1);
}

// 0x3F: CCF
void ccf(Memory* mem, CPU* cpu) {
    clear_flag(cpu, FLAG_N);
    clear_flag(cpu, FLAG_H);
    
    if (cpu->f & FLAG_C) {
        clear_flag(cpu, FLAG_C);
    } else {
        set_flag(cpu, FLAG_C);
    }
}
