#include "mutex_app.cc"

int main(void) {
    MutexApp *m = new MutexApp();
    m->lock();
    m->unlock();
    delete m;
}
