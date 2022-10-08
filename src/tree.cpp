#include "tree.h"

template <typename T>
void insertarNodo(Nodo<T>*& nodo, T v) {
    if (nodo == NULL) {
        nodo = new Nodo<T>();
        nodo->dato = v;
        nodo->contador = 1;
        nodo->izq = NULL;
        nodo->der = NULL;
    } else {
        if (v < nodo->dato) {
            insertarNodo<T>(nodo->izq, v);
        } else if (v > nodo->dato) {
            insertarNodo<T>(nodo->der, v);
        } else {
            nodo->contador++;
        }
    }
}

template <typename T>
void preOrden(Nodo<T>* nodo) {
    if (nodo != NULL) {
        std::cout << nodo->dato << "(" << nodo->contador << ")" << std::endl;
        preOrden<T>(nodo->izq);
        preOrden<T>(nodo->der);
    }
}

template <typename T>
void inOrden(Nodo<T>* nodo) {
    if (nodo != NULL) {
        inOrden<T>(nodo->izq);
        std::cout << nodo->dato << "(" << nodo->contador << ")" << std::endl;
        inOrden<T>(nodo->der);
    }
}

template <typename T>
void postOrden(Nodo<T>* nodo) {
    if (nodo != NULL) {
        postOrden<T>(nodo->izq);
        postOrden<T>(nodo->der);
        std::cout << nodo->dato << "(" << nodo->contador << ")" << std::endl;
    }
}
