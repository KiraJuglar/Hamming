#include "conversorbinariotext.h"

ConversorBinarioText::ConversorBinarioText()
{
}

int ConversorBinarioText::convertirBinario(int value)
{
    int resto = 0, resultado = 0;
    int digito[8];

    for (int i(0); i < 8 ; ++i)
    {
        digito[i] = value % 10;
        value /= 10;
    }

    for (int i(7); i >= 0 ; --i)
    {
        resultado = ( resto * 2 ) + digito[i];
        resto = resultado;
    }

    return resultado;
}
