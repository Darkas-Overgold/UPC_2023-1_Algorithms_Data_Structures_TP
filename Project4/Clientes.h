#pragma once
#include "Ubicacion.h"
#include <iostream>

template <typename T>
class Clientes {
protected:
    T dni;
    T nombre;
    T celular;
    Ubicacion<T> ubicacion;
public:
    Clientes(Ubicacion<T> ubicacion):ubicacion(ubicacion) {
    }
    

    ~Clientes() {}


    void setCelular(T celular);
    void setDni(T dni);
    void setNombre(T nombre);

    T getCelular();
    T getDni();
    T getNombre();
    Ubicacion<T> getUbicacion();

};
//Setters
template <typename T>
void Clientes<T>::setCelular(T celular) {
    
        this->celular = celular;
    
}
template <typename T>
void Clientes<T>::setDni(T dni) {
    if ((dni.length() != 8) || (!isdigit(dni[0]))) {
        std::cout << "Error en introducir el DNI\n";
    }
    else {
        this->dni = dni;
    }
}
template <typename T>
void Clientes<T>::setNombre(T nombre) {
    this->nombre = nombre;
}
//Getters
template <typename T>
T Clientes<T>::getCelular() {
    return celular;
}
template <typename T>
T Clientes<T>::getDni() {
    return dni;
}
template <typename T>
T Clientes<T>::getNombre() {
    return nombre;
}
template <typename T>
Ubicacion<T> Clientes<T>::getUbicacion() {
    return ubicacion;
}

