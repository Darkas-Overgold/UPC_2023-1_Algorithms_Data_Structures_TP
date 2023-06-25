#pragma once

#include "ListaDobleEnlazada.h"
#include "Paquete.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Hashtable.h"
#include "ArbolBB.h"
#include "Grafos.h"
#include "DataSet.h"

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
        objeto->producto.getPeso();
    default:
        break;
    }

};


class service {
private:
    Graph graph; //Grafos para indicar las conexiones entre departamentos
    ListaDobleEnlazada<Paquete< std::string, double>*>* lista;
    HashTabla<Paquete< std::string, double>*>* hash;
    ArbolBB<Paquete< std::string, double>*>* arbol;
    
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
    void AgregarPaqueteAleatorio(short n); //n = cantidad de paquetes aleatorios a generar
    void OrdenarPaquete() {
        lista->ordenar();
    };
    void BusquedaBinariaPorDNI() {
        int a;
        cout << "\nEl numero de DNI a buscar es:";
        cin >> a;
        cout<<lista->busquedaBinaria(a);
    };
    void AgregarConexiones(); //Se utiliza grafos para indicar las conexiones entre departamenos
    void MostrarConexiones();
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
    void BuscarPorCelular();
    ~service();

};

service::service()
{
    lista = new  ListaDobleEnlazada< Paquete< std::string, double>*>();
    hash = new HashTabla<Paquete< std::string, double>*>();
    arbol= new ArbolBB<Paquete< std::string, double>*>(OpcionesDeBusqueda);
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
    arbol->insertar(paquete);
    
  
};
void service::AgregarPaqueteAleatorio(short n) {
    srand(time(NULL)); // Inicializar la semilla aleatoria

    for (short i = 0; i < n; i++) {
        // Generar valores aleatorios para los índices de los datos
        int indexDistrito = rand() % 5;
        int indexProvincia = rand() % 5;
        int indexDepartamento = rand() % 5;
        int indexCelular = rand() % 5;
        int indexDNI = rand() % 5;
        int indexNombre = rand() % 5;
        int indexReferencias = rand() % 5;
        int indexDireccion = rand() % 5;
        int indexPeso = rand() % 5;
        int indexLargo = rand() % 4;
        int indexAncho = rand() % 4;
        int indexAlto = rand() % 4;

        // Crear objetos con los valores aleatorios
        Ubicacion<std::string> ubicacion(distritos[indexDistrito], provincias[indexProvincia], departamentos[indexDepartamento]);
        Remitente<std::string> remitente(ubicacion);
        remitente.setDni(numerosDNI[indexDNI]);
        remitente.setNombre(Nombres[indexNombre]);
        remitente.setCelular(celular[indexCelular]);

        Destinatario<std::string> destinatario(ubicacion);
        destinatario.setDni(numerosDNI[indexDNI]);
        destinatario.setNombre(Nombres[indexNombre]);
        destinatario.setCelular(celular[indexCelular]);
        destinatario.setDireccion(direccion[indexDireccion]);
        destinatario.setReferencias(referencias[indexReferencias]);

        Producto<double> producto(peso[indexPeso], largo[indexLargo], ancho[indexAncho], alto[indexAlto]);

        //Crear paquete y agregarlo a la lista y hash
        Paquete<std::string, double>* paquete = new Paquete<std::string, double>(remitente, destinatario, producto);
        lista->agregarAlInicio(paquete);
        hash->insertar(paquete->precio, paquete);
        arbol->insertar(paquete);
    }
}

void service::AgregarConexiones() {
    //Agregar departamentos a grafos
    for (short i = 0; i < 5; i++) {
        std::string aux = departamentos[i];
        graph.addVertex(aux);
    }

    //Agregar arcos
    graph.addEdge(departamentos[0], departamentos[1]);
    graph.addEdge(departamentos[0], departamentos[4]);
    graph.addEdge(departamentos[1], departamentos[3]);
    graph.addEdge(departamentos[2], departamentos[1]);
    graph.addEdge(departamentos[3], departamentos[0]);
    graph.addEdge(departamentos[3], departamentos[4]);
    graph.addEdge(departamentos[3], departamentos[2]);
}

void service::MostrarConexiones() {
    graph.printGraph();
}
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
void service::BuscarPorCelular()
{
    int a;
    cout << "ingrese el numero de celular a buscar";
    cin >> a;
    
    arbol->BusquedaPorCelular(a);
}
service::~service()
{
    delete arbol;
    delete lista;
    delete hash;
}



