#pragma once
#include "Clientes.h"
#include <iostream>

template <typename T, typename I>
class Remitente : public Clientes<I,T> {
private:
public:
    Remitente(Ubicacion<T> ubicacion) : Clientes<T,I>(ubicacion) {}
};

