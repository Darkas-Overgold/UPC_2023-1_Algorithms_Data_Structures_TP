#pragma once
#include "ListaDobleEnlazada.h"
#include "Paquete.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
class service {
private:
    ListaDobleEnlazada<Paquete< std::string>*>* lista;
public:
    service();
    void AgregarPaquete();
    Remitente<std::string> CrearRemitente() {
        std::string dniRemitente, nombreRemitente, celularRemitente, distritoRemitente, provinciaRemitente, departamentoRemitente;
        std::cout << "Ingrese los datos del remitente:\n";
        std::cout << "DNI: ";
        std::cin >> dniRemitente;
        std::cout << "Nombre: ";
        std::cin >> nombreRemitente;
        std::cin.ignore();

        std::cout << "Celular: ";
        std::cin >> celularRemitente;
        std::cout << "Distrito: ";

        std::cin>> distritoRemitente;
        std::cin.ignore();
        std::cout << "Provincia: ";
        std::cin>> provinciaRemitente;
        std::cout << "Departamento: ";
        std::cin>> departamentoRemitente;
        Ubicacion<std::string> ubicacionRemitente(distritoRemitente, provinciaRemitente, departamentoRemitente);

        Remitente<std::string> remitente(ubicacionRemitente);
        remitente.setDni(dniRemitente);
        remitente.setNombre(nombreRemitente);
        remitente.setCelular(celularRemitente);
        

        return remitente;


    };
    Destinatario<std::string> CrearDestinatario() {
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
        std::cin>> distritoDestinatario;
        std::cout << "Provincia: ";
        std::cin>> provinciaDestinatario;
        std::cout << "Departamento: ";
        std::cin >> departamentoDestinatario;
        Ubicacion<std::string> ubicacionDestinatario(distritoDestinatario, provinciaDestinatario, departamentoDestinatario);

        Destinatario<std::string> Destinatario(ubicacionDestinatario);
        Destinatario.setDni(dniDestinatario);
        Destinatario.setNombre(nombreDestinatario);
        Destinatario.setCelular(celularDestinatario);
        Destinatario.setDireccion(direccionDestinatario);
        Destinatario.setReferencias(referenciasDestinatario);
        return  Destinatario;
    }
    
    Producto<std::string> CrearProducto() {

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
        Producto<std::string> producto(std::to_string(peso), std::to_string(alto), std::to_string(ancho), std::to_string(largo));
        return producto;
    };
    void mostrar();
    void guardar();
    ~service();

};

service::service()
{
    lista = new  ListaDobleEnlazada< Paquete< std::string>*>();

};

void service::AgregarPaquete()
{

    //datos del producto
    Remitente<std::string> remitente = CrearRemitente();
    Destinatario<std::string> Destinatario = CrearDestinatario();
    Producto<std::string> producto=CrearProducto();
    Paquete<std::string>* paquete = new Paquete<std::string>(remitente, Destinatario, producto);

    lista->agregarAlInicio(new Paquete<std::string>(remitente, Destinatario, producto));


}
void service::mostrar()
{
    
}
void service::guardar()
{
    

}
service::~service()
{
    delete lista;
}



