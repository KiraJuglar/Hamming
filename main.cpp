#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

bool validarPalabras(string value)
{
    char c;
    bool flag = true;
    try {
        for (size_t i (0) ; i < value.length(); ++i)
        {
            c = value.at(i);
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

bool validarNumeros(string value)
{
    char c;
    int c2;
    bool flag = true;
    try {
        for (size_t i (0) ; i < value.length(); ++i)
        {
            c = value.at(i);
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

int convertirBinario(int value)
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

string removerEspacios (string value)
{
    string trama = "";
    for (size_t i(0) ; i < value.size() ; ++i)
    {
        if (value.at(i) != ' ')
            trama += value.at(i);
    }
    return trama;
}

int main()
{
    string tramaS;
    vector <string> v;
    bool flagP = false, flagN = false;

    do {
        cout <<"\n\t Ingresa una trama de bits: ";
        getline(cin, tramaS);
        // Remuevo espacios en la trama de bits
        tramaS = removerEspacios(tramaS);
        // Valido si existen palabras en la trama
        flagP = validarPalabras(tramaS);
        if (flagP) // Valido si solo hay valores num�ricos en la trama
            flagN = validarNumeros(tramaS);

    } while ( (flagP != true) || (flagN != true) );


    // En caso de que la trama est� completa
    if ((tramaS.size() % 2) == 0)
    {
        string b = "";
        int i = 1;
        for (size_t j (0) ; j < tramaS.size() ; ++j, ++i)
        {
            // Obtengo bit por bit
            b += tramaS.at(j);
            if ((i % 8) == 0)
            {
                // A�ado cada tramo de 8 bits en un vector
                v.push_back(b);
                b = "";
            }
        }
    }
    int data = 0;
    string cadena;
    for (size_t i(0) ; i < v.size(); ++i)
    {
        // Convierte cada tramo de 8 bits de string a int
        data = stoi(v.at(i), nullptr, 10);
        // Convierto cada tramo de 8 bits en un n�mero
        cadena += (char)convertirBinario(data);
    }
    // Salida
    cout<<"\n\t Palabra: "<<cadena<<endl;



    return 0;
}
