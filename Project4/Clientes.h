#pragma once
#include "Ubicacion.h"
#include <iostream>

template <typename T,typename I>
class Clientes {
protected:
    T dni;
    I nombre;
    T celular;
    Ubicacion<T> ubicacion;
public:
    Clientes(Ubicacion<T> ubicacion):ubicacion(ubicacion) {
    }
    

    ~Clientes() {}


    void setCelular(T celular);
    void setDni(T dni);
    void setNombre(I nombre);

    T getCelular();
    T getDni();
    T getNombre();
    Ubicacion<T> getUbicacion();

};
//Setters
template <typename T, typename I>
void Clientes<T,I>::setCelular(T celular) {
    
        this->celular = celular;
    
}
template <typename T, typename I>
void Clientes<T,I>::setDni(T dni) {
    if ((dni.length() != 8) || (!isdigit(dni[0]))) {
        std::cout << "Error en introducir el DNI\n";
    }
    else {
        this->dni = dni;
    }
}
template <typename T, typename I>
void Clientes<T,I>::setNombre(I nombre) {
    this->nombre = nombre;
}
//Getters
template <typename T, typename I>
T Clientes<T,I>::getCelular() {
    return celular;
}
template <typename T, typename I>
T Clientes<T,I>::getDni() {
    return dni;
}
template <typename T, typename I>
T Clientes<T,I>::getNombre() {
    return nombre;
}
template <typename T, typename I>
Ubicacion<T> Clientes<T,I>::getUbicacion() {
    return ubicacion;
}

