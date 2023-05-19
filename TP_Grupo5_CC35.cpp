#include "ListaEnlazada.hpp"
#include <conio.h>
#include <iostream>
#include <string>


int main() {
    //Lista enlazada de paquetes
    ListaEnlazada<std::string, float> list;
    //cantidad de elementos
    short n;
    short opc;
    short i; //Para los ciclos for

    //variables para almacenar datos
    std::string a = "asds", b = "asds", c = "asds", d = "12345678", e = "Sebastian Paredes", f = "912345678", g = "asds", h = "asds"; //Destinatario
    std::string j = "asds", k = "asds", l = "asds", m = "12345678", o = "Juan Perez", p = "912345678"; //Remitente
    float x, y, z, w; //Producto


    do {
        std::cout << "Ingrese la cantidad de paquetes que desea registrar (0-390): "; std::cin >> n;
    } while (!(n > 0 && n < 390));

    do {
        system("cls");
        do {
            int spd = 6;
            char s = spd;
            std::string a; //Ingresar variables string
            short b; //ingresar el ID (entero)
            setlocale(LC_ALL, "esp");
            std::cout << "\n\n..................................................." << std::endl;
            std::cout << "........ Bienvenidos a Silver Star Sending ........" << std::endl;
            std::cout << "..................................................." << std::endl;
            std::cout << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << std::endl;
            std::cout << s << " Digite la accion que desea realizar             " << s << std::endl;
            std::cout << s << " 1. Registrar nuevo paquete a base de datos      " << s << std::endl;
            std::cout << s << " 2. Ordenar registro por precio                  " << s << std::endl;
            std::cout << s << " 3. Ordenar registro por peso                    " << s << std::endl;
            std::cout << s << " 4. Mostrar paquetes registrados                 " << s << std::endl;
            std::cout << s << " 5. Salir                                        " << s << std::endl;
            std::cout << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << s << std::endl;
            std::cin >> opc;
        } while (!(n > 0 && n < 6));

        switch (opc) {
        case 1:
            for (i = 0; i < n; i++) {
                //Ubicacion de destinatario
                Ubicacion<std::string> ubicacion;
                std::cout << "\n***************************DESTINATARIO INFORMACION****************************\n";
                std::cout << "Ingrese el departamento del destinatario: "; /*std::cin >> a*/; ubicacion.setDepartamento(a);
                std::cout << "Ingrese la provincia del destinatario: "; //std::cin >> b; 
                ubicacion.setProvincia(b);
                std::cout << "Ingrese el distrito del destinatario: "; //std::cin >> c; 
                ubicacion.setDistrito(c);
                //Destinatario Informacion
                Destinatario<std::string>* destinatario = new Destinatario<std::string>(ubicacion);
                std::cout << "Ingrese el DNI : "; //std::cin >> d; 
                //std::cin.ignore(); 
                destinatario->setDni(d);
                std::cout << "Ingrese nombre completo de destinatario: "; //getline(std::cin, e);
                destinatario->setNombre(e);
                std::cout << "Ingrese numero de celular: "; //std::cin >> f; 
                destinatario->setCelular(f);
                std::cout << "Ingrese la direccion de domicilio: "; //std::cin >> g; 
                destinatario->setDireccion(g);
                std::cout << "Ingrese alguna referencia de domicilio: "; //std::cin >> h;
                destinatario->setReferencias(h);

                //Ubicacion de remitente
                Ubicacion<std::string> ubicacion2;
                std::cout << "\n***************************REMITENTE INFORMACION****************************\n";
                std::cout << "Ingrese el departamento del remitente: "; //std::cin >> j; 
                ubicacion2.setDepartamento(j);
                std::cout << "Ingrese la provincia del remitente: "; //std::cin >> k; 
                ubicacion2.setProvincia(k);
                std::cout << "Ingrese el distrito del remitente: "; //std::cin >> l; 
                ubicacion2.setDistrito(l);
                //Remitente informacion
                Remitente<std::string>* remitente = new Remitente<std::string>(ubicacion2);
                std::cout << "Ingrese el DNI: "; //std::cin >> m; 
                //std::cin.ignore(); 
                remitente->setDni(m);
                std::cout << "Ingrese nombre completo de remitente: "; //getline(std::cin, o); 
                remitente->setNombre(o);
                std::cout << "Ingrese numero de celular de remitente: "; //std::cin >> p; 
                remitente->setCelular(p);

                //Producto Informacion
                std::cout << "\n***************************PRODUCTO INFORMACION****************************\n";
                std::cout << "Ingrese peso del producto: "; std::cin >> x;
                std::cout << "\nIngrese alto del producto: "; std::cin >> y;
                std::cout << "\nIngrese ancho del producto: "; std::cin >> z;
                std::cout << "\nIngrese largo del producto: "; std::cin >> w;
                Producto<float>* producto = new Producto<float>(x, y, z, w);

                //Se agrega un paquete
                list.agregarElemento(destinatario, remitente, producto);
            }
            break;
        case 2:
            list.ordenarElementosPorPrecio(n);
            system("pause>null"); break;

        case 3:
            list.ordenarElementosPorPeso(n);
            system("pause>null"); break;

        case 4:
            list.mostrarLista(n);
            system("pause>null"); break;
        }

    } while (opc != 5);
    _getch();
    return 0;
}
