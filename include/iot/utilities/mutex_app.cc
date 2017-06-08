#ifndef MUTEX_APP
#define MUTEX_APP

#include "mutex.h"
#ifdef SIMULATE
#include "libc/mutex.cc"
#else
#include "epos/mutex.cc"
#endif

class MutexApp : public MutexInterface {
public:
    MutexApp() {
        this->m = new EAB::MutexAbstraction();
    }
    void lock() {
        this->m->lock();
    }
    void unlock() {
        this->m->unlock();
    }

private:
    EAB::MutexAbstraction *m;
};

#endif
