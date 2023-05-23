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

        bool intercambioRealizado;
        do {
            intercambioRealizado = false;
            for (Iterator<T> it = begin(); it != end(); ++it) {
                if (*it > *(it + 1)) {
                    // Intercambiar los datos de los nodos
                    T temp = *it;
                    *it = *(it + 1);
                    *(it + 1) = temp;
                    intercambioRealizado = true;
                }
            }
        } while (intercambioRealizado);
    }

};


