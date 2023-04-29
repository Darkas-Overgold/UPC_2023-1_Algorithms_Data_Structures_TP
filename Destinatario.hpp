#pragma once
#include "Ubicacion.hpp"
#include <iostream>
template <typename T>
class Destinatario : public Clientes<T> {
private:
    T direccion;
    T referencias;
    Ubicacion<T> ubicacion;
public:
    void setDireccion(T direccion) {
        this->direccion = direccion;
    }

    T getDireccion() {
        return direccion;
    }

    void setReferencias(T referencias) {
        this->referencias = referencias;
    }

    T getReferencias() {
        return referencias;
    }

    void setUbicacion(Ubicacion<T> ubicacion) {
        this->ubicacion = ubicacion;
    }

    Ubicacion<T> getUbicacion() {
        return ubicacion;
    }
};
