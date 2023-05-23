#include <iostream>
#include "service.h"
#include <string>
#include <sstream>

int main() {
    service servicio;

    int opcion;
    do {
        std::cout << "----- MENU -----" << std::endl;
        std::cout << "1. Agregar paquete" << std::endl;
        std::cout << "2. Cargar dataset" << std::endl;
        std::cout << "3. Guardar dataset" << std::endl;
        std::cout << "4. Salir" << std::endl;
        std::cout << "Ingrese una opción: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            servicio.AgregarPaquete();
            
            
            return main();
            break;
        case 2: {
            
            break;
        }
        case 3:
            
            
            return main();
            break;
        case 4:
            std::cout << "Saliendo..." << std::endl;
            break;
        default:
            std::cout << "Opción inválida. Intente nuevamente." << std::endl;
            break;
        }

        std::cout << std::endl;
    } while (opcion != 3);

        
     

    return 0;
}
