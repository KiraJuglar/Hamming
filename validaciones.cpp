#include "validaciones.h"

Validaciones::Validaciones()
{
}

bool Validaciones::validarPalabra(string trama)
{
    char c;
    bool flag = true;
    try {
        for (size_t i (0) ; i < trama.length(); ++i)
        {
            c = trama.at(i);
            if ( !isdigit(c) )
            {
                flag = false;
                break;
            }
       }
    }  catch (exception e) {
        cout<<"\n\t Ingresa una trama valida";
        flag = false;
    }
    return flag;
}

bool Validaciones::validarNumeros(string trama)
{
    char c;
    int c2;
    bool flag = true;
    try {
        for (size_t i (0) ; i < trama.length(); ++i)
        {
            c = trama.at(i);
            c2 = (int)c;
            if ( c2 != 48 && c2 != 49)
            {
                flag = false;
                break;
            }
       }
    }  catch (exception e) {
        cout<<"\n\t Ingresa una trama valida";
        flag = false;
    }
    return flag;
}

string Validaciones::removerEspacios(string trama)
{
    string value = "";
    for (size_t i(0) ; i < trama.size() ; ++i)
    {
        if (trama.at(i) != ' ')
            value += trama.at(i);
    }
    return value;
}
