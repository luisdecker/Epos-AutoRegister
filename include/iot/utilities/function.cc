#ifndef API_FUNCTION_CC
#define API_FUNCTION_CC

#include "function.h"

namespace EAB {
template <typename T>
Function<T>::Function(int address, T func) {
    this->address = address;
    this->func = func;
}

template <typename T>
Function<T>::Function (const Function<T> &obj) {
    this->address = obj.address;
    this->func = obj.func;
}

template <typename T>
Function<T>::Function(int address) {
    this->address = address;
}

template <typename T>
int Function<T>::getAddress() const {
    return this->address;
}

template <typename T>
T Function<T>::getFunction() {
    return this->func;
}

template <typename T>
bool Function<T>::operator==(const Function &lhs) {
    return this->getAddress() == lhs.getAddress();
}
template <typename T>
bool Function<T>::operator!=(const Function &rhs) {
    return this->getAddress() != rhs.getAddress();
}
}

#endif
