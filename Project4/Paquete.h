#pragma once
#include <string>
#include "Producto.h"
#include "Destinatario.h"
#include "Remitente.h"
#include <iostream>
template <class T,class I>
class Paquete {
public:
    Remitente< I,T> remitente;
    Destinatario < I, T > destinatario;
    Producto<I> producto;
    

public:
    I precio;
    Paquete(){}
    Paquete(Remitente<T> remitente, Destinatario<T,I> destinatario, Producto<I> producto) :remitente(remitente), destinatario(destinatario), producto(producto) { precio = producto.precio(); };
    ~Paquete() {}
    string toString() {
        ostringstream ss;
        ss << "Paquete(";
        ss << producto.toString();
        return ss.str();
    }
    Remitente< I,T> getRemitente();
    Destinatario<T,I> getDestinatario();
    Producto<I> getProducto();
    // setters
    void setRemitente(Remitente<I,T> remitente);
    void setDestinatario(Destinatario<T,I> destinatario);
    void setProducto(Producto<I> producto);
    


};






template <class T, class I>
Remitente< I,T> Paquete<T,I>::getRemitente() {
    return remitente;
}

template <class T,class I>
Destinatario<T,I> Paquete<T, I>::getDestinatario() {
    return destinatario;
}

template <class T, class I>
Producto<I> Paquete < T, I> ::getProducto() {
    return producto;
}
template <class T, class I>
void Paquete<T, I>::setRemitente(Remitente< I,T> remitente) {
    this->remitente = remitente;
}

template <class T, class I>
void Paquete<T, I>::setDestinatario(Destinatario<T,I> destinatario) {
    this->destinatario = destinatario;
}

template <class T, class I>
void Paquete<T, I>::setProducto(Producto<I> producto) {
    this->producto = producto;
}

