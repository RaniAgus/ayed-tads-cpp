#include <iostream>

using namespace std;

// Agregar
template <typename T>
void agregar(T arr[], int& len, T v) {
    arr[len] = v;
    len++;
    return;
}

// Mostrar
template <typename T>
void mostrar(T arr[], int len) {
    for (int i = 0; i < len; i++) {
        cout << arr[i] << endl;
    }
    return;
}

// Buscar
template <typename T, typename K>
int buscar(T arr[], int len, K v, int(*criterio(T, K))) {
    int i = 0;
    while (i < len && criterio(arr[i], v) != 0) {
        i++;
    }
    return i < len ? i : -1;
}

// Eliminar
template <typename T>
void eliminar(T arr[], int& len, int pos) {
    for (int i = pos; i < len - 1; i++) {
        arr[i] = arr[i + 1];
    }
    len--;
    return;
}

// Insertar
template <typename T>
void insertar(T arr[], int& len, T v, int pos) {
    for (int i = len - 1; i >= pos; i--) {
        arr[i + 1] = arr[i];
    }
    arr[pos] = v;
    len++;
    return;
}

// Insertar Ordenado
template <typename T>
int insertarOrdenado(T arr[], int& len, T v, int(*criterio(T, T))) {
    int i = 0;
    while (i < len && criterio(arr[i], v) <= 0) {
        i++;
    }
    insertar<T>(arr, len, v, i);
    return i;
}

// Busca e Inserta
template <typename T>
int buscaEInserta(T arr[], int& len, T v, bool& enc, int(*criterio(T, T))) {
    int pos = buscar<T, T>(arr, len, v, criterio);
    enc = pos >= 0;
    if (!enc) {
        pos = insertarOrdenado(arr, len, v, criterio);
    }
    return pos;
}

// Ordenar
template <typename T>
void ordenar(T arr[], int len, int (*criterio)(T, T)) {
    bool ordenado = false;
    while (!ordenado) {
        ordenado = true;
        for (int i = 0; i < len - 1; i++) {
            if (criterio(arr[i], arr[i + 1]) > 0) {
                T aux = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = aux;
                ordenado = false;
            }
        }
    }
}

// Búsqueda binaria
template <typename T, typename K>
int busquedaBinaria(T arr[], int len, K v, int (*criterio)(T, K), bool& enc) {
    int i = 0;
    int j = len - 1;
    int k = (i + j) / 2;
    enc = false;
    while (i <= j && !enc) {
        if (criterio(arr[k], v) > 0) {
            j = k - 1;
        } else {
            if (criterio(arr[k], v) < 0) {
                i = k + 1;
            } else {
                enc = true;
            }
        }
        k = (i + j) / 2;
    }
    return criterio(arr[k], v) >= 0 ? k : k + 1;
}
