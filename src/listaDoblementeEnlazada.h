#ifndef AYED_TADS_CPP_LISTADOBLEMENTEENLAZADA_H
#define AYED_TADS_CPP_LISTADOBLEMENTEENLAZADA_H

#include <cstdlib>

template <typename T>
struct Nodo {
	T elem;
	Nodo<T>* ant;
	Nodo<T>* sig;
};

template <typename T>
struct ListaDoblementeEnlazada {
	Nodo<T>* primero;
	Nodo<T>* ultimo;
};

template <typename T>
void inicializar(Nodo<T>* &primero, Nodo<T>* &ultimo);

template <typename T>
void agregar(Nodo<T>*& ultimo, T e);

template <typename T>
void eliminar(Nodo<T>* objetivo);

template <typename T>
void mostrar(Nodo<T>* primero, void (*mostrarLinea)(T, T));

template <typename T>
bool vacia(Nodo<T>* primero);

template <typename T>
T frente(Nodo<T>* primero);

template <typename T>
void insertarOrdenado(Nodo<T>* cabecera, T v, int(*criterio)(T, T));

template <typename T>
Nodo<T>* buscarEnLista(Nodo<T>* p, T v, int (*criterio)(T, T));

#endif //AYED_TADS_CPP_LISTADOBLEMENTEENLAZADA_H
