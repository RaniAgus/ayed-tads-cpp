#include <iostream>

using namespace std;

// Básicas
template <typename T>
void write(FILE* f, T v) {
    fwrite(&v, sizeof(T), 1, f);
    return;
}

template <typename T>
T read(FILE* f) {
    T buff;
    fread(&buff, sizeof(T), 1, f);
    return buff;
}

// Manejo de archivos
template <typename T>
void seek(FILE* f, int n) {
    fseek(f, n * sizeof(T), SEEK_SET);
    return;
}

template <typename T>
int filePos(FILE* f) {
    return ftell(f) / sizeof(T);
}

template <typename T>
int fileSize(FILE* f) {
    long pos = ftell(f);

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, pos, SEEK_SET);

    return size / sizeof(T);
}

// Búsqueda binaria en archivos
template <typename T, typename K>
int busquedaBinaria(FILE* f, K v, int (*criterio)(T, K)) {
    int i = 0;
    int j = fileSize<T>(f) - 1;
    int k = (i + j) / 2;
    seek<T>(f, k);
    T r = read<T>(f);
    while (i <= j && criterio(r, v) != 0) {
        if (criterio(r, v) > 0) {
            j = k - 1;
        } else {
            if (criterio(r, v) < 0) {
                i = k + 1;
            }
        }
        k = (i + j) / 2;
        seek<T>(f, k);
        r = read<T>(f);
    }
    return i <= j ? k : -1;
}
