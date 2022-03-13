template <typename T>
struct Nodo {
    T info;
    Nodo<T>* sig;
};

template <typename T>
T pop(Nodo<T>*& p) {
    T v;
    Nodo<T>* aux = p;
    v = aux->info;
    p = aux->sig;
    delete aux;
    return v;
}

template <typename T>
void push(Nodo<T>*& p, T v) {
    Nodo<T>* aux = new Nodo<T>();
    aux->info = v;
    aux->sig = p;
    p = aux;
    return;
}
