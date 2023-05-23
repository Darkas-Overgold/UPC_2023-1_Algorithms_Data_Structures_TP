#include "Clientes.h"
#include <iostream>

template <typename T>
class Destinatario : public Clientes<T> {
private:
    T direc;
    T referencias;
public:
    Destinatario(Ubicacion<T> ubicacion=nullptr) : Clientes<T>(ubicacion) {}

    void setDireccion(T direccion);
    void setReferencias(T referencias);
    T getDireccion();
    T getReferencias();

};
template <typename T>
void Destinatario<T>::setDireccion(T direccion) { this->direc = direccion; }
template <typename T>
void Destinatario<T>::setReferencias(T referencias) { this->referencias = referencias; }
template <typename T>
T Destinatario<T>::getDireccion() { return direc; }
template <typename T>
T Destinatario<T>::getReferencias() { return referencias; }