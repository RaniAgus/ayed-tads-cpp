#ifndef AYED_TADS_CPP_TREE_H
#define AYED_TADS_CPP_TREE_H

#include <cstdlib>
#include <iostream>

template <typename T>
struct Nodo {
	T dato;
	int contador;
	Nodo* izq;
	Nodo* der;
};

template <typename T>
void insertarNodo(Nodo<T>*& nodo, T v);

template <typename T>
void preOrden(Nodo<T>* nodo);

template <typename T>
void inOrden(Nodo<T>* nodo);

template <typename T>
void postOrden(Nodo<T>* nodo);

#endif //AYED_TADS_CPP_TREE_H
