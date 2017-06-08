#include <utility/ostream.h>
#include "comm/objects/smartobject.h"
#include <gpio.h>

using namespace EPOS;

OStream cout;

int main() {
    GPIO led('C', 3, GPIO::OUT);
    led.set(1);
    const char * nome = "Nome";
    SmartObject s(nome);
    while (1) {
        cout << s.getName();
    }
    return 0;
}