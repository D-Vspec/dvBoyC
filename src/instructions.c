#include "instructions.h"
#include "flags.h"
#include "memory.h"
#include <stdio.h>

Opcode opcode_table[256];

void init_opcode_table(void) {
    printf("Initializing opcode table...\n");

    // Existing opcodes (0x00-0x18)
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
    // STOP instruction (0x10) is skipped
    opcode_table[0x11] = (Opcode){ ld_de_d16, 3, 12, "LD DE,d16" };
    opcode_table[0x12] = (Opcode){ ld_de_a, 1, 8, "LD (DE),A" };
    opcode_table[0x13] = (Opcode){ inc_de, 1, 8, "INC DE" };
    opcode_table[0x14] = (Opcode){ inc_d, 1, 4, "INC D" };
    opcode_table[0x15] = (Opcode){ dec_d, 1, 4, "DEC D" };
    opcode_table[0x16] = (Opcode){ ld_d_d8, 2, 8, "LD D,d8" };
    opcode_table[0x17] = (Opcode){ rla, 1, 4, "RLA" };
    opcode_table[0x18] = (Opcode){ jr_s8, 2, 12, "JR s8" };

    // New opcodes (0x19-0x7E, skipping 0x76 HALT)
    opcode_table[0x19] = (Opcode){ add_hl_de, 1, 8, "ADD HL,DE" };
    opcode_table[0x1A] = (Opcode){ ld_a_de, 1, 8, "LD A,(DE)" };
    opcode_table[0x1B] = (Opcode){ dec_de, 1, 8, "DEC DE" };
    opcode_table[0x1C] = (Opcode){ inc_e, 1, 4, "INC E" };
    opcode_table[0x1D] = (Opcode){ dec_e, 1, 4, "DEC E" };
    opcode_table[0x1E] = (Opcode){ ld_e_d8, 2, 8, "LD E,d8" };
    opcode_table[0x1F] = (Opcode){ rra, 1, 4, "RRA" };
    opcode_table[0x20] = (Opcode){ jr_nz_s8, 2, 8, "JR NZ,s8" }; // 8/12 cycles
    opcode_table[0x21] = (Opcode){ ld_hl_d16, 3, 12, "LD HL,d16" };
    opcode_table[0x22] = (Opcode){ ld_hli_a, 1, 8, "LD (HL+),A" };
    opcode_table[0x23] = (Opcode){ inc_hl, 1, 8, "INC HL" };
    opcode_table[0x24] = (Opcode){ inc_h, 1, 4, "INC H" };
    opcode_table[0x25] = (Opcode){ dec_h, 1, 4, "DEC H" };
    opcode_table[0x26] = (Opcode){ ld_h_d8, 2, 8, "LD H,d8" };
    opcode_table[0x27] = (Opcode){ daa, 1, 4, "DAA" };
    opcode_table[0x28] = (Opcode){ jr_z_s8, 2, 8, "JR Z,s8" }; // 8/12 cycles
    opcode_table[0x29] = (Opcode){ add_hl_hl, 1, 8, "ADD HL,HL" };
    opcode_table[0x2A] = (Opcode){ ld_a_hli, 1, 8, "LD A,(HL+)" };
    opcode_table[0x2B] = (Opcode){ dec_hl, 1, 8, "DEC HL" };
    opcode_table[0x2C] = (Opcode){ inc_l, 1, 4, "INC L" };
    opcode_table[0x2D] = (Opcode){ dec_l, 1, 4, "DEC L" };
    opcode_table[0x2E] = (Opcode){ ld_l_d8, 2, 8, "LD L,d8" };
    opcode_table[0x2F] = (Opcode){ cpl, 1, 4, "CPL" };
    opcode_table[0x30] = (Opcode){ jr_nc_s8, 2, 8, "JR NC,s8" }; // 8/12 cycles
    opcode_table[0x31] = (Opcode){ ld_sp_d16, 3, 12, "LD SP,d16" };
    opcode_table[0x32] = (Opcode){ ld_hld_a, 1, 8, "LD (HL-),A" };
    opcode_table[0x33] = (Opcode){ inc_sp, 1, 8, "INC SP" };
    opcode_table[0x34] = (Opcode){ inc_hlm, 1, 12, "INC (HL)" };
    opcode_table[0x35] = (Opcode){ dec_hlm, 1, 12, "DEC (HL)" };
    opcode_table[0x36] = (Opcode){ ld_hl_d8, 2, 12, "LD (HL),d8" };
    opcode_table[0x37] = (Opcode){ scf, 1, 4, "SCF" };
    opcode_table[0x38] = (Opcode){ jr_c_s8, 2, 8, "JR C,s8" }; // 8/12 cycles
    opcode_table[0x39] = (Opcode){ add_hl_sp, 1, 8, "ADD HL,SP" };
    opcode_table[0x3A] = (Opcode){ ld_a_hld, 1, 8, "LD A,(HL-)" };
    opcode_table[0x3B] = (Opcode){ dec_sp, 1, 8, "DEC SP" };
    opcode_table[0x3C] = (Opcode){ inc_a, 1, 4, "INC A" };
    opcode_table[0x3D] = (Opcode){ dec_a, 1, 4, "DEC A" };
    opcode_table[0x3E] = (Opcode){ ld_a_d8, 2, 8, "LD A,d8" };
    opcode_table[0x3F] = (Opcode){ ccf, 1, 4, "CCF" };
    
    // Register-to-register load instructions (0x40-0x7F)
    opcode_table[0x40] = (Opcode){ ld_b_b, 1, 4, "LD B,B" };
    opcode_table[0x41] = (Opcode){ ld_b_c, 1, 4, "LD B,C" };
    opcode_table[0x42] = (Opcode){ ld_b_d, 1, 4, "LD B,D" };
    opcode_table[0x43] = (Opcode){ ld_b_e, 1, 4, "LD B,E" };
    opcode_table[0x44] = (Opcode){ ld_b_h, 1, 4, "LD B,H" };
    opcode_table[0x45] = (Opcode){ ld_b_l, 1, 4, "LD B,L" };
    opcode_table[0x46] = (Opcode){ ld_b_hl, 1, 8, "LD B,(HL)" };
    opcode_table[0x47] = (Opcode){ ld_b_a, 1, 4, "LD B,A" };
    opcode_table[0x48] = (Opcode){ ld_c_b, 1, 4, "LD C,B" };
    opcode_table[0x49] = (Opcode){ ld_c_c, 1, 4, "LD C,C" };
    opcode_table[0x4A] = (Opcode){ ld_c_d, 1, 4, "LD C,D" };
    opcode_table[0x4B] = (Opcode){ ld_c_e, 1, 4, "LD C,E" };
    opcode_table[0x4C] = (Opcode){ ld_c_h, 1, 4, "LD C,H" };
    opcode_table[0x4D] = (Opcode){ ld_c_l, 1, 4, "LD C,L" };
    opcode_table[0x4E] = (Opcode){ ld_c_hl, 1, 8, "LD C,(HL)" };
    opcode_table[0x4F] = (Opcode){ ld_c_a, 1, 4, "LD C,A" };
    opcode_table[0x50] = (Opcode){ ld_d_b, 1, 4, "LD D,B" };
    opcode_table[0x51] = (Opcode){ ld_d_c, 1, 4, "LD D,C" };
    opcode_table[0x52] = (Opcode){ ld_d_d, 1, 4, "LD D,D" };
    opcode_table[0x53] = (Opcode){ ld_d_e, 1, 4, "LD D,E" };
    opcode_table[0x54] = (Opcode){ ld_d_h, 1, 4, "LD D,H" };
    opcode_table[0x55] = (Opcode){ ld_d_l, 1, 4, "LD D,L" };
    opcode_table[0x56] = (Opcode){ ld_d_hl, 1, 8, "LD D,(HL)" };
    opcode_table[0x57] = (Opcode){ ld_d_a, 1, 4, "LD D,A" };
    opcode_table[0x58] = (Opcode){ ld_e_b, 1, 4, "LD E,B" };
    opcode_table[0x59] = (Opcode){ ld_e_c, 1, 4, "LD E,C" };
    opcode_table[0x5A] = (Opcode){ ld_e_d, 1, 4, "LD E,D" };
    opcode_table[0x5B] = (Opcode){ ld_e_e, 1, 4, "LD E,E" };
    opcode_table[0x5C] = (Opcode){ ld_e_h, 1, 4, "LD E,H" };
    opcode_table[0x5D] = (Opcode){ ld_e_l, 1, 4, "LD E,L" };
    opcode_table[0x5E] = (Opcode){ ld_e_hl, 1, 8, "LD E,(HL)" };
    opcode_table[0x5F] = (Opcode){ ld_e_a, 1, 4, "LD E,A" };
    opcode_table[0x60] = (Opcode){ ld_h_b, 1, 4, "LD H,B" };
    opcode_table[0x61] = (Opcode){ ld_h_c, 1, 4, "LD H,C" };
    opcode_table[0x62] = (Opcode){ ld_h_d, 1, 4, "LD H,D" };
    opcode_table[0x63] = (Opcode){ ld_h_e, 1, 4, "LD H,E" };
    opcode_table[0x64] = (Opcode){ ld_h_h, 1, 4, "LD H,H" };
    opcode_table[0x65] = (Opcode){ ld_h_l, 1, 4, "LD H,L" };
    opcode_table[0x66] = (Opcode){ ld_h_hl, 1, 8, "LD H,(HL)" };
    opcode_table[0x67] = (Opcode){ ld_h_a, 1, 4, "LD H,A" };
    opcode_table[0x68] = (Opcode){ ld_l_b, 1, 4, "LD L,B" };
    opcode_table[0x69] = (Opcode){ ld_l_c, 1, 4, "LD L,C" };
    opcode_table[0x6A] = (Opcode){ ld_l_d, 1, 4, "LD L,D" };
    opcode_table[0x6B] = (Opcode){ ld_l_e, 1, 4, "LD L,E" };
    opcode_table[0x6C] = (Opcode){ ld_l_h, 1, 4, "LD L,H" };
    opcode_table[0x6D] = (Opcode){ ld_l_l, 1, 4, "LD L,L" };
    opcode_table[0x6E] = (Opcode){ ld_l_hl, 1, 8, "LD L,(HL)" };
    opcode_table[0x6F] = (Opcode){ ld_l_a, 1, 4, "LD L,A" };
    opcode_table[0x70] = (Opcode){ ld_hl_b, 1, 8, "LD (HL),B" };
    opcode_table[0x71] = (Opcode){ ld_hl_c, 1, 8, "LD (HL),C" };
    opcode_table[0x72] = (Opcode){ ld_hl_d, 1, 8, "LD (HL),D" };
    opcode_table[0x73] = (Opcode){ ld_hl_e, 1, 8, "LD (HL),E" };
    opcode_table[0x74] = (Opcode){ ld_hl_h, 1, 8, "LD (HL),H" };
    opcode_table[0x75] = (Opcode){ ld_hl_l, 1, 8, "LD (HL),L" };
    // 0x76 HALT is skipped
    opcode_table[0x77] = (Opcode){ ld_hl_a, 1, 8, "LD (HL),A" };
    opcode_table[0x78] = (Opcode){ ld_a_b, 1, 4, "LD A,B" };
    opcode_table[0x79] = (Opcode){ ld_a_c, 1, 4, "LD A,C" };
    opcode_table[0x7A] = (Opcode){ ld_a_d, 1, 4, "LD A,D" };
    opcode_table[0x7B] = (Opcode){ ld_a_e, 1, 4, "LD A,E" };
    opcode_table[0x7C] = (Opcode){ ld_a_h, 1, 4, "LD A,H" };
    opcode_table[0x7D] = (Opcode){ ld_a_l, 1, 4, "LD A,L" };
    opcode_table[0x7E] = (Opcode){ ld_a_hl, 1, 8, "LD A,(HL)" };
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

// Register-to-register load instructions (0x40-0x7F)
// 0x40: LD B,B
void ld_b_b(Memory* mem, CPU* cpu) {
    // No operation needed since B is loaded with its own value
}

// 0x41: LD B,C
void ld_b_c(Memory* mem, CPU* cpu) {
    cpu->b = cpu->c;
}

// 0x42: LD B,D
void ld_b_d(Memory* mem, CPU* cpu) {
    cpu->b = cpu->d;
}

// 0x43: LD B,E
void ld_b_e(Memory* mem, CPU* cpu) {
    cpu->b = cpu->e;
}

// 0x44: LD B,H
void ld_b_h(Memory* mem, CPU* cpu) {
    cpu->b = cpu->h;
}

// 0x45: LD B,L
void ld_b_l(Memory* mem, CPU* cpu) {
    cpu->b = cpu->l;
}

// 0x46: LD B,(HL)
void ld_b_hl(Memory* mem, CPU* cpu) {
    cpu->b = read_memory_byte(mem, get_hl(cpu));
}

// 0x47: LD B,A
void ld_b_a(Memory* mem, CPU* cpu) {
    cpu->b = cpu->a;
}

// 0x48: LD C,B
void ld_c_b(Memory* mem, CPU* cpu) {
    cpu->c = cpu->b;
}

// 0x49: LD C,C
void ld_c_c(Memory* mem, CPU* cpu) {
    // No operation needed since C is loaded with its own value
}

// 0x4A: LD C,D
void ld_c_d(Memory* mem, CPU* cpu) {
    cpu->c = cpu->d;
}

// 0x4B: LD C,E
void ld_c_e(Memory* mem, CPU* cpu) {
    cpu->c = cpu->e;
}

// 0x4C: LD C,H
void ld_c_h(Memory* mem, CPU* cpu) {
    cpu->c = cpu->h;
}

// 0x4D: LD C,L
void ld_c_l(Memory* mem, CPU* cpu) {
    cpu->c = cpu->l;
}

// 0x4E: LD C,(HL)
void ld_c_hl(Memory* mem, CPU* cpu) {
    cpu->c = read_memory_byte(mem, get_hl(cpu));
}

// 0x4F: LD C,A
void ld_c_a(Memory* mem, CPU* cpu) {
    cpu->c = cpu->a;
}

// 0x50: LD D,B
void ld_d_b(Memory* mem, CPU* cpu) {
    cpu->d = cpu->b;
}

// 0x51: LD D,C
void ld_d_c(Memory* mem, CPU* cpu) {
    cpu->d = cpu->c;
}

// 0x52: LD D,D
void ld_d_d(Memory* mem, CPU* cpu) {
    // No operation needed since D is loaded with its own value
}

// 0x53: LD D,E
void ld_d_e(Memory* mem, CPU* cpu) {
    cpu->d = cpu->e;
}

// 0x54: LD D,H
void ld_d_h(Memory* mem, CPU* cpu) {
    cpu->d = cpu->h;
}

// 0x55: LD D,L
void ld_d_l(Memory* mem, CPU* cpu) {
    cpu->d = cpu->l;
}

// 0x56: LD D,(HL)
void ld_d_hl(Memory* mem, CPU* cpu) {
    cpu->d = read_memory_byte(mem, get_hl(cpu));
}

// 0x57: LD D,A
void ld_d_a(Memory* mem, CPU* cpu) {
    cpu->d = cpu->a;
}

// 0x58: LD E,B
void ld_e_b(Memory* mem, CPU* cpu) {
    cpu->e = cpu->b;
}

// 0x59: LD E,C
void ld_e_c(Memory* mem, CPU* cpu) {
    cpu->e = cpu->c;
}

// 0x5A: LD E,D
void ld_e_d(Memory* mem, CPU* cpu) {
    cpu->e = cpu->d;
}

// 0x5B: LD E,E
void ld_e_e(Memory* mem, CPU* cpu) {
    // No operation needed since E is loaded with its own value
}

// 0x5C: LD E,H
void ld_e_h(Memory* mem, CPU* cpu) {
    cpu->e = cpu->h;
}

// 0x5D: LD E,L
void ld_e_l(Memory* mem, CPU* cpu) {
    cpu->e = cpu->l;
}

// 0x5E: LD E,(HL)
void ld_e_hl(Memory* mem, CPU* cpu) {
    cpu->e = read_memory_byte(mem, get_hl(cpu));
}

// 0x5F: LD E,A
void ld_e_a(Memory* mem, CPU* cpu) {
    cpu->e = cpu->a;
}

// 0x60: LD H,B
void ld_h_b(Memory* mem, CPU* cpu) {
    cpu->h = cpu->b;
}

// 0x61: LD H,C
void ld_h_c(Memory* mem, CPU* cpu) {
    cpu->h = cpu->c;
}

// 0x62: LD H,D
void ld_h_d(Memory* mem, CPU* cpu) {
    cpu->h = cpu->d;
}

// 0x63: LD H,E
void ld_h_e(Memory* mem, CPU* cpu) {
    cpu->h = cpu->e;
}

// 0x64: LD H,H
void ld_h_h(Memory* mem, CPU* cpu) {
    // No operation needed since H is loaded with its own value
}

// 0x65: LD H,L
void ld_h_l(Memory* mem, CPU* cpu) {
    cpu->h = cpu->l;
}

// 0x66: LD H,(HL)
void ld_h_hl(Memory* mem, CPU* cpu) {
    cpu->h = read_memory_byte(mem, get_hl(cpu));
}

// 0x67: LD H,A
void ld_h_a(Memory* mem, CPU* cpu) {
    cpu->h = cpu->a;
}

// 0x68: LD L,B
void ld_l_b(Memory* mem, CPU* cpu) {
    cpu->l = cpu->b;
}

// 0x69: LD L,C
void ld_l_c(Memory* mem, CPU* cpu) {
    cpu->l = cpu->c;
}

// 0x6A: LD L,D
void ld_l_d(Memory* mem, CPU* cpu) {
    cpu->l = cpu->d;
}

// 0x6B: LD L,E
void ld_l_e(Memory* mem, CPU* cpu) {
    cpu->l = cpu->e;
}

// 0x6C: LD L,H
void ld_l_h(Memory* mem, CPU* cpu) {
    cpu->l = cpu->h;
}

// 0x6D: LD L,L
void ld_l_l(Memory* mem, CPU* cpu) {
    // No operation needed since L is loaded with its own value
}

// 0x6E: LD L,(HL)
void ld_l_hl(Memory* mem, CPU* cpu) {
    cpu->l = read_memory_byte(mem, get_hl(cpu));
}

// 0x6F: LD L,A
void ld_l_a(Memory* mem, CPU* cpu) {
    cpu->l = cpu->a;
}

// 0x70: LD (HL),B
void ld_hl_b(Memory* mem, CPU* cpu) {
    write_memory_byte(mem, get_hl(cpu), cpu->b);
}

// 0x71: LD (HL),C
void ld_hl_c(Memory* mem, CPU* cpu) {
    write_memory_byte(mem, get_hl(cpu), cpu->c);
}

// 0x72: LD (HL),D
void ld_hl_d(Memory* mem, CPU* cpu) {
    write_memory_byte(mem, get_hl(cpu), cpu->d);
}

// 0x73: LD (HL),E
void ld_hl_e(Memory* mem, CPU* cpu) {
    write_memory_byte(mem, get_hl(cpu), cpu->e);
}

// 0x74: LD (HL),H
void ld_hl_h(Memory* mem, CPU* cpu) {
    write_memory_byte(mem, get_hl(cpu), cpu->h);
}

// 0x75: LD (HL),L
void ld_hl_l(Memory* mem, CPU* cpu) {
    write_memory_byte(mem, get_hl(cpu), cpu->l);
}

// // 0x76: HALT
// void halt(Memory* mem, CPU* cpu) {
//     cpu->halted = 1;
// }

// 0x77: LD (HL),A
void ld_hl_a(Memory* mem, CPU* cpu) {
    write_memory_byte(mem, get_hl(cpu), cpu->a);
}

// 0x78: LD A,B
void ld_a_b(Memory* mem, CPU* cpu) {
    cpu->a = cpu->b;
}

// 0x79: LD A,C
void ld_a_c(Memory* mem, CPU* cpu) {
    cpu->a = cpu->c;
}

// 0x7A: LD A,D
void ld_a_d(Memory* mem, CPU* cpu) {
    cpu->a = cpu->d;
}

// 0x7B: LD A,E
void ld_a_e(Memory* mem, CPU* cpu) {
    cpu->a = cpu->e;
}

// 0x7C: LD A,H
void ld_a_h(Memory* mem, CPU* cpu) {
    cpu->a = cpu->h;
}

// 0x7D: LD A,L
void ld_a_l(Memory* mem, CPU* cpu) {
    cpu->a = cpu->l;
}

// 0x7E: LD A,(HL)
void ld_a_hl(Memory* mem, CPU* cpu) {
    cpu->a = read_memory_byte(mem, get_hl(cpu));
}

// 0x7F: LD A,A
void ld_a_a(Memory* mem, CPU* cpu) {
    // No operation needed since A is loaded with its own value
}