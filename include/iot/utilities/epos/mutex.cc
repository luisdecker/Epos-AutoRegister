#ifndef EPOS_MUTEX
#define EPOS_MUTEX

#include "../mutex.h"
#include <mutex.h>

namespace EAB {
class MutexAbstraction : public MutexInterface {
public:
    MutexAbstraction() {
        this->m = new EPOS::Mutex();
    }
    void lock() {
        this->m->lock();
    }
    void unlock() {
        this->m->unlock();
    }

private:
    EPOS::Mutex *m;
};
}

#endif
