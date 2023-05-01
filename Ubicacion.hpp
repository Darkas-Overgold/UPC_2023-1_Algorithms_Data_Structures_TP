#pragma once

#include <iostream>

template <typename T>
class Ubicacion {
private:
    T distrito;
    T provincia;
    T departamento;
public:
    void setDistrito(T distrito);
    void setDepartamento(T departamento);
    void setProvincia(T provincia);

    T getProvincia();
    T getDistrito();
    T getDepartamento();
}; 
//Setters
template <typename T>
void Ubicacion<T>::setDistrito(T distrito) {
    if (isdigit(distrito[0])) {
        std::cout << "Hay un error en la digitacion por favor reinicie el programa\n";
    }
    else {
        this->distrito = distrito;
    }
}
template <typename T>
void Ubicacion<T>::setDepartamento(T departamento) {
    if (isdigit(departamento[0])) {
        std::cout << "Hay un error en la digitacion por favor reinicie el programa\n";
    }
    else {
        this->departamento = departamento;
    }
}
template <typename T>
void Ubicacion<T>::setProvincia(T provincia) {
    if (isdigit(provincia[0])) {
        std::cout << "Hay un error en la digitacion por favor reinicie el programa\n";
    }
    else {
        this->provincia = provincia;
    }
}
//Getters
template <typename T>
T Ubicacion<T>::getProvincia() { return provincia; }
template <typename T>
T Ubicacion<T>::getDistrito() { return distrito; }
template <typename T>
T Ubicacion<T>::getDepartamento() { return departamento; }