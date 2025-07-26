#include "instructionsCBList.h"
#include "instructions.h"
#include <stdio.h>

Opcode cb_opcode_table[256];

void init_cb_opcode_table(void) {
    printf("Initializing CB opcode table...\n");

    // 0x00-0x07: RLC r
    cb_opcode_table[0x00] = (Opcode){ cb_rlc_b, 2, 8, "RLC B" };
    cb_opcode_table[0x01] = (Opcode){ cb_rlc_c, 2, 8, "RLC C" };
    cb_opcode_table[0x02] = (Opcode){ cb_rlc_d, 2, 8, "RLC D" };
    cb_opcode_table[0x03] = (Opcode){ cb_rlc_e, 2, 8, "RLC E" };
    cb_opcode_table[0x04] = (Opcode){ cb_rlc_h, 2, 8, "RLC H" };
    cb_opcode_table[0x05] = (Opcode){ cb_rlc_l, 2, 8, "RLC L" };
    cb_opcode_table[0x06] = (Opcode){ cb_rlc_hlm, 2, 16, "RLC (HL)" };
    cb_opcode_table[0x07] = (Opcode){ cb_rlc_a, 2, 8, "RLC A" };
    // 0x08-0x0F: RRC r
    cb_opcode_table[0x08] = (Opcode){ cb_rrc_b, 2, 8, "RRC B" };
    cb_opcode_table[0x09] = (Opcode){ cb_rrc_c, 2, 8, "RRC C" };
    cb_opcode_table[0x0A] = (Opcode){ cb_rrc_d, 2, 8, "RRC D" };
    cb_opcode_table[0x0B] = (Opcode){ cb_rrc_e, 2, 8, "RRC E" };
    cb_opcode_table[0x0C] = (Opcode){ cb_rrc_h, 2, 8, "RRC H" };
    cb_opcode_table[0x0D] = (Opcode){ cb_rrc_l, 2, 8, "RRC L" };
    cb_opcode_table[0x0E] = (Opcode){ cb_rrc_hlm, 2, 16, "RRC (HL)" };
    cb_opcode_table[0x0F] = (Opcode){ cb_rrc_a, 2, 8, "RRC A" };
    // 0x10-0x17: RL r
    cb_opcode_table[0x10] = (Opcode){ cb_rl_b, 2, 8, "RL B" };
    cb_opcode_table[0x11] = (Opcode){ cb_rl_c, 2, 8, "RL C" };
    cb_opcode_table[0x12] = (Opcode){ cb_rl_d, 2, 8, "RL D" };
    cb_opcode_table[0x13] = (Opcode){ cb_rl_e, 2, 8, "RL E" };
    cb_opcode_table[0x14] = (Opcode){ cb_rl_h, 2, 8, "RL H" };
    cb_opcode_table[0x15] = (Opcode){ cb_rl_l, 2, 8, "RL L" };
    cb_opcode_table[0x16] = (Opcode){ cb_rl_hlm, 2, 16, "RL (HL)" };
    cb_opcode_table[0x17] = (Opcode){ cb_rl_a, 2, 8, "RL A" };
    // 0x18-0x1F: RR r
    cb_opcode_table[0x18] = (Opcode){ cb_rr_b, 2, 8, "RR B" };
    cb_opcode_table[0x19] = (Opcode){ cb_rr_c, 2, 8, "RR C" };
    cb_opcode_table[0x1A] = (Opcode){ cb_rr_d, 2, 8, "RR D" };
    cb_opcode_table[0x1B] = (Opcode){ cb_rr_e, 2, 8, "RR E" };
    cb_opcode_table[0x1C] = (Opcode){ cb_rr_h, 2, 8, "RR H" };
    cb_opcode_table[0x1D] = (Opcode){ cb_rr_l, 2, 8, "RR L" };
    cb_opcode_table[0x1E] = (Opcode){ cb_rr_hlm, 2, 16, "RR (HL)" };
    cb_opcode_table[0x1F] = (Opcode){ cb_rr_a, 2, 8, "RR A" };
    // 0x20-0x27: SLA r
    cb_opcode_table[0x20] = (Opcode){ cb_sla_b, 2, 8, "SLA B" };
    cb_opcode_table[0x21] = (Opcode){ cb_sla_c, 2, 8, "SLA C" };
    cb_opcode_table[0x22] = (Opcode){ cb_sla_d, 2, 8, "SLA D" };
    cb_opcode_table[0x23] = (Opcode){ cb_sla_e, 2, 8, "SLA E" };
    cb_opcode_table[0x24] = (Opcode){ cb_sla_h, 2, 8, "SLA H" };
    cb_opcode_table[0x25] = (Opcode){ cb_sla_l, 2, 8, "SLA L" };
    cb_opcode_table[0x26] = (Opcode){ cb_sla_hlm, 2, 16, "SLA (HL)" };
    cb_opcode_table[0x27] = (Opcode){ cb_sla_a, 2, 8, "SLA A" };
    // 0x28-0x2F: SRA r
    cb_opcode_table[0x28] = (Opcode){ cb_sra_b, 2, 8, "SRA B" };
    cb_opcode_table[0x29] = (Opcode){ cb_sra_c, 2, 8, "SRA C" };
    cb_opcode_table[0x2A] = (Opcode){ cb_sra_d, 2, 8, "SRA D" };
    cb_opcode_table[0x2B] = (Opcode){ cb_sra_e, 2, 8, "SRA E" };
    cb_opcode_table[0x2C] = (Opcode){ cb_sra_h, 2, 8, "SRA H" };
    cb_opcode_table[0x2D] = (Opcode){ cb_sra_l, 2, 8, "SRA L" };
    cb_opcode_table[0x2E] = (Opcode){ cb_sra_hlm, 2, 16, "SRA (HL)" };
    cb_opcode_table[0x2F] = (Opcode){ cb_sra_a, 2, 8, "SRA A" };
    // 0x30-0x37: SWAP r
    cb_opcode_table[0x30] = (Opcode){ cb_swap_b, 2, 8, "SWAP B" };
    cb_opcode_table[0x31] = (Opcode){ cb_swap_c, 2, 8, "SWAP C" };
    cb_opcode_table[0x32] = (Opcode){ cb_swap_d, 2, 8, "SWAP D" };
    cb_opcode_table[0x33] = (Opcode){ cb_swap_e, 2, 8, "SWAP E" };
    cb_opcode_table[0x34] = (Opcode){ cb_swap_h, 2, 8, "SWAP H" };
    cb_opcode_table[0x35] = (Opcode){ cb_swap_l, 2, 8, "SWAP L" };
    cb_opcode_table[0x36] = (Opcode){ cb_swap_hlm, 2, 16, "SWAP (HL)" };
    cb_opcode_table[0x37] = (Opcode){ cb_swap_a, 2, 8, "SWAP A" };
    // 0x38-0x3F: SRL r
    cb_opcode_table[0x38] = (Opcode){ cb_srl_b, 2, 8, "SRL B" };
    cb_opcode_table[0x39] = (Opcode){ cb_srl_c, 2, 8, "SRL C" };
    cb_opcode_table[0x3A] = (Opcode){ cb_srl_d, 2, 8, "SRL D" };
    cb_opcode_table[0x3B] = (Opcode){ cb_srl_e, 2, 8, "SRL E" };
    cb_opcode_table[0x3C] = (Opcode){ cb_srl_h, 2, 8, "SRL H" };
    cb_opcode_table[0x3D] = (Opcode){ cb_srl_l, 2, 8, "SRL L" };
    cb_opcode_table[0x3E] = (Opcode){ cb_srl_hlm, 2, 16, "SRL (HL)" };
    cb_opcode_table[0x3F] = (Opcode){ cb_srl_a, 2, 8, "SRL A" };
    // 0x40-0x47: BIT 0,r
    cb_opcode_table[0x40] = (Opcode){ cb_bit_0_b, 2, 8, "BIT 0,B" };
    cb_opcode_table[0x41] = (Opcode){ cb_bit_0_c, 2, 8, "BIT 0,C" };
    cb_opcode_table[0x42] = (Opcode){ cb_bit_0_d, 2, 8, "BIT 0,D" };
    cb_opcode_table[0x43] = (Opcode){ cb_bit_0_e, 2, 8, "BIT 0,E" };
    cb_opcode_table[0x44] = (Opcode){ cb_bit_0_h, 2, 8, "BIT 0,H" };
    cb_opcode_table[0x45] = (Opcode){ cb_bit_0_l, 2, 8, "BIT 0,L" };
    cb_opcode_table[0x46] = (Opcode){ cb_bit_0_hlm, 2, 16, "BIT 0,(HL)" };
    cb_opcode_table[0x47] = (Opcode){ cb_bit_0_a, 2, 8, "BIT 0,A" };
    // 0x48-0x4F: BIT 1,r
    cb_opcode_table[0x48] = (Opcode){ cb_bit_1_b, 2, 8, "BIT 1,B" };
    cb_opcode_table[0x49] = (Opcode){ cb_bit_1_c, 2, 8, "BIT 1,C" };
    cb_opcode_table[0x4A] = (Opcode){ cb_bit_1_d, 2, 8, "BIT 1,D" };
    cb_opcode_table[0x4B] = (Opcode){ cb_bit_1_e, 2, 8, "BIT 1,E" };
    cb_opcode_table[0x4C] = (Opcode){ cb_bit_1_h, 2, 8, "BIT 1,H" };
    cb_opcode_table[0x4D] = (Opcode){ cb_bit_1_l, 2, 8, "BIT 1,L" };
    cb_opcode_table[0x4E] = (Opcode){ cb_bit_1_hlm, 2, 16, "BIT 1,(HL)" };
    cb_opcode_table[0x4F] = (Opcode){ cb_bit_1_a, 2, 8, "BIT 1,A" };
    // 0x50-0x57: BIT 2,r
    cb_opcode_table[0x50] = (Opcode){ cb_bit_2_b, 2, 8, "BIT 2,B" };
    cb_opcode_table[0x51] = (Opcode){ cb_bit_2_c, 2, 8, "BIT 2,C" };
    cb_opcode_table[0x52] = (Opcode){ cb_bit_2_d, 2, 8, "BIT 2,D" };
    cb_opcode_table[0x53] = (Opcode){ cb_bit_2_e, 2, 8, "BIT 2,E" };
    cb_opcode_table[0x54] = (Opcode){ cb_bit_2_h, 2, 8, "BIT 2,H" };
    cb_opcode_table[0x55] = (Opcode){ cb_bit_2_l, 2, 8, "BIT 2,L" };
    cb_opcode_table[0x56] = (Opcode){ cb_bit_2_hlm, 2, 16, "BIT 2,(HL)" };
    cb_opcode_table[0x57] = (Opcode){ cb_bit_2_a, 2, 8, "BIT 2,A" };
    // 0x58-0x5F: BIT 3,r
    cb_opcode_table[0x58] = (Opcode){ cb_bit_3_b, 2, 8, "BIT 3,B" };
    cb_opcode_table[0x59] = (Opcode){ cb_bit_3_c, 2, 8, "BIT 3,C" };
    cb_opcode_table[0x5A] = (Opcode){ cb_bit_3_d, 2, 8, "BIT 3,D" };
    cb_opcode_table[0x5B] = (Opcode){ cb_bit_3_e, 2, 8, "BIT 3,E" };
    cb_opcode_table[0x5C] = (Opcode){ cb_bit_3_h, 2, 8, "BIT 3,H" };
    cb_opcode_table[0x5D] = (Opcode){ cb_bit_3_l, 2, 8, "BIT 3,L" };
    cb_opcode_table[0x5E] = (Opcode){ cb_bit_3_hlm, 2, 16, "BIT 3,(HL)" };
    cb_opcode_table[0x5F] = (Opcode){ cb_bit_3_a, 2, 8, "BIT 3,A" };
    // 0x60-0x67: BIT 4,r
    cb_opcode_table[0x60] = (Opcode){ cb_bit_4_b, 2, 8, "BIT 4,B" };
    cb_opcode_table[0x61] = (Opcode){ cb_bit_4_c, 2, 8, "BIT 4,C" };
    cb_opcode_table[0x62] = (Opcode){ cb_bit_4_d, 2, 8, "BIT 4,D" };
    cb_opcode_table[0x63] = (Opcode){ cb_bit_4_e, 2, 8, "BIT 4,E" };
    cb_opcode_table[0x64] = (Opcode){ cb_bit_4_h, 2, 8, "BIT 4,H" };
    cb_opcode_table[0x65] = (Opcode){ cb_bit_4_l, 2, 8, "BIT 4,L" };
    cb_opcode_table[0x66] = (Opcode){ cb_bit_4_hlm, 2, 16, "BIT 4,(HL)" };
    cb_opcode_table[0x67] = (Opcode){ cb_bit_4_a, 2, 8, "BIT 4,A" };
    // 0x68-0x6F: BIT 5,r
    cb_opcode_table[0x68] = (Opcode){ cb_bit_5_b, 2, 8, "BIT 5,B" };
    cb_opcode_table[0x69] = (Opcode){ cb_bit_5_c, 2, 8, "BIT 5,C" };
    cb_opcode_table[0x6A] = (Opcode){ cb_bit_5_d, 2, 8, "BIT 5,D" };
    cb_opcode_table[0x6B] = (Opcode){ cb_bit_5_e, 2, 8, "BIT 5,E" };
    cb_opcode_table[0x6C] = (Opcode){ cb_bit_5_h, 2, 8, "BIT 5,H" };
    cb_opcode_table[0x6D] = (Opcode){ cb_bit_5_l, 2, 8, "BIT 5,L" };
    cb_opcode_table[0x6E] = (Opcode){ cb_bit_5_hlm, 2, 16, "BIT 5,(HL)" };
    cb_opcode_table[0x6F] = (Opcode){ cb_bit_5_a, 2, 8, "BIT 5,A" };
    // 0x70-0x77: BIT 6,r
    cb_opcode_table[0x70] = (Opcode){ cb_bit_6_b, 2, 8, "BIT 6,B" };
    cb_opcode_table[0x71] = (Opcode){ cb_bit_6_c, 2, 8, "BIT 6,C" };
    cb_opcode_table[0x72] = (Opcode){ cb_bit_6_d, 2, 8, "BIT 6,D" };
    cb_opcode_table[0x73] = (Opcode){ cb_bit_6_e, 2, 8, "BIT 6,E" };
    cb_opcode_table[0x74] = (Opcode){ cb_bit_6_h, 2, 8, "BIT 6,H" };
    cb_opcode_table[0x75] = (Opcode){ cb_bit_6_l, 2, 8, "BIT 6,L" };
    cb_opcode_table[0x76] = (Opcode){ cb_bit_6_hlm, 2, 16, "BIT 6,(HL)" };
    cb_opcode_table[0x77] = (Opcode){ cb_bit_6_a, 2, 8, "BIT 6,A" };
    // 0x78-0x7F: BIT 7,r
    cb_opcode_table[0x78] = (Opcode){ cb_bit_7_b, 2, 8, "BIT 7,B" };
    cb_opcode_table[0x79] = (Opcode){ cb_bit_7_c, 2, 8, "BIT 7,C" };
    cb_opcode_table[0x7A] = (Opcode){ cb_bit_7_d, 2, 8, "BIT 7,D" };
    cb_opcode_table[0x7B] = (Opcode){ cb_bit_7_e, 2, 8, "BIT 7,E" };
    cb_opcode_table[0x7C] = (Opcode){ cb_bit_7_h, 2, 8, "BIT 7,H" };
    cb_opcode_table[0x7D] = (Opcode){ cb_bit_7_l, 2, 8, "BIT 7,L" };
    cb_opcode_table[0x7E] = (Opcode){ cb_bit_7_hlm, 2, 16, "BIT 7,(HL)" };
    cb_opcode_table[0x7F] = (Opcode){ cb_bit_7_a, 2, 8, "BIT 7,A" };
    // 0x80-0x87: RES 0,r
    cb_opcode_table[0x80] = (Opcode){ cb_res_0_b, 2, 8, "RES 0,B" };
    cb_opcode_table[0x81] = (Opcode){ cb_res_0_c, 2, 8, "RES 0,C" };
    cb_opcode_table[0x82] = (Opcode){ cb_res_0_d, 2, 8, "RES 0,D" };
    cb_opcode_table[0x83] = (Opcode){ cb_res_0_e, 2, 8, "RES 0,E" };
    cb_opcode_table[0x84] = (Opcode){ cb_res_0_h, 2, 8, "RES 0,H" };
    cb_opcode_table[0x85] = (Opcode){ cb_res_0_l, 2, 8, "RES 0,L" };
    cb_opcode_table[0x86] = (Opcode){ cb_res_0_hlm, 2, 16, "RES 0,(HL)" };
    cb_opcode_table[0x87] = (Opcode){ cb_res_0_a, 2, 8, "RES 0,A" };
    // 0x88-0x8F: RES 1,r
    cb_opcode_table[0x88] = (Opcode){ cb_res_1_b, 2, 8, "RES 1,B" };
    cb_opcode_table[0x89] = (Opcode){ cb_res_1_c, 2, 8, "RES 1,C" };
    cb_opcode_table[0x8A] = (Opcode){ cb_res_1_d, 2, 8, "RES 1,D" };
    cb_opcode_table[0x8B] = (Opcode){ cb_res_1_e, 2, 8, "RES 1,E" };
    cb_opcode_table[0x8C] = (Opcode){ cb_res_1_h, 2, 8, "RES 1,H" };
    cb_opcode_table[0x8D] = (Opcode){ cb_res_1_l, 2, 8, "RES 1,L" };
    cb_opcode_table[0x8E] = (Opcode){ cb_res_1_hlm, 2, 16, "RES 1,(HL)" };
    cb_opcode_table[0x8F] = (Opcode){ cb_res_1_a, 2, 8, "RES 1,A" };
    // 0x90-0x97: RES 2,r
    cb_opcode_table[0x90] = (Opcode){ cb_res_2_b, 2, 8, "RES 2,B" };
    cb_opcode_table[0x91] = (Opcode){ cb_res_2_c, 2, 8, "RES 2,C" };
    cb_opcode_table[0x92] = (Opcode){ cb_res_2_d, 2, 8, "RES 2,D" };
    cb_opcode_table[0x93] = (Opcode){ cb_res_2_e, 2, 8, "RES 2,E" };
    cb_opcode_table[0x94] = (Opcode){ cb_res_2_h, 2, 8, "RES 2,H" };
    cb_opcode_table[0x95] = (Opcode){ cb_res_2_l, 2, 8, "RES 2,L" };
    cb_opcode_table[0x96] = (Opcode){ cb_res_2_hlm, 2, 16, "RES 2,(HL)" };
    cb_opcode_table[0x97] = (Opcode){ cb_res_2_a, 2, 8, "RES 2,A" };
    // 0x98-0x9F: RES 3,r
    cb_opcode_table[0x98] = (Opcode){ cb_res_3_b, 2, 8, "RES 3,B" };
    cb_opcode_table[0x99] = (Opcode){ cb_res_3_c, 2, 8, "RES 3,C" };
    cb_opcode_table[0x9A] = (Opcode){ cb_res_3_d, 2, 8, "RES 3,D" };
    cb_opcode_table[0x9B] = (Opcode){ cb_res_3_e, 2, 8, "RES 3,E" };
    cb_opcode_table[0x9C] = (Opcode){ cb_res_3_h, 2, 8, "RES 3,H" };
    cb_opcode_table[0x9D] = (Opcode){ cb_res_3_l, 2, 8, "RES 3,L" };
    cb_opcode_table[0x9E] = (Opcode){ cb_res_3_hlm, 2, 16, "RES 3,(HL)" };
    cb_opcode_table[0x9F] = (Opcode){ cb_res_3_a, 2, 8, "RES 3,A" };
    // 0xA0-0xA7: RES 4,r
    cb_opcode_table[0xA0] = (Opcode){ cb_res_4_b, 2, 8, "RES 4,B" };
    cb_opcode_table[0xA1] = (Opcode){ cb_res_4_c, 2, 8, "RES 4,C" };
    cb_opcode_table[0xA2] = (Opcode){ cb_res_4_d, 2, 8, "RES 4,D" };
    cb_opcode_table[0xA3] = (Opcode){ cb_res_4_e, 2, 8, "RES 4,E" };
    cb_opcode_table[0xA4] = (Opcode){ cb_res_4_h, 2, 8, "RES 4,H" };
    cb_opcode_table[0xA5] = (Opcode){ cb_res_4_l, 2, 8, "RES 4,L" };
    cb_opcode_table[0xA6] = (Opcode){ cb_res_4_hlm, 2, 16, "RES 4,(HL)" };
    cb_opcode_table[0xA7] = (Opcode){ cb_res_4_a, 2, 8, "RES 4,A" };
    // 0xA8-0xAF: RES 5,r
    cb_opcode_table[0xA8] = (Opcode){ cb_res_5_b, 2, 8, "RES 5,B" };
    cb_opcode_table[0xA9] = (Opcode){ cb_res_5_c, 2, 8, "RES 5,C" };
    cb_opcode_table[0xAA] = (Opcode){ cb_res_5_d, 2, 8, "RES 5,D" };
    cb_opcode_table[0xAB] = (Opcode){ cb_res_5_e, 2, 8, "RES 5,E" };
    cb_opcode_table[0xAC] = (Opcode){ cb_res_5_h, 2, 8, "RES 5,H" };
    cb_opcode_table[0xAD] = (Opcode){ cb_res_5_l, 2, 8, "RES 5,L" };
    cb_opcode_table[0xAE] = (Opcode){ cb_res_5_hlm, 2, 16, "RES 5,(HL)" };
    cb_opcode_table[0xAF] = (Opcode){ cb_res_5_a, 2, 8, "RES 5,A" };
    // 0xB0-0xB7: RES 6,r
    cb_opcode_table[0xB0] = (Opcode){ cb_res_6_b, 2, 8, "RES 6,B" };
    cb_opcode_table[0xB1] = (Opcode){ cb_res_6_c, 2, 8, "RES 6,C" };
    cb_opcode_table[0xB2] = (Opcode){ cb_res_6_d, 2, 8, "RES 6,D" };
    cb_opcode_table[0xB3] = (Opcode){ cb_res_6_e, 2, 8, "RES 6,E" };
    cb_opcode_table[0xB4] = (Opcode){ cb_res_6_h, 2, 8, "RES 6,H" };
    cb_opcode_table[0xB5] = (Opcode){ cb_res_6_l, 2, 8, "RES 6,L" };
    cb_opcode_table[0xB6] = (Opcode){ cb_res_6_hlm, 2, 16, "RES 6,(HL)" };
    cb_opcode_table[0xB7] = (Opcode){ cb_res_6_a, 2, 8, "RES 6,A" };
    // 0xB8-0xBF: RES 7,r
    cb_opcode_table[0xB8] = (Opcode){ cb_res_7_b, 2, 8, "RES 7,B" };
    cb_opcode_table[0xB9] = (Opcode){ cb_res_7_c, 2, 8, "RES 7,C" };
    cb_opcode_table[0xBA] = (Opcode){ cb_res_7_d, 2, 8, "RES 7,D" };
    cb_opcode_table[0xBB] = (Opcode){ cb_res_7_e, 2, 8, "RES 7,E" };
    cb_opcode_table[0xBC] = (Opcode){ cb_res_7_h, 2, 8, "RES 7,H" };
    cb_opcode_table[0xBD] = (Opcode){ cb_res_7_l, 2, 8, "RES 7,L" };
    cb_opcode_table[0xBE] = (Opcode){ cb_res_7_hlm, 2, 16, "RES 7,(HL)" };
    cb_opcode_table[0xBF] = (Opcode){ cb_res_7_a, 2, 8, "RES 7,A" };
    // 0xC0-0xC7: SET 0,r
    cb_opcode_table[0xC0] = (Opcode){ cb_set_0_b, 2, 8, "SET 0,B" };
    cb_opcode_table[0xC1] = (Opcode){ cb_set_0_c, 2, 8, "SET 0,C" };
    cb_opcode_table[0xC2] = (Opcode){ cb_set_0_d, 2, 8, "SET 0,D" };
    cb_opcode_table[0xC3] = (Opcode){ cb_set_0_e, 2, 8, "SET 0,E" };
    cb_opcode_table[0xC4] = (Opcode){ cb_set_0_h, 2, 8, "SET 0,H" };
    cb_opcode_table[0xC5] = (Opcode){ cb_set_0_l, 2, 8, "SET 0,L" };
    cb_opcode_table[0xC6] = (Opcode){ cb_set_0_hlm, 2, 16, "SET 0,(HL)" };
    cb_opcode_table[0xC7] = (Opcode){ cb_set_0_a, 2, 8, "SET 0,A" };
    // 0xC8-0xCF: SET 1,r
    cb_opcode_table[0xC8] = (Opcode){ cb_set_1_b, 2, 8, "SET 1,B" };
    cb_opcode_table[0xC9] = (Opcode){ cb_set_1_c, 2, 8, "SET 1,C" };
    cb_opcode_table[0xCA] = (Opcode){ cb_set_1_d, 2, 8, "SET 1,D" };
    cb_opcode_table[0xCB] = (Opcode){ cb_set_1_e, 2, 8, "SET 1,E" };
    cb_opcode_table[0xCC] = (Opcode){ cb_set_1_h, 2, 8, "SET 1,H" };
    cb_opcode_table[0xCD] = (Opcode){ cb_set_1_l, 2, 8, "SET 1,L" };
    cb_opcode_table[0xCE] = (Opcode){ cb_set_1_hlm, 2, 16, "SET 1,(HL)" };
    cb_opcode_table[0xCF] = (Opcode){ cb_set_1_a, 2, 8, "SET 1,A" };
    // 0xD0-0xD7: SET 2,r
    cb_opcode_table[0xD0] = (Opcode){ cb_set_2_b, 2, 8, "SET 2,B" };
    cb_opcode_table[0xD1] = (Opcode){ cb_set_2_c, 2, 8, "SET 2,C" };
    cb_opcode_table[0xD2] = (Opcode){ cb_set_2_d, 2, 8, "SET 2,D" };
    cb_opcode_table[0xD3] = (Opcode){ cb_set_2_e, 2, 8, "SET 2,E" };
    cb_opcode_table[0xD4] = (Opcode){ cb_set_2_h, 2, 8, "SET 2,H" };
    cb_opcode_table[0xD5] = (Opcode){ cb_set_2_l, 2, 8, "SET 2,L" };
    cb_opcode_table[0xD6] = (Opcode){ cb_set_2_hlm, 2, 16, "SET 2,(HL)" };
    cb_opcode_table[0xD7] = (Opcode){ cb_set_2_a, 2, 8, "SET 2,A" };
    // 0xD8-0xDF: SET 3,r
    cb_opcode_table[0xD8] = (Opcode){ cb_set_3_b, 2, 8, "SET 3,B" };
    cb_opcode_table[0xD9] = (Opcode){ cb_set_3_c, 2, 8, "SET 3,C" };
    cb_opcode_table[0xDA] = (Opcode){ cb_set_3_d, 2, 8, "SET 3,D" };
    cb_opcode_table[0xDB] = (Opcode){ cb_set_3_e, 2, 8, "SET 3,E" };
    cb_opcode_table[0xDC] = (Opcode){ cb_set_3_h, 2, 8, "SET 3,H" };
    cb_opcode_table[0xDD] = (Opcode){ cb_set_3_l, 2, 8, "SET 3,L" };
    cb_opcode_table[0xDE] = (Opcode){ cb_set_3_hlm, 2, 16, "SET 3,(HL)" };
    cb_opcode_table[0xDF] = (Opcode){ cb_set_3_a, 2, 8, "SET 3,A" };
    // 0xE0-0xE7: SET 4,r
    cb_opcode_table[0xE0] = (Opcode){ cb_set_4_b, 2, 8, "SET 4,B" };
    cb_opcode_table[0xE1] = (Opcode){ cb_set_4_c, 2, 8, "SET 4,C" };
    cb_opcode_table[0xE2] = (Opcode){ cb_set_4_d, 2, 8, "SET 4,D" };
    cb_opcode_table[0xE3] = (Opcode){ cb_set_4_e, 2, 8, "SET 4,E" };
    cb_opcode_table[0xE4] = (Opcode){ cb_set_4_h, 2, 8, "SET 4,H" };
    cb_opcode_table[0xE5] = (Opcode){ cb_set_4_l, 2, 8, "SET 4,L" };
    cb_opcode_table[0xE6] = (Opcode){ cb_set_4_hlm, 2, 16, "SET 4,(HL)" };
    cb_opcode_table[0xE7] = (Opcode){ cb_set_4_a, 2, 8, "SET 4,A" };
    // 0xE8-0xEF: SET 5,r
    cb_opcode_table[0xE8] = (Opcode){ cb_set_5_b, 2, 8, "SET 5,B" };
    cb_opcode_table[0xE9] = (Opcode){ cb_set_5_c, 2, 8, "SET 5,C" };
    cb_opcode_table[0xEA] = (Opcode){ cb_set_5_d, 2, 8, "SET 5,D" };
    cb_opcode_table[0xEB] = (Opcode){ cb_set_5_e, 2, 8, "SET 5,E" };
    cb_opcode_table[0xEC] = (Opcode){ cb_set_5_h, 2, 8, "SET 5,H" };
    cb_opcode_table[0xED] = (Opcode){ cb_set_5_l, 2, 8, "SET 5,L" };
    cb_opcode_table[0xEE] = (Opcode){ cb_set_5_hlm, 2, 16, "SET 5,(HL)" };
    cb_opcode_table[0xEF] = (Opcode){ cb_set_5_a, 2, 8, "SET 5,A" };
    // 0xF0-0xF7: SET 6,r
    cb_opcode_table[0xF0] = (Opcode){ cb_set_6_b, 2, 8, "SET 6,B" };
    cb_opcode_table[0xF1] = (Opcode){ cb_set_6_c, 2, 8, "SET 6,C" };
    cb_opcode_table[0xF2] = (Opcode){ cb_set_6_d, 2, 8, "SET 6,D" };
    cb_opcode_table[0xF3] = (Opcode){ cb_set_6_e, 2, 8, "SET 6,E" };
    cb_opcode_table[0xF4] = (Opcode){ cb_set_6_h, 2, 8, "SET 6,H" };
    cb_opcode_table[0xF5] = (Opcode){ cb_set_6_l, 2, 8, "SET 6,L" };
    cb_opcode_table[0xF6] = (Opcode){ cb_set_6_hlm, 2, 16, "SET 6,(HL)" };
    cb_opcode_table[0xF7] = (Opcode){ cb_set_6_a, 2, 8, "SET 6,A" };
    // 0xF8-0xFF: SET 7,r
    cb_opcode_table[0xF8] = (Opcode){ cb_set_7_b, 2, 8, "SET 7,B" };
    cb_opcode_table[0xF9] = (Opcode){ cb_set_7_c, 2, 8, "SET 7,C" };
    cb_opcode_table[0xFA] = (Opcode){ cb_set_7_d, 2, 8, "SET 7,D" };
    cb_opcode_table[0xFB] = (Opcode){ cb_set_7_e, 2, 8, "SET 7,E" };
    cb_opcode_table[0xFC] = (Opcode){ cb_set_7_h, 2, 8, "SET 7,H" };
    cb_opcode_table[0xFD] = (Opcode){ cb_set_7_l, 2, 8, "SET 7,L" };
    cb_opcode_table[0xFE] = (Opcode){ cb_set_7_hlm, 2, 16, "SET 7,(HL)" };
    cb_opcode_table[0xFF] = (Opcode){ cb_set_7_a, 2, 8, "SET 7,A" };
}