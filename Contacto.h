#ifndef CONTACTO_H
#define CONTACTO_H
#include <string>
#include <exception>


class Contacto
{
    public:

        Contacto( std::string posicion = "" ,std::string nombre = "", std::string telefono = "");
        virtual ~Contacto();
        void setNombre( std::string );
        std::string getNombre();
        void setTelefono( std::string );
        std::string getTelefono();
        std::string getPosicion();
        void setPosicion( std::string );
    private:
        std::string nombre;
        std::string telefono;
        std::string posicion;
};

#endif // CONTACTO_H
