#ifndef AYED_TADS_CPP_PILA_H
#define AYED_TADS_CPP_PILA_H

template <typename T>
struct Nodo {
	T info;
	Nodo<T>* sig;
};

template <typename T>
T pop(Nodo<T>*& p);

template <typename T>
void push(Nodo<T>*& p, T v);

#endif //AYED_TADS_CPP_PILA_H
