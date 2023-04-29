#pragma once
#include <iostream>
template <typename T>
class Ubicacion {
private:
    T distrito;
    T provincia;
    T departamento;
public:
    void setDistrito(T distrito) {
        if (isdigit(distrito[0])) {
            std::cout << "Hay un error en la digitacion por favor reinicie el programa\n";
        }
        else {
            this->distrito = distrito;
        }
    }

    T getDistrito() {
        return distrito;
    }

    void setProvincia(T provincia) {
        if (isdigit(provincia[0])) {
            std::cout << "Hay un error en la digitacion por favor reinicie el programa\n";
        }
        else {
            this->provincia = provincia;
        }
    }

    T getProvincia() {
        return provincia;
    }

    void setDepartamento(T departamento) {
        if (isdigit(departamento[0])) {
            std::cout << "Hay un error en la digitacion por favor reinicie el programa\n";
        }
        else {
            this->departamento = departamento;
        }
    }

    T getDepartamento() {
        return departamento;
    }
};
