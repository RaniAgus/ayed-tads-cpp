#include "cola.h"

template <typename T>
void agregar(Nodo<T>*& p, Nodo<T>*& q, T v) {
    Nodo<T>* nuevo = new Nodo<T>();
    nuevo->info = v;
    nuevo->sig = NULL;
    if (p == NULL) {
        p = nuevo;
    } else {
        q->sig = nuevo;
    }
    q = nuevo;
}

template <typename T>
T suprimir(Nodo<T>*& p, Nodo<T>*& q) {
    T ret = p->info;
    Nodo<T>* aux = p;
    p = p->sig;
    if (p == NULL) {
        q = NULL;
    }
    delete aux;
    return ret;
}
