#ifndef LIBC_SLEEP
#define LIBC_SLEEP

#include <time.h>

namespace EAB{
    void delay(unsigned int d) {
        struct timespec tim;
        tim.tv_sec = d / 1000000;
        tim.tv_nsec = (d % 1000000) * 1000;
        int result = -1;
        while (result == -1) {
            struct timespec tim2;
            result = nanosleep(&tim, &tim2);
            tim = tim2;
        }
    }
}
#endif
