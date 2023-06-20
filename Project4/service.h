#pragma once
#include "ListaDobleEnlazada.h"
#include "Paquete.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Hashtable.h"
template<class T>
void OpcionesDeBusqueda(T objeto) {
    int op;
    cout << "Seleccione que quieres encontrar el objeto\n";
    cout << "1.-Precio\n";
    cout << "2.- Nombre del remitente\n";
    cout << "3.-Nombre del destinario\n";
    cin >> op;

    switch (op)
    {
    case 1:
        objeto->precio;
        break;
    case 2:
        objeto->remitente.getNombre();
        break;
    case 3:
        objeto->producto.getNombre();
    default:
        break;
    }

};


class service {
private:
    ListaDobleEnlazada<Paquete< std::string, double>*>* lista;
    HashTabla<Paquete< std::string, double>*>* hash;
    
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
    
    Producto<double> CrearProducto() {

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
        Producto<double> producto(peso, alto,ancho, largo);
        return producto;
    };
    void BuscarPorPrecio();
    void mostrar();
    void guardar();
    
    ~service();

};

service::service()
{
    lista = new  ListaDobleEnlazada< Paquete< std::string, double>*>();
    hash = new HashTabla<Paquete< std::string, double>*>();
};

void service::AgregarPaquete()
{

    //datos del producto
    Remitente<std::string> remitente = CrearRemitente();
    Destinatario<std::string> Destinatario = CrearDestinatario();
    Producto<double> producto = CrearProducto();
    Paquete<std::string, double>* paquete = new Paquete<std::string, double>(remitente, Destinatario, producto);
    
    lista->agregarAlInicio(new Paquete<std::string, double>(remitente, Destinatario, producto));
    hash->insertar(paquete->precio, paquete);
  
};
void service::BuscarPorPrecio() {
    int a;
    cout << "Ingrese el precio para buscar";
    cin >> a;
    OpcionesDeBusqueda(hash->buscar(a));


};
void service::mostrar()
{
    
}
void service::guardar()
{
    

}
service::~service()
{
    delete lista;
    delete hash;
}



