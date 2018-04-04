/*
 * 
 * Subprograma para el ejercicio 3 de la práctica 1 de la asignatura
 * Estructura de Datos No Lineales, 2017-2018.
 *
 */


#include <iostream>
#include "abinCelEnlazadas.hpp"
#include "abin_E-S.hpp"
#include "profundidadNodo.hpp"


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

    //Escogemos para la prueba dos nodos concretos totalmente dependientes de la forma que le hemos
    //dado al árbol en el fichero "arbol.dat".
    
    /*
     * Abin<char>::nodo nodoF, nodoL;
     * nodoF = arbol.hijoDrchoB(arbol.hijoDrchoB(arbol.hijoIzqdoB(arbol.raizB())));
     * nodoL = arbol.hijoIzqdoB(arbol.hijoDrchoB(arbol.hijoDrchoB(arbol.hijoDrchoB(arbol.raizB()))));
     *  
     * cout << "\nEl nodo F tiene profundidad " << profundidadNodo(arbol, profundidadNodo(nodoF)) << " .\n";
     * cout << "\nEl nodo L tiene profundidad " << profundidadNodo(arbol, profundidadNodo(nodoL)) << " .\n";
     */

    cout << "\nEl nodo F tiene profundidad " << profundidadNodo(arbol, arbol.hijoDrchoB(arbol.hijoDrchoB(arbol.hijoIzqdoB(arbol.raizB())))) << " .\n";
    cout << "\nEl nodo L tiene profundidad " << profundidadNodo(arbol, arbol.hijoIzqdoB(arbol.hijoDrchoB(arbol.hijoDrchoB(arbol.hijoDrchoB(arbol.raizB()))))) << " .\n";



    return 0;
}

