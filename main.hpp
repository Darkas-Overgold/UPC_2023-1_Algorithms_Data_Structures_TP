#include <iostream>
#include "ListaDobleEnlazada.hpp"
#include "Producto.hpp"

int main() {
    ListaDobleEnlazada<Producto<int>> lista;

    int opcion;
    do {
        std::cout << "Seleccione una opcion:\n"
                  << "1. Agregar producto\n"
                  << "2. Mostrar productos\n"
                  << "3. Salir\n";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                int peso, alto, ancho, largo;
                std::cout << "Ingrese el peso del producto: ";
                std::cin >> peso;
                std::cout << "Ingrese la altura del producto: ";
                std::cin >> alto;
                std::cout << "Ingrese el ancho del producto: ";
                std::cin >> ancho;
                std::cout << "Ingrese la longitud del producto: ";
                std::cin >> largo;

                Producto<int> producto(peso, alto, ancho, largo);
                lista.agregar(producto);

                std::cout << "Producto agregado correctamente\n";
                break;
            }
            case 2: {
                if (lista.estaVacia()) {
                    std::cout << "La lista esta vacia\n";
                } else {
                    std::cout << "Productos almacenados:\n";
                    Nodo<Producto<int>>* actual = lista.getPrimero();
                    while (actual != nullptr) {
                        std::cout << "Peso: " << actual->getValor().getPeso()
                                  << ", alto: " << actual->getValor().getAlto()
                                  << ", ancho: " << actual->getValor().getAncho()
                                  << ", largo: " << actual->getValor().getLargo() << "\n";
                        actual = actual->getSiguiente();
                    }
                }
                break;
            }
            case 3:
                std::cout << "Saliendo del programa...\n";
                break;
            default:
                std::cout << "Opcion invalida\n";
                break;
        }
    } while (opcion != 3);

    return 0;
}
