#pragma once

#include "Clientes.hpp"
#include <iostream>

template <typename T>
class Remitente : public Clientes<T> {
private:
public:
    Remitente(Ubicacion<T> ubicacion) : Clientes<T>(ubicacion) {}
};