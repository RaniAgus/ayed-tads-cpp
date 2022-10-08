#ifndef AYED_TADS_CPP_ARCHIVOS_H
#define AYED_TADS_CPP_ARCHIVOS_H

#include <iostream>

template <typename T>
void write(FILE* f, T v);

template <typename T>
T read(FILE* f);

template <typename T>
void seek(FILE* f, int n);

template <typename T>
int filePos(FILE* f);

template <typename T>
int fileSize(FILE* f);

template <typename T, typename K>
int busquedaBinaria(FILE* f, K v, int (*criterio)(T, K));

#endif //AYED_TADS_CPP_ARCHIVOS_H
