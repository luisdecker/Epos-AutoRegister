#ifndef EPOS_QUEUE
#define EPOS_QUEUE

#include "../queue.h"
#include <utility/queue.h>

namespace EAB {
template <typename T> class QueueAbstraction : public QueueInterface<T> {
public:
    typedef EPOS::Queue<T> Q;
    typedef typename Q::Element E;

public:
    QueueAbstraction() {
        this->q = new Q();
    }
    void insert(T element) {
        T* v = new T(element);
        E *link = new E(v);
        this->q->insert(link);
    }
    T remove() {
        E *link = this->q->remove();
        T *result = link->object();
        delete link;
        return *result;
    }
    bool empty() {
        return this->q->empty();
    }
    int size() {
        return this->q->size();
    }

private:
    Q *q;
};
}

#endif
