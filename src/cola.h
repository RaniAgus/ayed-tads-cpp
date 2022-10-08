#ifndef AYED_TADS_CPP_COLA_H
#define AYED_TADS_CPP_COLA_H

#include <cstdlib>

template <typename T>
struct Nodo {
	T info;
	Nodo<T>* sig;
};

template <typename T>
void agregar(Nodo<T>*& p, Nodo<T>*& q, T v);

template <typename T>
T suprimir(Nodo<T>*& p, Nodo<T>*& q);

#endif //AYED_TADS_CPP_COLA_H
