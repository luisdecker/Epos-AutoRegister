#ifndef LIST_APP
#define LIST_APP

#include "list.h"
#include "iterator.h"
#ifdef SIMULATE
#include "libc/list.cc"
#else
#include "epos/list.cc"
#endif

template <typename T> class ListApp : public ListInterface<T> {
public:
    typedef typename EAB::ListAbstraction<T>::Iterator Iterator;
    ListApp() {
        this->m = new EAB::ListAbstraction<T>();
    }
    ~ListApp() {
        delete this->m;
    }
    void insert(T element) {
        this->m->insert(element);
    }
    void remove(T element) {
        return this->m->remove(element);
    }
    bool find(T element) {
        return this->m->find(element);
    }
    T search(T element) {
        return this->m->search(element);
    }
    Iterator* iterator() {
        return this->m->iterator();
    }

private:
    EAB::ListAbstraction<T> *m;
};

#endif
