#ifndef MUTEX_INTERFACE
#define MUTEX_INTERFACE

class MutexInterface {
public:
    virtual ~MutexInterface() {};
    virtual void lock() = 0;
    virtual void unlock() = 0;
};

#endif
