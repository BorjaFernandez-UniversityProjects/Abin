/*
 * 
 * Subprograma para el ejercicio 2 de la práctica 1 de la asignatura
 * Estructura de Datos No Lineales, 2017-2018.
 *
 */

#include <iostream>
#include "abinCelEnlazadas.hpp"
#include "abin_E-S.hpp"
#include "alturaArbolBin.hpp"


using namespace std;


int main(int argc, char* args[])
{

        Abin<char> Arbol{};

        ifstream inputStream("arbol.dat");

        cout << "\n***\tLeyendo árbol binario de fichero\t***\n";
        rellenarAbin(inputStream, Arbol);
        inputStream.close();

        cout << "\n***\tMostrando árbol binario\t***\n";
        imprimirAbin(Arbol);

        cout << "\nEl árbol binario es de altura " << alturaArbolBin(Arbol) << ".\n";

        return 0;
}
