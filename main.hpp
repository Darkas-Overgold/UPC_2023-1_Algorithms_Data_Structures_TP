#include <iostream>
#include "ListaDobleEnlazada.hpp"
#include "Producto.hpp"
#include "Ubicacion.hpp"
#include "Destinatario.hpp"
#include "Remitente.hpp"
#include "Paquete.hpp"
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
                std::string dniRemitente, nombreRemitente, celularRemitente, distritoRemitente, provinciaRemitente, departamentoRemitente;
    std::cout << "Ingrese los datos del remitente:\n";
    std::cout << "DNI: ";
    std::cin >> dniRemitente;
    std::cout << "Nombre: ";
    std::cin.ignore();
    std::getline(std::cin, nombreRemitente);
    std::cout << "Celular: ";
    std::cin >> celularRemitente;
    std::cout << "Distrito: ";
    std::cin.ignore();
    std::getline(std::cin, distritoRemitente);
    std::cout << "Provincia: ";
    std::getline(std::cin, provinciaRemitente);
    std::cout << "Departamento: ";
    std::getline(std::cin, departamentoRemitente);
    Ubicacion<std::string> ubicacionRemitente;
    ubicacionRemitente.setDistrito(distritoRemitente);
    ubicacionRemitente.setProvincia(provinciaRemitente);
    ubicacionRemitente.setDepartamento(departamentoRemitente);
    Remitente<std::string> remitente(ubicacionRemitente);
    remitente.setDni(dniRemitente);
    remitente.setNombre(nombreRemitente);
    remitente.setCelular(celularRemitente);

    std::string dniDestinatario, nombreDestinatario, celularDestinatario, direccionDestinatario, referenciasDestinatario, distritoDestinatario, provinciaDestinatario, departamentoDestinatario;
    std::cout << "Ingrese los datos del destinatario:\n";
    std::cout << "DNI: ";
    std::cin >> dniDestinatario;
    std::cout << "Nombre: ";
    std::cin.ignore();
    std::getline(std::cin, nombreDestinatario);
    std::cout << "Celular: ";
    std::cin >> celularDestinatario;
    std::cout << "Direccion: ";
    std::cin.ignore();
    std::getline(std::cin, direccionDestinatario);
    std::cout << "Referencias: ";
    std::getline(std::cin, referenciasDestinatario);
    std::cout << "Distrito: ";
    std::getline(std::cin, distritoDestinatario);
    std::cout << "Provincia: ";
    std::getline(std::cin, provinciaDestinatario);
    std::cout <<  "Departamento: ";
    Ubicacion<std::string> ubicacionDestinatario;
    ubicacionDestinatario.setDistrito(distritoDestinatario);
    ubicacionDestinatario.setProvincia(provinciaDestinatario);
    ubicacionDestinatario.setDepartamento(departamentoDestinatario);
    Destinatario<std::string> Destinatario(ubicacionDestinatario);
    Destinatario.setDni(dniDestinatario);
    Destinatario.setNombre(nombreDestinatario);
    Destinatario.setCelular(celularDestinatario);
    Destinatario.setDireccion(direccionDestinatario);
    Destinatario.setReferencias(referenciasDestinatario);
                
                
    //datos del producto
                
    std::cout << "\nAGREGAR datos del Producto\n";
                std::cout << "Ingrese el peso (kg): ";
                double peso;
                std::cin >> peso;
                std::cout << "Ingrese la altura (cm): ";
                double alto;
                std::cin >> alto;
                std::cout << "Ingrese el ancho (cm): ";
                double ancho;
                std::cin >> ancho;
                std::cout << "Ingrese la longitud (cm): ";
                double largo;
                std::cin >> largo;
                Producto<double> producto(peso, alto, ancho, largo);
                
     
                
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
