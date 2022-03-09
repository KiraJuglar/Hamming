#ifndef VALIDACIONES_H
#define VALIDACIONES_H

#include <iostream>

using namespace std;

class Validaciones
{
public:
    Validaciones();

    bool validarPalabra (string trama);
    bool validarNumeros (string trama);
    string removerEspacios (string trama);

private:

};

#endif // VALIDACIONES_H

