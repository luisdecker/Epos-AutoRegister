#ifndef LIBC_ITERATOR
#define LIBC_ITERATOR

#include "../iterator.h"
#include <iterator>
namespace EAB {
    template <typename T>
    class IteratorAbstraction : public IteratorInterface<T> {
        public:
            typedef typename std::list<T>::iterator It;

            IteratorAbstraction(It begin, It end) {
                this->it = begin;
                this->end = end;
            }
            void next(){
                this->it++;
            }
            bool hasNext() {
                return this->it != this->end;
            }
            T element() {
                return *(this->it);
            }
        private:
            It it;
            It end;
    };
}
#endif
