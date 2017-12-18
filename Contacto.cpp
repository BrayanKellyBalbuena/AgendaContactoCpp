#include "Contacto.h"
#include <iostream>
#include <iomanip>


using namespace std;

Contacto::Contacto( string posicioN, string nombre, string telefono)
{
    setNombre( nombre );
    setTelefono( telefono );
    posicion = posicioN;
}



Contacto::~Contacto()
{

}

void Contacto::setNombre( string nombreN )
{
    if ( nombreN.empty() )
        nombre = "";
    else
        nombre = nombreN;
}

string Contacto::getNombre()
{
    return nombre;
}

void Contacto::setTelefono( string telefonoN )
{
    if ( telefonoN.empty() )
        telefono="";
    else
        telefono = telefonoN;
}

std::string Contacto::getTelefono()
{
    return telefono;
}


std::string Contacto::getPosicion()
{
    return posicion;
}


void Contacto::setPosicion(std::string posic)
{
    posicion = posic;
}


