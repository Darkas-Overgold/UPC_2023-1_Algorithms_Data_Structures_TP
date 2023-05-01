#include "ListaEnlazada.hpp"
#include <iostream>
#include <string>


int main() {/*
    Remitente<std::string> remitente;
    Destinatario<std::string> destinatario;

    remitente.setDni("12345678");
    remitente.setNombre("Juan Perez");
    remitente.setCelular("987654321");
    Ubicacion<std::string> ubicacionRemitente;
    ubicacionRemitente.setDistrito("San Isidro");
    ubicacionRemitente.setProvincia("Lima");
    ubicacionRemitente.setDepartamento("Lima");
    remitente.setUbicacion(ubicacionRemitente);


    destinatario.setDni("1234567a");
    destinatario.setNombre("Maria Garcia");
    destinatario.setCelular("98765432a");
    Ubicacion<std::string> ubicacionDestinatario;
    ubicacionDestinatario.setDistrito("Miraflores");
    std::cout << "Remitente:\n";
    std::cout << "Dni: " << remitente.getDni() << std::endl;
    std::cout << "Nombre: " << remitente.getNombre() << std::endl;
    std::cout << "Celular: " << remitente.getCelular() << std::endl;
    std::cout << "Ubicacion:\n";
    std::cout << "Distrito: " << remitente.getUbicacion().getDistrito() << std::endl;
    std::cout << "Provincia: " << remitente.getUbicacion().getProvincia() << std::endl;
    std::cout << "Departamento: " << remitente.getUbicacion().getDepartamento() << std::endl;*/

    ListaEnlazada<std::string, float> list;
    //Destinatario
    Ubicacion<std::string> ubicacion;
    ubicacion.setDistrito("Miraflores");
    ubicacion.setProvincia("Lima");
    ubicacion.setDepartamento("Lima");

    Destinatario<std::string>* destinatario = new Destinatario<std::string>(ubicacion);
    destinatario->setDni("123456");
    destinatario->setNombre("JuanPerez");
    destinatario->setCelular("982765431");
    destinatario->setDireccion("Av. Pardo 123");
    destinatario->setReferencias("Cerca al Parque Kennedy");
    //Remitente
    Ubicacion<std::string> ubicacion2;
    ubicacion2.setDistrito("Lince");
    ubicacion2.setProvincia("LD");
    ubicacion2.setDepartamento("ASDma");

    Remitente<std::string>* remitente = new Remitente<std::string>(ubicacion);
    remitente->setCelular("987456123");
    remitente->setDni("9123722");
    remitente->setNombre("Espantaviejas");
    //Paquete
    Paquete<float>* paquete = new Paquete<float>(70.7, 13.4, 10.5, 10.9);

    list.agregarElemento(destinatario, remitente, paquete);
    list.mostrarElemento();

    _getch();
    return 0;
}