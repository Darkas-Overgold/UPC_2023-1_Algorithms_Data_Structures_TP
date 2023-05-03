#pragma once

#include "Producto.hpp"
#include "Destinatario.hpp"
#include "Remitente.hpp"

#include <iostream>
#include <string>
#include <conio.h>

template<typename T, typename F>
class Paquete {
public:
    //Objetos que irian dentro de cada Paquete 
    Destinatario<T>* destinatario;
    Remitente<T>* remitente;
    Producto<F>* producto;

    Paquete<T, F>* siguiente;
};

template<typename T, typename F>
class ListaEnlazada {
public:
    Paquete<T, F>* primero; //Primer elemento de la lista

    ListaEnlazada() : primero(nullptr) {}
    void agregarElemento(Destinatario<T>* dest, Remitente<T>* rem, Producto<F>* prod);
   
    void mostrarLista();
    void mostrarListaRecursiva(Paquete<T, F>* nodoActual);

    void ordenarElementosPorPrecio(short n);


};

template<typename T, typename F>
void ListaEnlazada<T, F>::agregarElemento(Destinatario<T>* dest, Remitente<T>* rem, Producto<F>* prod) {

    Paquete<T, F>* nuevoPaquete = new Paquete<T, F>();
    nuevoPaquete->destinatario = dest;
    nuevoPaquete->remitente = rem;
    nuevoPaquete->producto = prod;
    nuevoPaquete->siguiente = nullptr;

    if (primero == nullptr) {
        primero = nuevoPaquete;
    }
    else {
        Paquete<T, F>* actual = primero;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoPaquete;
    }
}

// Función pública para llamar a la función privada recursiva
template<typename T, typename F>
void ListaEnlazada<T, F>::mostrarLista() {
    mostrarListaRecursiva(primero);
}

template<typename T, typename F>
void ListaEnlazada<T, F>::mostrarListaRecursiva(Paquete<T, F>* nodoActual) {
    if (nodoActual == nullptr) {
        return;
    }
    else {
        std::cout << "\n************DESTINATARIO************\n";
        std::cout << "\nNombre: " << nodoActual->destinatario->getNombre();
        std::cout << "\nDNI: " << nodoActual->destinatario->getDni();
        std::cout << "\nCelular: " << nodoActual->destinatario->getCelular();
        std::cout << "\nDistrito: " << nodoActual->destinatario->getUbicacion().getDistrito();
        std::cout << "\nProvincia: " << nodoActual->destinatario->getUbicacion().getProvincia();
        std::cout << "\nDepartamento: " << nodoActual->destinatario->getUbicacion().getDepartamento();
        std::cout << "\n---------------------------------------";
        std::cout << "\n************REMITENTE************\n";
        std::cout << "\nNombre: " << nodoActual->remitente->getNombre();
        std::cout << "\nDNI: " << nodoActual->remitente->getDni();
        std::cout << "\nCelular: " << nodoActual->remitente->getCelular();
        std::cout << "\nDistrito: " << nodoActual->remitente->getUbicacion().getDistrito();
        std::cout << "\nProvincia: " << nodoActual->remitente->getUbicacion().getProvincia();
        std::cout << "\nDepartamento: " << nodoActual->remitente->getUbicacion().getDepartamento();
        std::cout << "\n---------------------------------------";
        std::cout << "\n************Producto************\n";
        std::cout << "\nAlto: " << nodoActual->producto->getAlto();
        std::cout << "\nAncho: " << nodoActual->producto->getAncho();
        std::cout << "\nLargo: " << nodoActual->producto->getLargo();
        std::cout << "\nPeso: " << nodoActual->producto->getPeso();
        std::cout << "\nPrecio: " << nodoActual->producto->getPrecio();
        std::cout << "\n---------------------------------------";

        mostrarListaRecursiva(nodoActual->siguiente);
    }
}

template<typename T, typename F>
void ListaEnlazada<T, F>::ordenarElementosPorPrecio(short n) {
    bool intercambiado = false;

    Paquete<T, F>* actual = primero;
    Paquete<T, F>* ptr1 = nullptr;
    Paquete<T, F>* lptr = nullptr;

    // Repetir el proceso n veces
    for (int i = 0; i < n; i++) {
        ptr1 = actual;
        intercambiado = false;

        // Realizar una pasada completa a través de la lista
        while (ptr1->siguiente != lptr) {
            // Comparar los elementos adyacentes
            if (ptr1->producto->getPrecio() > ptr1->siguiente->producto->getPrecio()) {
                // Intercambiar los elementos
                Producto<F>* temp = ptr1->producto;
                ptr1->producto = ptr1->siguiente->producto;
                ptr1->siguiente->producto = temp;
                intercambiado = true;
            }
            ptr1 = ptr1->siguiente;
        }

        // Si no se han realizado intercambios, la lista está ordenada
        if (intercambiado == false)
            break;
    }
}
