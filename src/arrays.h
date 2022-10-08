#ifndef AYED_TADS_CPP_ARRAYS_H
#define AYED_TADS_CPP_ARRAYS_H

#include <iostream>

template <typename T>
void agregar(T arr[], int& n, T v);

template <typename T>
void mostrar(T arr[], int len);

template <typename T, typename K>
int buscar(T arr[], int len, K v, int(*criterio(T, K)));

template <typename T>
void eliminar(T arr[], int& len, int pos);

template <typename T>
void insertar(T arr[], int& len, T v, int pos);

template <typename T>
int insertarOrdenado(T arr[], int& len, T v, int(*criterio(T, T)));

template <typename T>
int buscaEInserta(T arr[], int& len, T v, bool& enc, int(*criterio(T, T)));

template <typename T>
void ordenar(T arr[], int len, int (*criterio)(T, T));

template <typename T, typename K>
int busquedaBinaria(T arr[], int len, K v, int (*criterio)(T, K), bool& enc);

#endif //AYED_TADS_CPP_ARRAYS_H
