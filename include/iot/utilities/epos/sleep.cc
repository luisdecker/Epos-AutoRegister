#ifndef EPOS_SLEEP
#define EPOS_SLEEP

#include <alarm.h>

namespace EAB {
    void delay(unsigned int d) {
        EPOS::Delay x(d);
    }
}
#endif
