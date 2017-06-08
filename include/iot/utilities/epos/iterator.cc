#ifndef EPOS_ITERATOR
#define EPOS_ITERATOR

#include "../iterator.h"
#include <utility/list.h>
namespace EAB {
    template <typename T>
    class IteratorAbstraction : public IteratorInterface<T> {
        public:
            typedef typename EPOS::List<T>::Iterator It;

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
                T *v = this->it->object();
                return *v;
            }
        private:
            It it;
            It end;
    };
}
#endif
