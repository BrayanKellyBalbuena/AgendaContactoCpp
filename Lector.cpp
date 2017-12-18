#include "Lector.h"

using namespace std;

Lector::Lector()
{
    //ctor
}

//metodo que muestra todos los datos
bool Lector::leerArchivo()
{
    ifstream enContactoArchivo( "contactos.dat", ios::in );

    if(!enContactoArchivo )
        return true;

    string posicion = "";
    string nombre ="";
    string telefono = "";

     cout << left << setw( 14 )<<"|Posicion|"<<setw( 13 )<<"|Nombre|"
            << setw( 7 )<<setprecision( 2 )<<right << "|Telefono|\n" <<endl;
    while(enContactoArchivo >> posicion >> nombre >> telefono )
    {
        cout << left << setw( 14 )<<posicion<<setw( 13 )<<nombre
            << setw( 7 )<<setprecision( 2 )<<right << telefono << endl;
    }
    return false;
}

bool Lector::cambioContacto(int posicion)
{
    string nombre ="";
    string telefono = "";

    fstream cambiarEnArchivo("contactos.dat", ios::in | ios::out | ios::binary );
    if ( !cambiarEnArchivo )
    {
        if( cambiarEnArchivo.eof() )
        {
            cout << "No hay datos que mostrar" << endl;
        }
        cerr << "No se pudo abrir el archivo." << endl;
        return true;
    }

    cin.ignore();

    cout << "Digite el nombre: ";
    cin >> nombre;
    cout << "Digite el  telefono: ";
    cin >> telefono;

    stringstream stream;
    stream << posicion;
    string posicionString = stream.str();
    Contacto contacto( posicionString ,nombre,telefono);

    cambiarEnArchivo.seekp (posicion - 1); //posiciona sobre el archivo actual
    cambiarEnArchivo << contacto.getPosicion() << ' ' << contacto.getNombre() << ' '
        << contacto.getTelefono() << endl;

    cambiarEnArchivo.close();
    return false;
}

int Lector::localizarContacto( string posicion )
{
    int contador = 0;
    string bufferCedula ="";
    string nombre = "";
    string telefono="";

    ifstream enContactoArchivo( "contactos.dat", ios::in );

    if ( !enContactoArchivo )
    {
         cout << "Problemas leiendo el archivo\n" << endl;
         return 0;
    }
    while ( enContactoArchivo >> bufferCedula  >> nombre >> telefono )
    {
        contador++;
        if ( posicion == bufferCedula )
        {
            cout << "\nCliente encontrado: " << nombre << endl;
            enContactoArchivo.close();
            return contador;
        }
    }
    enContactoArchivo.close();
    return 0;
}

//metodo permiter actualizar un contacto

void Lector::actualizarContacto()
{
    string cedulaBuscada="";
    int ubicacion=0;

    if( leerArchivo())
    {
        cout << "No hay archivo que actualizar" << endl;
        return;
    }
    cout << "\nDigite la posicion del contacto a actualizar: ";
    cin >> cedulaBuscada;

    ubicacion = localizarContacto( cedulaBuscada );

    if ( ubicacion )
    {
        if ( cambioContacto ( ubicacion ) )
          cout << "\n\nEl contacto se ha modificaco con exito" << endl;
    }
    else
        cout << "\n\nEl contacto no existe en el archivo" << endl;
}

//metodo Agregar un nuevo contacto

bool Lector::nuevoContacto(Contacto contacto)
{
    ofstream insertarEnArchivo("contactos.dat", ios::app);
    if ( !insertarEnArchivo )
    {
        return true;
    }

    cin.ignore();
    insertarEnArchivo << contacto.getPosicion() << ' ' << contacto.getNombre() << ' '
        << contacto.getTelefono() << endl;

    insertarEnArchivo.close();
    return false;
}


//Implementacion del metodo eliminar
void Lector::eliminarContacto()
{
    if( leerArchivo())
    {
        cout << "No hay contacto que eliminar" << endl;
        return;
    }

    string posicionBuscada="";
    string nombre ="";
    string telefono = "";
    string posicion="";

    cout << "\nDigite la posicion del contacto a eliminar: ";
    cin >> posicionBuscada;

    if ( localizarContacto( posicionBuscada ) )
    {
       fstream archivoLectura("contactos.dat",ios::in | ios::out | ios::binary);
       ofstream archivoEscritura( "auxiliar.dat", ios::out );

       if ( !archivoLectura || !archivoEscritura )
       {
           cout << "Problemas con el archivo de lectura";
           return ;
       }

       while( archivoLectura >> posicion >> nombre >> telefono )
       {
           if ( posicion == posicionBuscada ){}
                //has nada
           else
           {
               archivoEscritura << posicion << ' ' << nombre << ' ' << telefono << endl;
           }
       }

       archivoEscritura.close();
       archivoLectura.close();
       remove("contactos.dat");
       rename( "auxiliar.dat", "contactos.dat" );

       cout << "\n\nEl contacto se ha eliminado con exito" << endl;
       return;
    }
    else
        cout << "\n\nEl contacto no existe en el archivo" << endl;
}




