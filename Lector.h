#ifndef LECTOR_H
#define LECTOR_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include "Contacto.h"

class Lector
{
    public:
        Lector();
        bool leerArchivo();
        void actualizarContacto();
        bool nuevoContacto(Contacto);
        void eliminarContacto();
    private:
        int localizarContacto( std::string );
        bool cambioContacto( int );

};

#endif // LECTOR_H
