#include <iostream>

template <typename T>
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

template <typename T>
class ListaDobleEnlazada {
private:
    Nodo<T>* cabeza;
    Nodo<T>* cola;
public:
    ListaDobleEnlazada() {
        cabeza = nullptr;
        cola = nullptr;
    }

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
};

