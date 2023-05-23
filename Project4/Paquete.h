#pragma once
#include <string>
#include "Producto.h"
#include "Destinatario.h"
#include "Remitente.h"
#include <iostream>
template <class T>
class Paquete {
private:
    Remitente<T> remitente;
    Destinatario<T> destinatario;
    Producto<T> producto;

public:
    
    Paquete(Remitente<T> remitente, Destinatario<T> destinatario, Producto<T> producto):remitente(remitente),  destinatario(destinatario), producto(producto){};
    ~Paquete() {}
    string toString() {
        ostringstream ss;
        ss << "Paquete(";
        ss << producto.toString();
        return ss.str();
    }
    Remitente<T> getRemitente();
    Destinatario<T> getDestinatario();
    Producto<T> getProducto();
    // setters
    void setRemitente(Remitente<T> remitente);
    void setDestinatario(Destinatario<T> destinatario);
    void setProducto(Producto<T> producto);
    


};






template <class T>
Remitente<T> Paquete<T>::getRemitente() {
    return remitente;
}

template <class T>
Destinatario<T> Paquete<T>::getDestinatario() {
    return destinatario;
}

template <class T>
Producto<T> Paquete < T > ::getProducto() {
    return producto;
}
template <class T>
void Paquete<T>::setRemitente(Remitente<T> remitente) {
    this->remitente = remitente;
}

template <class T>
void Paquete<T>::setDestinatario(Destinatario<T> destinatario) {
    this->destinatario = destinatario;
}

template <class T>
void Paquete<T>::setProducto(Producto<T> producto) {
    this->producto = producto;
}

