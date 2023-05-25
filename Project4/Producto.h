
#pragma once

#include <sstream>
#include <iostream>
using namespace std;
template<typename T>
class Producto {
protected:
    T alto;
    T ancho;
    T largo;
    T peso;
public:
    
    Producto(T peso, T alto, T ancho, T largo);
    T precio() {
        T precio = (2.0 * alto) + (2.0 * ancho) + (2.0 * largo) + (3.0 * peso);
        return precio;
    };
    string toString() {
        ostringstream ss;
        ss << peso;
        return ss.str();


    };
    ~Producto() {}

    T getPeso();
    T getAlto();
    T getAncho();
    T getLargo();

};

template<typename T>
Producto<T>::Producto(T peso, T alto, T ancho, T largo) {
    this->peso = peso;
    this->alto = alto;
    this->ancho = ancho;
    this->largo = largo;
}

template<typename T>
T Producto<T>::getPeso() {
    return peso;
}

template<typename T>
inline T Producto<T>::getAlto()
{
    return alto;
}

template<typename T>
inline T Producto<T>::getAncho()
{
    return ancho;
}

template<typename T>
inline T Producto<T>::getLargo()
{
    return largo;
}
