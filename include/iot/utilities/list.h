#ifndef LIST_INTERFACE
#define LIST_INTERFACE

#include "iterator.h"

template <typename T>
class ListInterface {
public:
    typedef IteratorInterface<T> Iterator;
    virtual ~ListInterface(){};
    virtual void insert(T element) = 0;
    virtual void remove(T element) = 0;
    virtual bool find(T element) = 0;
    virtual T search(T element) = 0;
    virtual Iterator* iterator() = 0;
};

#endif
