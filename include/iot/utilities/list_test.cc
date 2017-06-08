#include "list_app.cc"

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
    ListApp<Pessoa> *lista = new ListApp<Pessoa>();
    lista->insert(p1);
    lista->insert(p2);
    lista->insert(p3);
    lista->remove(p1);
    int c = 0;
    Pessoa *i = new Pessoa[2];
    i[0] = p2;
    i[1] = p3;
    for(ListInterface<Pessoa>::Iterator *it = lista->iterator(); it->hasNext(); it->next()) {
        if (i[c].getName() != it->element().getName()) {
            cout << "Expected: '" << i[c].getName() << "' - received: '" << it->element().getName() << "'" << endl;
            return 1;
        }
        cout << i[c].getName() << endl;
        c++;
    }
    delete lista;
    delete i;
    return 0;
}
