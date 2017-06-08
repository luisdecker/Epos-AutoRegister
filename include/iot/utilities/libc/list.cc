#ifndef LIBC_LIST
#define LIBC_LIST

#include "../list.h"
#include <algorithm>
#include <list>
#include "../iterator.h"
#include "iterator.cc"

namespace EAB {
template <typename T> class ListAbstraction : public ListInterface<T> {
public:
    typedef std::list<T> L;
    typedef typename L::iterator I;
    typedef IteratorAbstraction<T> Iterator;

public:
    ListAbstraction() {
        this->m = new L();
    }
    void insert(T element) {
        this->m->push_back(element);
    }
    void remove(T element) {
        I first = this->m->begin();
        I end = this->m->end();
        I it = std::find(first, end, element);
        if (it == end) {
            return;
        }
        this->m->erase(it);
    }
    bool find(T element) {
        I first = this->m->begin();
        I end = this->m->end();
        return std::find(first, end, element) != end;
    }
    T search(T element) {
        I first = this->m->begin();
        I end = this->m->end();
        T p = *(std::find(first, end, element));
        return p;
    }
    Iterator* iterator() {
        return new Iterator(this->m->begin(), this->m->end());
    }
protected:
    L *m;
};
}

#endif
