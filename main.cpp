#include <iostream>
#include <string>
#include <cstdlib>

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

int main()
{

    string tramaS;
    bool flagP = false, flagN = false;
    do {
        cout <<"\n\t Ingresa una trama de bits: ";
        getline(cin, tramaS);
        flagP = validarPalabras(tramaS);
        if (flagP)
        {
            flagN = validarNumeros(tramaS);
        }
    } while ( (flagP != true) || (flagN != true) );



    return 0;
}
