#include "Clientes.h"
#include <iostream>

template <typename T, typename I>
class Destinatario : public Clientes<I,T> {
private:
    T direc;
    T referencias;
public:
    Destinatario(Ubicacion<T> ubicacion=nullptr) : Clientes<I,T>(ubicacion) {}

    void setDireccion(T direccion);
    void setReferencias(T referencias);
    T getDireccion();
    T getReferencias();

};
template <typename T, typename I>
void Destinatario<T,I>::setDireccion(T direccion) { this->direc = direccion; }
template <typename T, typename I>
void Destinatario<T, I>::setReferencias(T referencias) { this->referencias = referencias; }
template <typename T, typename I>
T Destinatario<T, I>::getDireccion() { return direc; }
template <typename T, typename I>
T Destinatario<T, I>::getReferencias() { return referencias; }