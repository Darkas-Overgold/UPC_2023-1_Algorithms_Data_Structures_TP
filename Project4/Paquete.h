#pragma once
#include <string>
#include "Producto.h"
#include "Destinatario.h"
#include "Remitente.h"
#include <iostream>
template <class T,class I>
class Paquete {
private:
    Remitente<T> remitente;
    Destinatario<T> destinatario;
    Producto<I> producto;
    

public:
    I precio;
    
    Paquete(Remitente<T> remitente, Destinatario<T> destinatario, Producto<I> producto) :remitente(remitente), destinatario(destinatario), producto(producto) { precio = producto.precio(); };
    ~Paquete() {}
    string toString() {
        ostringstream ss;
        ss << "Paquete(";
        ss << producto.toString();
        return ss.str();
    }
    Remitente<T> getRemitente();
    Destinatario<T> getDestinatario();
    Producto<I> getProducto();
    // setters
    void setRemitente(Remitente<T> remitente);
    void setDestinatario(Destinatario<T> destinatario);
    void setProducto(Producto<I> producto);
    


};






template <class T, class I>
Remitente<T> Paquete<T,I>::getRemitente() {
    return remitente;
}

template <class T,class I>
Destinatario<T> Paquete<T, I>::getDestinatario() {
    return destinatario;
}

template <class T, class I>
Producto<I> Paquete < T, I> ::getProducto() {
    return producto;
}
template <class T, class I>
void Paquete<T, I>::setRemitente(Remitente<T> remitente) {
    this->remitente = remitente;
}

template <class T, class I>
void Paquete<T, I>::setDestinatario(Destinatario<T> destinatario) {
    this->destinatario = destinatario;
}

template <class T, class I>
void Paquete<T, I>::setProducto(Producto<I> producto) {
    this->producto = producto;
}

