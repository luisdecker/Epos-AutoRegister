#ifndef EPOS_CONDITION
#define EPOS_CONDITION

#include "../condition.h"
#include <condition.h>

namespace EAB {
class ConditionAbstraction : public ConditionInterface {
public:
    ConditionAbstraction() {
        this->c = new EPOS::Condition();
    }
    void wait() {
        this->c->wait();
    }
    void notify() {
        this->c->signal();
    }
    void notify_all() {
        this->c->broadcast();
    }

private:
    EPOS::Condition *c;
};
}

#endif
