#pragma once
#include "Clientes.hpp"
#include "Remitente.hpp"
#include "Destinatario.hpp"
#include "Ubicacion.hpp"
#include <iostream>
#include <string>
#include <conio.h>
template<typename T>
class Nodo {
public:
    Clientes<T>* cliente;
    Nodo<T>* siguiente;
};

template<typename T>
class ListaEnlazada {
public:
    Nodo<T>* primero;

    ListaEnlazada() : primero(nullptr) {}

    void agregarCliente(Clientes<T>* clientes) {
        Nodo<T>* nuevoNodo = new Nodo<T>();
        nuevoNodo->clientes = clientes;
        nuevoNodo->siguiente = nullptr;

        if (primero == nullptr) {
            primero = nuevoNodo;
        }
        else {
            Nodo<T>* actual = primero;
            while (actual->siguiente != nullptr) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevoNodo;
        }
    }

    void mostrarClientes() {
        Nodo<T>* actual = primero;
        while (actual != nullptr) {
            std::cout << "\n\n-----------------------";
            std::cout << "\nNombre: " << actual->cliente->getNombre();
            std::cout << "\nCodigo: " << actual->cliente->getCodigo();
            std::cout << "\nDireccion: " << actual->cliente->getDireccion();
            std::cout << "\nTelefono: " << actual->cliente->getTelefono();
            std::cout << "\nDNI: " << actual->cliente->getdocumento();
            std::cout << "\n-----------------------";
            actual = actual->siguiente;
        }
    }
};
