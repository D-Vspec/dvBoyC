#ifndef INSTRUCTIONS_LIST_CB_H
#define INSTRUCTIONS_LIST_CB_H

#include "memory.h"
#include "cpu.h"

// 0x00-0x07
void cb_rlc_b(Memory*, CPU*);
void cb_rlc_c(Memory*, CPU*);
void cb_rlc_d(Memory*, CPU*);
void cb_rlc_e(Memory*, CPU*);
void cb_rlc_h(Memory*, CPU*);
void cb_rlc_l(Memory*, CPU*);
void cb_rlc_hlm(Memory*, CPU*);
void cb_rlc_a(Memory*, CPU*);
// 0x08-0x0F
void cb_rrc_b(Memory*, CPU*);
void cb_rrc_c(Memory*, CPU*);
void cb_rrc_d(Memory*, CPU*);
void cb_rrc_e(Memory*, CPU*);
void cb_rrc_h(Memory*, CPU*);
void cb_rrc_l(Memory*, CPU*);
void cb_rrc_hlm(Memory*, CPU*);
void cb_rrc_a(Memory*, CPU*);
// 0x10-0x17
void cb_rl_b(Memory*, CPU*);
void cb_rl_c(Memory*, CPU*);
void cb_rl_d(Memory*, CPU*);
void cb_rl_e(Memory*, CPU*);
void cb_rl_h(Memory*, CPU*);
void cb_rl_l(Memory*, CPU*);
void cb_rl_hlm(Memory*, CPU*);
void cb_rl_a(Memory*, CPU*);
// 0x18-0x1F
void cb_rr_b(Memory*, CPU*);
void cb_rr_c(Memory*, CPU*);
void cb_rr_d(Memory*, CPU*);
void cb_rr_e(Memory*, CPU*);
void cb_rr_h(Memory*, CPU*);
void cb_rr_l(Memory*, CPU*);
void cb_rr_hlm(Memory*, CPU*);
void cb_rr_a(Memory*, CPU*);
// 0x20-0x27
void cb_sla_b(Memory*, CPU*);
void cb_sla_c(Memory*, CPU*);
void cb_sla_d(Memory*, CPU*);
void cb_sla_e(Memory*, CPU*);
void cb_sla_h(Memory*, CPU*);
void cb_sla_l(Memory*, CPU*);
void cb_sla_hlm(Memory*, CPU*);
void cb_sla_a(Memory*, CPU*);
// 0x28-0x2F
void cb_sra_b(Memory*, CPU*);
void cb_sra_c(Memory*, CPU*);
void cb_sra_d(Memory*, CPU*);
void cb_sra_e(Memory*, CPU*);
void cb_sra_h(Memory*, CPU*);
void cb_sra_l(Memory*, CPU*);
void cb_sra_hlm(Memory*, CPU*);
void cb_sra_a(Memory*, CPU*);
// 0x30-0x37
void cb_swap_b(Memory*, CPU*);
void cb_swap_c(Memory*, CPU*);
void cb_swap_d(Memory*, CPU*);
void cb_swap_e(Memory*, CPU*);
void cb_swap_h(Memory*, CPU*);
void cb_swap_l(Memory*, CPU*);
void cb_swap_hlm(Memory*, CPU*);
void cb_swap_a(Memory*, CPU*);
// 0x38-0x3F
void cb_srl_b(Memory*, CPU*);
void cb_srl_c(Memory*, CPU*);
void cb_srl_d(Memory*, CPU*);
void cb_srl_e(Memory*, CPU*);
void cb_srl_h(Memory*, CPU*);
void cb_srl_l(Memory*, CPU*);
void cb_srl_hlm(Memory*, CPU*);
void cb_srl_a(Memory*, CPU*);
// 0x40-0x47
void cb_bit_0_b(Memory*, CPU*);
void cb_bit_0_c(Memory*, CPU*);
void cb_bit_0_d(Memory*, CPU*);
void cb_bit_0_e(Memory*, CPU*);
void cb_bit_0_h(Memory*, CPU*);
void cb_bit_0_l(Memory*, CPU*);
void cb_bit_0_hlm(Memory*, CPU*);
void cb_bit_0_a(Memory*, CPU*);
// 0x48-0x4F
void cb_bit_1_b(Memory*, CPU*);
void cb_bit_1_c(Memory*, CPU*);
void cb_bit_1_d(Memory*, CPU*);
void cb_bit_1_e(Memory*, CPU*);
void cb_bit_1_h(Memory*, CPU*);
void cb_bit_1_l(Memory*, CPU*);
void cb_bit_1_hlm(Memory*, CPU*);
void cb_bit_1_a(Memory*, CPU*);
// 0x50-0x57
void cb_bit_2_b(Memory*, CPU*);
void cb_bit_2_c(Memory*, CPU*);
void cb_bit_2_d(Memory*, CPU*);
void cb_bit_2_e(Memory*, CPU*);
void cb_bit_2_h(Memory*, CPU*);
void cb_bit_2_l(Memory*, CPU*);
void cb_bit_2_hlm(Memory*, CPU*);
void cb_bit_2_a(Memory*, CPU*);
// 0x58-0x5F
void cb_bit_3_b(Memory*, CPU*);
void cb_bit_3_c(Memory*, CPU*);
void cb_bit_3_d(Memory*, CPU*);
void cb_bit_3_e(Memory*, CPU*);
void cb_bit_3_h(Memory*, CPU*);
void cb_bit_3_l(Memory*, CPU*);
void cb_bit_3_hlm(Memory*, CPU*);
void cb_bit_3_a(Memory*, CPU*);
// 0x60-0x67
void cb_bit_4_b(Memory*, CPU*);
void cb_bit_4_c(Memory*, CPU*);
void cb_bit_4_d(Memory*, CPU*);
void cb_bit_4_e(Memory*, CPU*);
void cb_bit_4_h(Memory*, CPU*);
void cb_bit_4_l(Memory*, CPU*);
void cb_bit_4_hlm(Memory*, CPU*);
void cb_bit_4_a(Memory*, CPU*);
// 0x68-0x6F
void cb_bit_5_b(Memory*, CPU*);
void cb_bit_5_c(Memory*, CPU*);
void cb_bit_5_d(Memory*, CPU*);
void cb_bit_5_e(Memory*, CPU*);
void cb_bit_5_h(Memory*, CPU*);
void cb_bit_5_l(Memory*, CPU*);
void cb_bit_5_hlm(Memory*, CPU*);
void cb_bit_5_a(Memory*, CPU*);
// 0x70-0x77
void cb_bit_6_b(Memory*, CPU*);
void cb_bit_6_c(Memory*, CPU*);
void cb_bit_6_d(Memory*, CPU*);
void cb_bit_6_e(Memory*, CPU*);
void cb_bit_6_h(Memory*, CPU*);
void cb_bit_6_l(Memory*, CPU*);
void cb_bit_6_hlm(Memory*, CPU*);
void cb_bit_6_a(Memory*, CPU*);
// 0x78-0x7F
void cb_bit_7_b(Memory*, CPU*);
void cb_bit_7_c(Memory*, CPU*);
void cb_bit_7_d(Memory*, CPU*);
void cb_bit_7_e(Memory*, CPU*);
void cb_bit_7_h(Memory*, CPU*);
void cb_bit_7_l(Memory*, CPU*);
void cb_bit_7_hlm(Memory*, CPU*);
void cb_bit_7_a(Memory*, CPU*);
// 0x80-0x87
void cb_res_0_b(Memory*, CPU*);
void cb_res_0_c(Memory*, CPU*);
void cb_res_0_d(Memory*, CPU*);
void cb_res_0_e(Memory*, CPU*);
void cb_res_0_h(Memory*, CPU*);
void cb_res_0_l(Memory*, CPU*);
void cb_res_0_hlm(Memory*, CPU*);
void cb_res_0_a(Memory*, CPU*);
// 0x88-0x8F
void cb_res_1_b(Memory*, CPU*);
void cb_res_1_c(Memory*, CPU*);
void cb_res_1_d(Memory*, CPU*);
void cb_res_1_e(Memory*, CPU*);
void cb_res_1_h(Memory*, CPU*);
void cb_res_1_l(Memory*, CPU*);
void cb_res_1_hlm(Memory*, CPU*);
void cb_res_1_a(Memory*, CPU*);
// 0x90-0x97
void cb_res_2_b(Memory*, CPU*);
void cb_res_2_c(Memory*, CPU*);
void cb_res_2_d(Memory*, CPU*);
void cb_res_2_e(Memory*, CPU*);
void cb_res_2_h(Memory*, CPU*);
void cb_res_2_l(Memory*, CPU*);
void cb_res_2_hlm(Memory*, CPU*);
void cb_res_2_a(Memory*, CPU*);
// 0x98-0x9F
void cb_res_3_b(Memory*, CPU*);
void cb_res_3_c(Memory*, CPU*);
void cb_res_3_d(Memory*, CPU*);
void cb_res_3_e(Memory*, CPU*);
void cb_res_3_h(Memory*, CPU*);
void cb_res_3_l(Memory*, CPU*);
void cb_res_3_hlm(Memory*, CPU*);
void cb_res_3_a(Memory*, CPU*);
// 0xA0-0xA7
void cb_res_4_b(Memory*, CPU*);
void cb_res_4_c(Memory*, CPU*);
void cb_res_4_d(Memory*, CPU*);
void cb_res_4_e(Memory*, CPU*);
void cb_res_4_h(Memory*, CPU*);
void cb_res_4_l(Memory*, CPU*);
void cb_res_4_hlm(Memory*, CPU*);
void cb_res_4_a(Memory*, CPU*);
// 0xA8-0xAF
void cb_res_5_b(Memory*, CPU*);
void cb_res_5_c(Memory*, CPU*);
void cb_res_5_d(Memory*, CPU*);
void cb_res_5_e(Memory*, CPU*);
void cb_res_5_h(Memory*, CPU*);
void cb_res_5_l(Memory*, CPU*);
void cb_res_5_hlm(Memory*, CPU*);
void cb_res_5_a(Memory*, CPU*);
// 0xB0-0xB7
void cb_res_6_b(Memory*, CPU*);
void cb_res_6_c(Memory*, CPU*);
void cb_res_6_d(Memory*, CPU*);
void cb_res_6_e(Memory*, CPU*);
void cb_res_6_h(Memory*, CPU*);
void cb_res_6_l(Memory*, CPU*);
void cb_res_6_hlm(Memory*, CPU*);
void cb_res_6_a(Memory*, CPU*);
// 0xB8-0xBF
void cb_res_7_b(Memory*, CPU*);
void cb_res_7_c(Memory*, CPU*);
void cb_res_7_d(Memory*, CPU*);
void cb_res_7_e(Memory*, CPU*);
void cb_res_7_h(Memory*, CPU*);
void cb_res_7_l(Memory*, CPU*);
void cb_res_7_hlm(Memory*, CPU*);
void cb_res_7_a(Memory*, CPU*);
// 0xC0-0xC7
void cb_set_0_b(Memory*, CPU*);
void cb_set_0_c(Memory*, CPU*);
void cb_set_0_d(Memory*, CPU*);
void cb_set_0_e(Memory*, CPU*);
void cb_set_0_h(Memory*, CPU*);
void cb_set_0_l(Memory*, CPU*);
void cb_set_0_hlm(Memory*, CPU*);
void cb_set_0_a(Memory*, CPU*);
// 0xC8-0xCF
void cb_set_1_b(Memory*, CPU*);
void cb_set_1_c(Memory*, CPU*);
void cb_set_1_d(Memory*, CPU*);
void cb_set_1_e(Memory*, CPU*);
void cb_set_1_h(Memory*, CPU*);
void cb_set_1_l(Memory*, CPU*);
void cb_set_1_hlm(Memory*, CPU*);
void cb_set_1_a(Memory*, CPU*);
// 0xD0-0xD7
void cb_set_2_b(Memory*, CPU*);
void cb_set_2_c(Memory*, CPU*);
void cb_set_2_d(Memory*, CPU*);
void cb_set_2_e(Memory*, CPU*);
void cb_set_2_h(Memory*, CPU*);
void cb_set_2_l(Memory*, CPU*);
void cb_set_2_hlm(Memory*, CPU*);
void cb_set_2_a(Memory*, CPU*);
// 0xD8-0xDF
void cb_set_3_b(Memory*, CPU*);
void cb_set_3_c(Memory*, CPU*);
void cb_set_3_d(Memory*, CPU*);
void cb_set_3_e(Memory*, CPU*);
void cb_set_3_h(Memory*, CPU*);
void cb_set_3_l(Memory*, CPU*);
void cb_set_3_hlm(Memory*, CPU*);
void cb_set_3_a(Memory*, CPU*);
// 0xE0-0xE7
void cb_set_4_b(Memory*, CPU*);
void cb_set_4_c(Memory*, CPU*);
void cb_set_4_d(Memory*, CPU*);
void cb_set_4_e(Memory*, CPU*);
void cb_set_4_h(Memory*, CPU*);
void cb_set_4_l(Memory*, CPU*);
void cb_set_4_hlm(Memory*, CPU*);
void cb_set_4_a(Memory*, CPU*);
// 0xE8-0xEF
void cb_set_5_b(Memory*, CPU*);
void cb_set_5_c(Memory*, CPU*);
void cb_set_5_d(Memory*, CPU*);
void cb_set_5_e(Memory*, CPU*);
void cb_set_5_h(Memory*, CPU*);
void cb_set_5_l(Memory*, CPU*);
void cb_set_5_hlm(Memory*, CPU*);
void cb_set_5_a(Memory*, CPU*);
// 0xF0-0xF7
void cb_set_6_b(Memory*, CPU*);
void cb_set_6_c(Memory*, CPU*);
void cb_set_6_d(Memory*, CPU*);
void cb_set_6_e(Memory*, CPU*);
void cb_set_6_h(Memory*, CPU*);
void cb_set_6_l(Memory*, CPU*);
void cb_set_6_hlm(Memory*, CPU*);
void cb_set_6_a(Memory*, CPU*);
// 0xF8-0xFF
void cb_set_7_b(Memory*, CPU*);
void cb_set_7_c(Memory*, CPU*);
void cb_set_7_d(Memory*, CPU*);
void cb_set_7_e(Memory*, CPU*);
void cb_set_7_h(Memory*, CPU*);
void cb_set_7_l(Memory*, CPU*);
void cb_set_7_hlm(Memory*, CPU*);
void cb_set_7_a(Memory*, CPU*);

#endif