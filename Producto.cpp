template<typename T>
class Producto {
protected:
    T alto;
    T ancho;
    T largo;
    T peso;
public:
    Producto(T peso, T alto, T ancho, T largo);
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
