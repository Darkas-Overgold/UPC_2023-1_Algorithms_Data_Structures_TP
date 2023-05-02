#pragma once
#include "Producto.hpp"
#include "Destinatario.hpp"
#include "Remitente.hpp"

template <typename T>
class Paquete {
private:
    Remitente<T> remitente;
    Destinatario<T> destinatario;
    Producto<T> producto;
public:
    Paquete(Remitente<T> remitente, Destinatario<T> destinatario, Producto<T> producto);
    ~Paquete() {}
    Remitente<T> getRemitente();
    Destinatario<T> getDestinatario();
    Producto<T> getProducto();
};

template <typename T>
Paquete<T>::Paquete(Remitente<T> remitente, Destinatario<T> destinatario, Producto<T> producto) {
    this->remitente = remitente;
    this->destinatario = destinatario;
    this->producto = producto;
}

template <typename T>
Remitente<T> Paquete<T>::getRemitente() {
    return remitente;
}

template <typename T>
Destinatario<T> Paquete<T>::getDestinatario() {
    return destinatario;
}

template <typename T>
Producto<T> Paquete<T>::getProducto() {
    return producto;
}
