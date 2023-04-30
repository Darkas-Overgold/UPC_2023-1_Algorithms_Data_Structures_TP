#include <iostream>
#include "Producto.hpp"

template<typename T>

class Paquete : public Producto<T> {
private:
    T precio; //T = float :v
public:
    Paquete(T peso, T alto, T ancho, T largo);
    ~Paquete() {}

    T getPrecio();
};

template<typename T>
Paquete<T>::Paquete(T peso, T alto, T ancho, T largo) : Producto<T>(peso, alto, ancho, largo) {
    precio = (2.0 * alto) + (2.0 * ancho) + (2.0 * largo) + (3.0 * peso);
}

template<typename T>
T Paquete<T>::getPrecio() {
    return precio;
}
