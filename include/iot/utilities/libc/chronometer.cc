#ifndef LIBC_CHRONOMETER
#define LIBC_CHRONOMETER

#include "../chronometer.h"
#include <chrono>

namespace EAB {
class ChronometerAbstraction : public ChronometerInterface {
public:
    ChronometerAbstraction() {
        this->reset();
    }
    ~ChronometerAbstraction() {}
    void reset() {
        this->d = std::chrono::microseconds::zero();
        this->started = false;
    }
    void start() {
        this->t1 = std::chrono::high_resolution_clock::now();
        this->started = true;
    }
    void lap() {
        std::chrono::high_resolution_clock::time_point t2;
        t2 = std::chrono::high_resolution_clock::now();
        this->d =
            std::chrono::duration_cast<std::chrono::microseconds>(t2 - this->t1);
    }
    void stop() {
        this->lap();
        this->started = false;
    }
    unsigned int read() {
        return d.count();
    }

protected:
    std::chrono::high_resolution_clock::time_point t1;
    std::chrono::microseconds d;
    bool started;
};
}

#endif
