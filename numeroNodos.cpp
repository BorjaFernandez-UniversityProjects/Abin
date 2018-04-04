/*
 * 
 * Subprograma para el ejercicio 1 de la práctica 1 de la asignatura
 * Estructura de Datos No Lineales, 2017-2018.
 *
 */

#include <iostream>
#include "abinVec.hpp"
#include "abin_E-S.hpp"
#include "numeroNodos.hpp"


using namespace std;


int main(int argc, char* args[])
{
    
    Abin<char> Arbol{50};

    ifstream inputStream("arbol.dat");

    cout << "\n***\tLeyendo arbol binario de fichero\t***\n";
    rellenarAbin(inputStream, Arbol);
    inputStream.close();

    cout << "\n***\tMostrando arbol binario\t***\n";
    imprimirAbin(Arbol);

    cout << "\nEl arbol tiene " << cuentaNodos(Arbol) << " nodos.\n";
    
    return 0;
}
