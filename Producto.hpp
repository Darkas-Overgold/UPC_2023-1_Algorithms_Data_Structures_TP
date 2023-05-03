#include <iostream>

template<typename T>
class Producto  {
private:
    T alto;
    T ancho;
    T largo;
    T peso;

    T precio; //T = float :v
public:
    Producto(T peso, T alto, T ancho, T largo);
    ~Producto() {}

    T getPeso();
    T getAlto();
    T getAncho();
    T getLargo();

    T getPrecio();
};

template<typename T>
Producto<T>::Producto(T peso, T alto, T ancho, T largo) {
    this->peso = peso;
    this->alto = alto;
    this->ancho = ancho;
    this->largo = largo;
    //Lambda
    precio = [=]() -> T { return (2 * peso) + (2 * alto) + (1.5 * ancho) + (1.5 * largo); }();
}
template<typename T>
T Producto<T>::getPeso() {
    return peso;
}

template<typename T>
T Producto<T>::getAlto() {
    return alto;
}

template<typename T>
T Producto<T>::getAncho() {
    return ancho;
}

template<typename T>
T Producto<T>::getLargo() {
    return largo;
}

template<typename T>
T Producto<T>::getPrecio() {
    return precio;
}
