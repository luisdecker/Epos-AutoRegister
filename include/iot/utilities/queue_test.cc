#include "queue_app.cc"
#include "queue.h"

#ifndef SIMULATE
#include <utility/ostream.h>
using EPOS::endl;
EPOS::OStream cout;
#else
#include <iostream>
using std::cout;
using std::endl;
#endif

class Pessoa {
private:
    const char *name;
public:
    Pessoa(const char *name) {
        this->name = name;
    }
    Pessoa() {}
    const char* getName() const {
        return this->name;
    }
    inline bool operator==(const Pessoa& lhs){
        return lhs.getName() == this->getName();
    }

};
int main(int argc, char **argv) {
    Pessoa p1("Mota");
    Pessoa p2("Podestá");
    Pessoa p3("Cancian");
    QueueInterface<Pessoa> *fila = new QueueApp<Pessoa>();
    if (!fila->empty()) {
        return 1;
    }
    fila->insert(p1);
    fila->insert(p2);
    fila->insert(p3);
    if (fila->empty()) {
        return 2;
    }
    if(fila->remove().getName() != p1.getName()) {
        return 3;
    }
    if (fila->size() != 2) {
        return 4;
    }
    delete fila;
    return 0;
}
