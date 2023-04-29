#pragma once
#include "Ubicacion.hpp"
#include <iostream>
template <typename T>
class Remitente : public Clientes<T> {
private:
    Ubicacion<T> ubicacion;
public:
    void setUbicacion(Ubicacion<T> ubicacion) {
        this->ubicacion = ubicacion;
    }

    Ubicacion<T> getUbicacion() {
        return ubicacion;
    }
};
