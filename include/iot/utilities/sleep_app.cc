#ifndef SLEEP_CC
#define SLEEP_CC

#include "sleep.h"
#ifdef SIMULATE
#include "libc/sleep.cc"
#else
#include "epos/sleep.cc"
#endif

void delay(unsigned int d) {
    EAB::delay(d);
}
#endif
