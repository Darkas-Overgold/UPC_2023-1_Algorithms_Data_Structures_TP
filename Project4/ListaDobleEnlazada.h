#pragma once
template <class T>
class Nodo {
public:
    T dato;
    Nodo<T>* siguiente;
    Nodo<T>* anterior;

    Nodo(T dato) {
        this->dato = dato;
        siguiente = nullptr;
        anterior = nullptr;
    }
};
template<class T>
class Iterator {
private:
    unsigned int pos;
    Nodo<T>* aux;
public:
    Iterator(unsigned int pos, Nodo<T>* aux) : pos(pos), aux(aux) {}
    void operator ++() { pos++; aux = aux->siguiente; }
    bool operator !=(Iterator x) { return pos != x.pos; }
    T operator *() { return aux->dato; }
};

template <class T>
class ListaDobleEnlazada {
private:
    Nodo<T>* cabeza;
    Nodo<T>* cola;
public:
    ListaDobleEnlazada() {
        cabeza = nullptr;
        cola = nullptr;
    }
    Nodo<T>* getCabeza() {
        return cabeza;
    };
    bool estaVacia() {
        return cabeza == nullptr;
    }
    void agregarAlInicio(T dato) {
        Nodo<T>* nuevoNodo = new Nodo<T>(dato);
        if (estaVacia()) {
            cola = nuevoNodo;
        }
        else {
            cabeza->anterior = nuevoNodo;
            nuevoNodo->siguiente = cabeza;
        }
        cabeza = nuevoNodo;
    }
    Iterator<T> begin() {
        return Iterator<T>(0, cabeza);
    }
    Iterator<T> end() {
        return Iterator<T>(size(), nullptr);
    }

    void agregarAlFinal(T dato) {
        Nodo<T>* nuevoNodo = new Nodo<T>(dato);
        if (estaVacia()) {
            cabeza = nuevoNodo;
        }
        else {
            cola->siguiente = nuevoNodo;
            nuevoNodo->anterior = cola;
        }
        cola = nuevoNodo;
    }

    void eliminarAlInicio() {
        if (!estaVacia()) {
            Nodo<T>* nodoAEliminar = cabeza;
            if (cabeza == cola) {
                cola = nullptr;
            }
            else {
                cabeza->siguiente->anterior = nullptr;
            }
            cabeza = cabeza->siguiente;
            delete nodoAEliminar;
        }
    }

    void eliminarAlFinal() {
        if (!estaVacia()) {
            Nodo<T>* nodoAEliminar = cola;
            if (cabeza == cola) {
                cabeza = nullptr;
            }
            else {
                cola->anterior->siguiente = nullptr;
            }
            cola = cola->anterior;
            delete nodoAEliminar;
        }
    }

    void mostrarAdelante() {
        Nodo<T>* nodoActual = cabeza;
        while (nodoActual != nullptr) {
            std::cout << nodoActual->dato << " ";
            nodoActual = nodoActual->siguiente;
        }
        std::cout << std::endl;
    }

    void mostrarAtras() {
        Nodo<T>* nodoActual = cola;
        while (nodoActual != nullptr) {
            std::cout << nodoActual->dato << " ";
            nodoActual = nodoActual->anterior;
        }
        std::cout << std::endl;
    }
    void ordenar() {
        if (estaVacia() || cabeza == cola) {
            return;  // La lista está vacía o tiene un solo elemento, no hay nada que ordenar
        }

        quicksort(cabeza, cola);
    }

    void quicksort(Nodo<T>* izquierda, Nodo<T>* derecha) {
        if (izquierda != nullptr && derecha != nullptr && izquierda != derecha && izquierda->anterior != derecha) {
            Nodo<T>* pivot = particionar(izquierda, derecha);

            // Ordenar recursivamente los subarreglos antes y después del pivote
            if (pivot != nullptr && pivot->anterior != nullptr) {
                quicksort(izquierda, pivot->anterior);
            }
            if (pivot != nullptr && pivot->siguiente != nullptr) {
                quicksort(pivot->siguiente, derecha);
            }
        }
    }

    Nodo<T>* particionar(Nodo<T>* izquierda, Nodo<T>* derecha) {
        T pivot = derecha->dato;
        Nodo<T>* i = izquierda->anterior;

        for (Nodo<T>* j = izquierda; j != derecha; j = j->siguiente) {
            if (j->dato->precio <= pivot->precio) {
                i = (i == nullptr) ? izquierda : i->siguiente;
                intercambiarNodos(i, j);
            }
        }

        i = (i == nullptr) ? izquierda : i->siguiente;
        intercambiarNodos(i, derecha);

        return i;
    }

    void intercambiarNodos(Nodo<T>* nodo1, Nodo<T>* nodo2) {
        if (nodo1 != nullptr && nodo2 != nullptr && nodo1 != nodo2) {
            T temp = nodo1->dato;
            nodo1->dato = nodo2->dato;
            nodo2->dato = temp;
        }
    }
    Nodo<T>* busquedaBinaria(int b) {
        T valorBuscado = cabeza->dato;
        valorBuscado->getDestinatario().setDni(to_string(b));
        
        Nodo<T>* izquierda = cabeza;
        Nodo<T>* derecha = cola;

        while (izquierda != nullptr && derecha != nullptr && izquierda != derecha && izquierda->anterior != derecha) {
            Nodo<T>* medio = izquierda;
            int i = 0;
            while (medio != nullptr && i < ((derecha->dato->getDestinatario().getDni() - izquierda->dato->getDestinatario().getDni()) / 2)) {
                medio = medio->siguiente;
                i++;
            }

            if (medio->dato->getDestinatario().getDni() == valorBuscado) {
                return medio;
            }
            else if (medio->dato->getDestinatario().getDni() < valorBuscado) {
                izquierda = medio->siguiente;
            }
            else {
                derecha = medio->anterior;
            }
        }

        return nullptr; // No se encontró el valor buscado
    }
    
};


