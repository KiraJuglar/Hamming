#include "ingresodatos.h"

ingresoDatos::ingresoDatos()
{

}

string ingresoDatos::ingresarTrama()
{
    bool flagP = false, flagN = false;
    string tramaS;

    // Llamar a la clase Validaciones
    Validaciones va;

    do {
        cout <<"\n\t Ingresa una trama de bits: ";
        getline(cin, tramaS);
        // Remuevo espacios en la trama de bits
        tramaS = va.removerEspacios(tramaS);
        // Valido si existen palabras en la trama
        flagP = va.validarPalabra(tramaS);
        if (flagP) // Valido si solo hay valores numéricos en la trama
            flagN = va.validarNumeros(tramaS);

    } while ( (flagP != true) || (flagN != true) );

    return tramaS;

}

void ingresoDatos::mostrarPalabra(string trama)
{
    // Llamar a la clase Convertir Binario Texto
    ConversorBinarioText con;
    // Vector que guarda los conjuntos de 8 bits
    vector <string> v;
    // En caso de que la trama esté completa
    if ((trama.size() % 2) == 0)
    {
        string b = "";
        int i = 1;
        for (size_t j (0) ; j < trama.size() ; ++j, ++i)
        {
            // Obtengo bit por bit
            b += trama.at(j);
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
        // Convierto cada tramo de 8 bits en un char
        cadena += (char)con.convertirBinario(data);
    }
    // Salida
    cout<<"\n\t Palabra: "<<cadena<<endl;
}



