#ifndef LIBC_QUEUE
#define LIBC_QUEUE

#include "../queue.h"
#include <queue>

namespace EAB {
template <typename T> class QueueAbstraction : public QueueInterface<T> {
public:
    QueueAbstraction() {
        this->m = new std::queue<T>();
    }
    void insert(T element) {
        this->m->push(element);
    }
    T remove() {
        T front = this->m->front();
        this->m->pop();
        return front;
    }
    bool empty() {
        return this->m->empty();
    }
    int size() {
        return this->m->size();
    }

protected:
    std::queue<T> *m;
};
}

#endif
