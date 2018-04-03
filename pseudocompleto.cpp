/*
 * 
 * Subprograma para el ejercicio 7 de la práctica 1 de la asignatura
 * Estructura de Datos No Lineales, 2017-2018.
 *
 */


#include <iostream>
#include "abinCelEnlazadas.hpp"
#include "abin_E-S.hpp"
#include "pseudocompleto.hpp"


using namespace std;


int main(int argc, char* args[])
{
    Abin<char> arbol{};

    ifstream inputStream("arbol.dat");

    cout << "\n***\tLeyendo arbol binario de fichero\t***\n";
    rellenarAbin(inputStream, arbol);
    inputStream.close();

    cout << "\n***\tMostrando arbol binario\t***\n";
    imprimirAbin(arbol);

    if(pseudocompleto(arbol))
    {
        cout << "\nEl árbol es pseudocompleto.\n";
    }
    else
    {
        cout << "\nEl árbol no es pseudocompleto.\n";
    }

    return 0;
}