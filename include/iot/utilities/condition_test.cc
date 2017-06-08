#include "condition.h"
#include "condition_app.cc"

int main(void) {
    ConditionInterface *i = new ConditionApp();
    i->wait();
    i->notify();
    i->notify_all();
}
