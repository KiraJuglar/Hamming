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

char []Hamming(string value){
    //Calculamos la cantidad de bits de paridad
    float exp = log2(value.length());
    exp = floor(exp);
    //Arreglo de bits de paridad
    int paridad[(int(exp))];
    //Arreglo de bits de paridad y bits de value
    char nValue[(int(exp)) + value.length()];
    //Inicializamos las posiciones de los bits de paridad en 0
    for(int i = 0; i < exp; i++){
        nValue[pow(2,i) - 1] = '0';
    }
    //Ingresamos value en el resto de posiciones
    int aux = 0;
    for(int i = 0; i < nValue.length(); i++){
        if(nValue[i] != '0'){
            nValue[i] = value[aux++];
        }
    }
    //Se hace el calculo de los bits de paridad
    for(int i = 0; i < exp; i++){
        paridad[i] = 0;
        for(int j = pow(2,i) - 1; j < nvalue.length(); j + pow(2,i) + 1){
            for(int k = 0; k < j; k++){
                paridad[i] += nvalue[j];
            }
        }
    }
    //Asignamos el valor de los bits de paridad
    aux = 0;
    for(int i = 0; i < exp; i++){
        nValue[pow(2,i) - 1] = paridad[aux++] % 2;
    }

    return nValue;
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
        if (flagP) // Valido si solo hay valores numéricos en la trama
            flagN = validarNumeros(tramaS);

    } while ( (flagP != true) || (flagN != true) );


    // En caso de que la trama esté completa
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
                // Añado cada tramo de 8 bits en un vector
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
        // Convierto cada tramo de 8 bits en un número
        cadena += (char)convertirBinario(data);
    }
    // Salida
    cout<<"\n\t Palabra: "<<cadena<<endl;



    return 0;
}
