#ifndef CHRONOMETER_APP
#define CHRONOMETER_APP

#include "chronometer.h"
#ifdef SIMULATE
#include "libc/chronometer.cc"
#else
#include "epos/chronometer.cc"
#endif

class ChronometerApp : public ChronometerInterface {
public:
    ChronometerApp() {
        this->m = new EAB::ChronometerAbstraction();
    }
    ~ChronometerApp() {
        delete this->m;
    }
    void reset() {
        this->m->reset();
    }
    void start() {
        this->m->start();
    }
    void lap() {
        this->m->lap();
    }
    void stop() {
        this->m->stop();
    }
    unsigned int read() {
        return this->m->read();
    }

private:
    EAB::ChronometerAbstraction *m;
};

#endif
