#pragma once
#include <iostream>
template <typename T>
class Clientes {
private:
    T dni;
    T nombre;
    T celular;
public:
    void setDni(T dni) {
        if ((dni.length() != 8) || (!isdigit(dni[0]))) {
            std::cout << "Error en introducir el DNI\n";
        }
        else {
            this->dni = dni;
        }
    }

    T getDni() {
        return dni;
    }

    void setNombre(T nombre) {
        this->nombre = nombre;
    }

    T getNombre() {
        return nombre;
    }

    void setCelular(T celular) {
        if ((celular.length() != 9) || (!isdigit(celular[0]))) {
            std::cout << "Error al introducir el numero de celular\n";
        }
        else {
            this->celular = celular;
        }
    }

    T getCelular() {
        return celular;
    }
};
