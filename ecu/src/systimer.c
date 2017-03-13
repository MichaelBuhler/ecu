#include "systimer.h"

unsigned long micros () {
    return get32(SYSTIMER_COUNTER_LOW);
}

void delay (unsigned long us) {
    unsigned long until = micros();
    until += us;
    while ( micros() < until );
}