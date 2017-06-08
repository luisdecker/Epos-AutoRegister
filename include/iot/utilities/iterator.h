#ifndef ITERATOR_INTERFACE
#define ITERATOR_INTERFACE

template <typename T>
class IteratorInterface {
public:
    virtual ~IteratorInterface(){};
    virtual void next() = 0;
    virtual bool hasNext() = 0;
    virtual T element() = 0;
};

#endif
