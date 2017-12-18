#include <iostream>
#include <cstdlib>
#include "Lector.h"

using namespace std;

enum Opciones { IMPRIMIR = 1, NUEVO, ACTUALIZAR, ELIMINAR, TERMINAR};
Lector lector;

void agregarContaco()
{
    cout << "\t\t=================================================" << endl;
    cout << "\t\t||   AGREGAR UN NUEVO CONTACTO A LA AGENDAS    ||" << endl;
    cout << "\t\t==================================================\n\n" << endl;
    string posicion = "";
    string nombre ="";
    string telefono = "";
    cout << "Digite la posicion: ";
    cin >> posicion;
    cout << "Digite el nombre: ";
    cin >> nombre;
    cout << "Digite el  telefono: ";
    cin >> telefono;

    Contacto contacto(posicion,nombre,telefono);


    if ( lector.nuevoContacto(contacto) )
        cerr << "\nNo se pudo agregar el contacto." << endl;
    else
       cout << "\nContacto agregado satisfactoriamente\n";
}
int escribirOpcion()
{
    cout << "\t\t===========================================" << endl;
    cout << "\t\t||    BIENVENIDO AL GESTOR DE AGENDAS    ||" << endl;
    cout << "\t\t===========================================\n\n" << endl;

    cout <<"1- Mostrar contactos" << endl
        <<"2- agregar un nuevo contacto" << endl
        <<"3- actualizar un  contacto" << endl
        <<"4- eliminar un contacto << " << endl
        <<"5- fin del programa\n" << endl
        << "Escriba su opcion: ";


     int opcionMenu;
     cin >> opcionMenu;
     return opcionMenu;
}

int main()
{
    int opcion;

    while ( ( opcion = escribirOpcion() ) != TERMINAR )
    {
        switch ( opcion )
        {
            case IMPRIMIR:
                system( "cls" );
                cout << "\t\t===================================" << endl;
                cout << "\t\t||    CONTACTOS EN LA AGENDAS    ||" << endl;
                cout << "\t\t====================================\n\n" << endl;
                if ( lector.leerArchivo())
                    cout << "No hay datos que mostrar" << endl;
                system("pause");
                system( "cls" );
                break;
            case NUEVO:
                system( "cls" );
                agregarContaco();
                system( "pause" );
                system("cls");
                break;
            case ACTUALIZAR:
                system("cls");
                 cout << "\t\t===================================================" << endl;
                cout << "\t\t||   ACTUALIZAR UN NUEVO CONTACTO A LA AGENDAS   ||" << endl;
                cout << "\t\t===================================================\n\n" << endl;
                lector.actualizarContacto();
                system("pause");
                system("cls");
                break;
            case ELIMINAR:
                system("cls");
                cout << "\t\t=================================================" << endl;
                cout << "\t\t||   ELIMINAR UN NUEVO CONTACTO A LA AGENDAS   ||" << endl;
                cout << "\t\t==================================================\n\n" << endl;
                lector.eliminarContacto();
                system("pause");
                system("cls");
                break;
            default:
                cerr << "Opcion incorrecta" << endl;
                system("pause");
                system("cls");
                break;
        }

    }
    return 0;
}


