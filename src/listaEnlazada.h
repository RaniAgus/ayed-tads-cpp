#ifndef AYED_TADS_CPP_LISTAENLAZADA_H
#define AYED_TADS_CPP_LISTAENLAZADA_H

#include <cstdlib>
#include <iostream>

template <typename T>
struct Nodo {
	T info;
	Nodo<T>* sig;
};

template <typename T>
void agregarNodo(Nodo<T>*& p, T v);

template <typename T>
void liberar(Nodo<T>*& p);

template <typename T>
T eliminarPrimerNodo(Nodo<T>*& p);

template <typename T>
void mostrar(Nodo<T>* p);

template <typename T, typename K>
T buscar(Nodo<T>* p, K v, int (*criterio)(T, K));

template <typename T>
void eliminar(Nodo<T>*& p, T v, int (*criterio)(T, T));

template <typename T>
Nodo<T>* insertarOrdenado(Nodo<T>*& p, T v, int (*criterio)(T, T));

template <typename T>
void ordenar(Nodo<T>*& p, int (*criterio)(T, T));

template <typename T>
Nodo<T>* buscaEInsertaOrdenado(Nodo<T>*& p, T v, bool& enc, int (*criterio)(T, T));

#endif //AYED_TADS_CPP_LISTAENLAZADA_H
