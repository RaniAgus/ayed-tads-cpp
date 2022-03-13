template <typename T>
struct ListaDoblementeEnlazada {
    Nodo*<T> primero;
    Nodo*<T> ultimo;
};

template <typename T>
struct Nodo {
    T elem;
    Nodo*<T> ant;
    Nodo*<T> sig;
};

// Inicialización
template <typename T>
void inicializar(Nodo<T>* &primero, Nodo<T>* &ultimo) {
    *primero = new Nodo<T>();
    primero->ant = NULL;

    *ultimo = new Nodo<T>();
    ultimo->sig = NULL;
    primero->sig = ultimo;
    ultimo->ant = primero;
}


// Básicas
template <typename T>
void agregar(Nodo<T>*& ultimo, T e) {
    Nodo<T>* nuevo = new Nodo<T>();
    nuevo->elem = e;
    nuevo->sig = ultimo;
    nuevo->ant = ultimo->ant;

    Nodo<T>* pre = ultimo->ant;
    ultimo->ant = nuevo;
    pre->sig = nuevo;
}

template <typename T>
void eliminar(Nodo<T>* objetivo) {
    Nodo<T>* pre = objetivo->ant;
    Nodo<T>* pro = objetivo->sig;
    pre->sig = pro;
    pro->ant = pre;
    delete objetivo;
}

// Manejo listas doblemente enlazadas
// Mostrar
template <typename T>
void mostrar(Nodo<T>* primero, void (*mostrarLinea)(T, T)) {
    Nodo<T>* aux = primero->sig;
    while (aux->sig != NULL) {
        mostrarLinea(aux->info);
        aux = aux->sig;
    }
    return;
}

// Vacia
template <typename T>
bool vacia(Nodo<T>* primero) {
    Nodo<T>* aux = primero->sig;
    return aux->sig == NULL ? true : false;
}

// Frente
template <typename T>
T frente(Nodo<T>* primero) {
    Nodo<T>* aux = primero->sig;
    return aux->info;
}

// Insertar Ordenado
template <typename T>
void insertarOrdenado(Nodo<T>* cabecera, T v, int(*criterio)(T, T)) {
    Nodo<T>* nuevo = new Nodo<T>();
    nuevo->info = v;
    Nodo<T>* aux = primero->sig;
    while (aux->sig != NULL && criterio(aux->info, v) <= 0) {
        aux = aux->sig;
    }
    nuevo->sig = aux;
    nuevo->ant = aux->ant;
    aux->ant = nuevo;
    aux = nuevo->ant;
    aux->sig = nuevo;
    return;
}

// Buscar en Lista
template <typename T>
Nodo<T>* buscarEnLista(Nodo<T>* p, T v, int (*criterio)(T, T)) {
    Nodo<T>* aux = p;
    while (aux != NULL && criterio(aux->info, v) != 0) {
        aux = aux->sig;
    }
    return aux;
}
