#pragma once
#include "Producto.hpp"
#include "Destinatario.hpp"
#include "Remitente.hpp"

template<typename T>
class Paquete : public Producto<T> {
private:
    Remitente<T> *remitente;
    Destinatario<T> *destinatario;
public:
    Paquete(T peso, T alto, T ancho, T largo, Clientes<T> *remitente, Destinatario<T> *destinatario)
        : Producto<T>(peso, alto, ancho, largo) {
        this->remitente = remitente;
        this->destinatario = destinatario;
    }
    ~Paquete() {}

    // Método para calcular el precio
    T calcularPrecio() {
        return (2.0 * this->alto) + (2.0 * this->ancho) + (2.0 * this->largo) + (3.0 * this->peso);
    }

    // Getters y setters
   Remitente<T>* getRemitente() {
        return remitente;
    }

    void setRemitente(Remitente<T> *remitente) {
        this->remitente = remitente;
    }

    Destinatario<T>* getDestinatario() {
        return destinatario;
    }

    void setDestinatario(Destinatario<T> *destinatario) {
        this->destinatario = destinatario;
    }
};
