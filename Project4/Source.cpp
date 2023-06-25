#include <iostream>
#include "service.h"
#include <string>
#include <sstream>

int main() {
    service servicio;

    int opcion;
    short aux;
    do {
        do {
            system("cls");
            std::cout << "----- MENU -----" << std::endl;
            std::cout << "1. Agregar paquete (manualmente)" << std::endl;
            std::cout << "2. Agregar paquete (aleatoriamente)" << std::endl;
            std::cout << "3. Mostrar la conexion entre departamentos" << std::endl;
            std::cout << "3. Mostrar la conexion entre departamentos" << std::endl;
            std::cout << "4. Buscar por precio del paquete." << std::endl;
            std::cout << "5. Buscar por el numero de celular." << std::endl;
            std::cout << "6. Ordenar por los precios." << std::endl;
            std::cout << "7. Buscar por numero de DNI." << std::endl;
            std::cout << "8. Salir" << std::endl;
            std::cout << "Ingrese una opción: ";
            std::cin >> opcion;
        } while (!(opcion > 0 && opcion < 6));
        switch (opcion) {
        case 1:
            servicio.AgregarPaquete();


            system("pause>null");
            break;
        case 2: {
            std::cout << "Ingrese cantidad de paquetes a insertar: "; std::cin >> aux;
            servicio.AgregarPaqueteAleatorio(aux);
            //std::cout << "Creando....."; _sleep(150);
            system("pause>null");
            break;
        }
        case 3:
            servicio.MostrarConexiones();
            system("pause>null");
            return main();
            break;
        case 4:
            servicio.BuscarPorPrecio();
            break;
        case 5:
            servicio.BuscarPorCelular();
            break;
        case 6:
            servicio.OrdenarPaquete();
            break;
        case 7:
            servicio.BusquedaBinariaPorDNI();
            break;
        case 8:
            std::cout << "Saliendo..." << std::endl;
            break;
        default:
            std::cout << "Opción inválida. Intente nuevamente." << std::endl;
            break;
        }

        std::cout << std::endl;
    } while (opcion != 4);




    return 0;
}
