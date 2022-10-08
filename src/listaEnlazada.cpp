#include "listaEnlazada.h"

// Básicas
template <typename T>
void agregarNodo(Nodo<T>*& p, T v) {
    Nodo<T>* nuevo = new Nodo<T>();
    nuevo->info = v;
    nuevo->sig = NULL;
    if (p == NULL) {
        p = nuevo;
    } else {
        Nodo<T>* aux = p;
        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

template <typename T>
void liberar(Nodo<T>*& p) {
    Nodo<T>* aux;
    while (p != NULL) {
        aux = p;
        p = p->sig;
        delete aux;
    }
}

template <typename T>
T eliminarPrimerNodo(Nodo<T>*& p) {
    T ret = p->info;
    Nodo<T>* aux = p;
    p = p->sig;
    delete aux;
    return ret;
}

// Complejas
// Mostrar
template <typename T>
void mostrar(Nodo<T>* p) {
    Nodo<T>* aux = p;
    while (aux != NULL) {
        std::cout << aux->info << std::endl;
        aux = aux->sig;
    }
}

// Buscar
template <typename T, typename K>
T buscar(Nodo<T>* p, K v, int (*criterio)(T, K)) {
    Nodo<T>* aux = p;
    while (aux != NULL && criterio(aux->info, v) != 0) {
        aux = aux->sig;
    }
    return aux = NULL ? -1 : aux->info;
}

// Eliminar
template <typename T>
void eliminar(Nodo<T>*& p, T v, int (*criterio)(T, T)) {
    Nodo<T>* aux = p;
    Nodo<T>* ant = NULL;
    while (aux != NULL && criterio(aux->info, v) != 0) {
        ant = aux;
        aux = aux->sig;
    }
    if (ant != NULL) {
        ant->sig = aux->sig;
    } else {
        p = aux->sig;
    }
    delete aux;
}

// Insertar Ordenado
template <typename T>
Nodo<T>* insertarOrdenado(Nodo<T>*& p, T v, int (*criterio)(T, T)) {
    Nodo<T>* nuevo = new Nodo<T>();
    nuevo->info = v;
    nuevo->sig = NULL;
    Nodo<T>* ant = NULL;
    Nodo<T>* aux = p;
    while (aux != NULL && criterio(aux->info, v) <= 0) {
        ant = aux;
        aux = aux->sig;
    }
    if (ant == NULL) {
        p = nuevo;
    } else {
        ant->sig = nuevo;
    }
    nuevo->sig = aux;
    return nuevo;
}

// Ordenar
template <typename T>
void ordenar(Nodo<T>*& p, int (*criterio)(T, T)) {
    Nodo<T>* q = NULL;
    while (p != NULL) {
        T v = eliminarPrimerNodo<T>(p);
        insertarOrdenado<T>(q, v, criterio);
    }
    p = q;
}

// Busca e inserta ordenado
template <typename T>
Nodo<T>* buscaEInsertaOrdenado(Nodo<T>*& p, T v, bool& enc, int (*criterio)(T, T)) {
    Nodo<T>* x = buscar<T, T>(p, v);
    enc = x != NULL;
    if (!enc) {
        x = insertarOrdenado<T>(p, v, criterio);
    }
    return x;
}
