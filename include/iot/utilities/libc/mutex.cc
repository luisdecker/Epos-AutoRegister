#ifndef LIBC_MUTEX
#define LIBC_MUTEX

#include "../mutex.h"
#include <mutex>

namespace EAB {
class MutexAbstraction : public MutexInterface {
public:
    MutexAbstraction() {
        this->m = new std::mutex();
    }
    void lock() {
        this->m->lock();
    }
    void unlock() {
        this->m->unlock();
    }

protected:
    std::mutex *m;
};
}

#endif
