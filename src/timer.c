#include "timer.h"
#include "flags.h" 

void timer_init(Timer* timer) {
    timer->div = 0;
    timer->tima = 0;
    timer->tma = 0;
    timer->tac = 0;
    timer->div_counter = 0;
    timer->tima_counter = 0;
}

static uint16_t timer_frequency(uint8_t tac) {
    switch (tac & 0x3) {
        case 0: return 1024; 
        case 1: return 16;   
        case 2: return 64;   
        case 3: return 256; 
        default: return 1024;
    }
}

void timer_update(Timer* timer, uint16_t cycles, uint8_t* interrupt_flag) { 
    timer->div_counter += cycles;
    while (timer->div_counter >= 256) {
        timer->div_counter -= 256;
        timer->div = (timer->div + 1) & 0xFFFF;
    }

    if (timer->tac & 0x04) {
        timer->tima_counter += cycles;
        uint16_t freq = timer_frequency(timer->tac);
        while (timer->tima_counter >= freq) {
            timer->tima_counter -= freq;
            if (timer->tima == 0xFF) {
                timer->tima = timer->tma;
                if (interrupt_flag) *interrupt_flag |= 0x04;
            } else {
                timer->tima++;
            }
        }
    }
}