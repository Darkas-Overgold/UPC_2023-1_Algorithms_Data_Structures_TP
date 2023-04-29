#include "ListaEnlazada.hpp"
#include <iostream>
#include <string>

int main() {
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
    std::cout << "Departamento: " << remitente.getUbicacion().getDepartamento() << std::endl;
    _getch();
    return 0;
}
