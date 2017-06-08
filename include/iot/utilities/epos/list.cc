#ifndef EPOS_LIST
#define EPOS_LIST

#include "../list.h"
#include "../iterator.h"
#include "iterator.cc"
#include <utility/list.h>

namespace EAB {
template <typename T> class ListAbstraction : public ListInterface<T> {
public:
    typedef EPOS::List<T> Q;
    typedef typename Q::Element E;
    typedef IteratorAbstraction<T> Iterator;

public:
    ListAbstraction() {
        this->l = new Q();
    }
    void insert(T element) {
        T *v = new T(element);
        E *link = new E(v);
        this->l->insert(link);
    }
    void remove(T element) {
        E * e = this->l->head();
        for(; e && (*(e->object()) != element); e = e->next());
        E *link = this->l->remove(e);
        T *v = link->object();
        delete v;
        delete link;
    }
    bool find(T element) {
        E *e = this->l->head();

        for(; e && (*(e->object()) != element); e = e->next());
        return e != 0;
    }
    T search(T element) {
        E *e = this->l->head();
        for(; e && (*(e->object()) != element); e = e->next());
        T *v = e->object();
        return *v;
    }
    Iterator* iterator() {
        return new Iterator(this->l->begin(), this->l->end());
    }

private:
    Q *l;
};
}

#endif
