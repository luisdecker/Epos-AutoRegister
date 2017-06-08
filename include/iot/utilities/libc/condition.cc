#ifndef LIBC_CONDITION
#define LIBC_CONDITION

#include "../condition.h"
#include <condition_variable>
#include <mutex>

namespace EAB {
class ConditionAbstraction : public ConditionInterface {
public:
    ConditionAbstraction() {
        this->c = new std::condition_variable();
    }
    void wait() {
        std::unique_lock<std::mutex> lck(this->mtx);
        this->c->wait(lck);
    }
    void notify() {
        std::unique_lock<std::mutex> lck(this->mtx);
        this->c->notify_one();
    }
    void notify_all() {
        std::unique_lock<std::mutex> lck(this->mtx);
        this->c->notify_all();
    }

protected:
    std::condition_variable *c;
    std::mutex mtx;
};
}

#endif
