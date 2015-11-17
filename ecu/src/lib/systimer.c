#include "systimer.h"

unsigned int micros() {
    return get32(SYSTIMER_COUNTER_LOW);
}
