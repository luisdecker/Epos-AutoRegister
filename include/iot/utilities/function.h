#ifndef API_FUNCTION_H
#define API_FUNCTION_H

namespace EAB {
template <typename T> class Function {
protected:
    int address;
    T func;

public:
    Function(int address, T func);

    Function(int address);

    Function (const Function &obj);


    int getAddress() const;

    T getFunction();

    inline bool operator==(const Function &lhs);
    inline bool operator!=(const Function &rhs);
};
}
#endif
