#ifndef INGRESODATOS_H
#define INGRESODATOS_H

#include <iostream>
#include <string>
#include <vector>
#include "conversorbinariotext.h"
#include "validaciones.h"

using namespace std;

class ingresoDatos
{
public:
    ingresoDatos();

    string ingresarTrama();
    string ingresarTramaError();
    void mostrarPalabra(string trama);
private:

};

#endif // INGRESODATOS_H

