template <typename T>
struct Nodo {
    T dato;
    int contador;
    Nodo* izq;
    Nodo* der;
};

template <typename T>
void insertarNodo(Nodo<T>*& nodo, T v) {
    if (nodo == NULL) {
        nodo = new Nodo<T>();
        nodo->dato = v;
        nodo->contador = 1;
        nodo->izq = NULL;
        nodo->der = NULL;
    } else {
        if (v < nodo->dato) {
            insertarNodo<T>(nodo->izq, v);
        } else if (v > nodo->dato) {
            insertarNodo<T>(nodo->der, v);
        } else {
            nodo->contador++;
        }
    }
}

template <typename T>
void preOrden(Nodo<T>* nodo) {
    if (nodo != NULL) {
        cout << nodo->dato << "(" << nodo->contador << ")" << endl;
        preOrden<T>(nodo->izq);
        preOrden<T>(nodo->der);
    }
}

template <typename T>
void inOrden(Nodo<T>* nodo) {
    if (nodo != NULL) {
        inOrden<T>(nodo->izq);
        cout << nodo->dato << "(" << nodo->contador << ")" << endl;
        inOrden<T>(nodo->der);
    }
}

template <typename T>
void postOrden(Nodo<T>* nodo) {
    if (nodo != NULL) {
        postOrden<T>(nodo->izq);
        postOrden<T>(nodo->der);
        cout << nodo->dato << "(" << nodo->contador << ")" << endl;
    }
}
