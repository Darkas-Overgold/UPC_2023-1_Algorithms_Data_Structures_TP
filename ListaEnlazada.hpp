#pragma once

#include "Paquete.hpp"
#include "Destinatario.hpp"
#include "Remitente.hpp"

#include <iostream>
#include <string>
#include <conio.h>

template<typename T, typename F>
class Nodo {
public:
    //Objetos que irian dentro de cada Nodo 
    Destinatario<T>* destinatario;
    Remitente<T>* remitente;
    Paquete<F>* paquete;

    Nodo<T, F>* siguiente;
};

template<typename T, typename F>
class ListaEnlazada {
public:
    Nodo<T, F>* primero; //Primer elemento de la lista

    ListaEnlazada() : primero(nullptr) {}
    void agregarElemento(Destinatario<T>* dest, Remitente<T>* rem, Paquete<F>* paqu);
    void mostrarElemento();
};

template<typename T, typename F>
void ListaEnlazada<T, F>::agregarElemento(Destinatario<T>* dest, Remitente<T>* rem, Paquete<F>* paqu) {

    Nodo<T, F>* nuevoNodo = new Nodo<T, F>();
    nuevoNodo->destinatario = dest;
    nuevoNodo->remitente = rem;
    nuevoNodo->paquete = paqu;
    nuevoNodo->siguiente = nullptr;

    if (primero == nullptr) {
        primero = nuevoNodo;
    }
    else {
        Nodo<T, F>* actual = primero;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
    }
}
template<typename T, typename F>
void ListaEnlazada<T, F>::mostrarElemento() {
    Nodo<T, F>* actual = primero;
    while (actual != nullptr) {
        std::cout << "\n************REMITENTE************\n";
        std::cout << "\nNombre: " << actual->remitente->getNombre();
        std::cout << "\nDNI: " << actual->remitente->getDni();
        std::cout << "\nCelular: " << actual->remitente->getCelular();
        std::cout << "\nDistrito: " << actual->remitente->getUbicacion().getDistrito();
        std::cout << "\nProvincia: " << actual->remitente->getUbicacion().getProvincia();
        std::cout << "\nDepartamento: " << actual->remitente->getUbicacion().getDepartamento();
        std::cout << "\n---------------------------------------";
        std::cout << "\n************DESTINATARIO************\n";
        std::cout << "\nNombre: " << actual->destinatario->getNombre();
        std::cout << "\nDNI: " << actual->destinatario->getDni();
        std::cout << "\nCelular: " << actual->destinatario->getCelular();
        std::cout << "\nDistrito: " << actual->destinatario->getUbicacion().getDistrito();
        std::cout << "\nProvincia: " << actual->destinatario->getUbicacion().getProvincia();
        std::cout << "\nDepartamento: " << actual->destinatario->getUbicacion().getDepartamento();
        std::cout << "\n---------------------------------------";
        std::cout << "\n************PAQUETE************\n";
        std::cout << "\nPrecio: " << actual->paquete->getPrecio();
        std::cout << "\n---------------------------------------";
        actual = actual->siguiente;
    }
}