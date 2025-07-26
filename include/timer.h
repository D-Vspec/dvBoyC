#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>

typedef struct {
    uint16_t div;
    uint8_t tima;
    uint8_t tma;
    uint8_t tac;
    uint16_t div_counter;
    uint16_t tima_counter;
} Timer;

void timer_init(Timer* timer);
void timer_update(Timer* timer, uint16_t cycles, uint8_t* interrupt_flag);

#endif // TIMER_H