#include <iostream>
#include <fstream>
#include "abin.hpp"
#include "abin_E-S.hpp"
#include "numeroNodos.hpp"




int main(int argc, char* args[])
{
    
    Abin<char> arbol{50};
    std::filebuf fbuffer;


    if(fbuffer.open("arbol.dat", std::ios::in))
    {
        std::istream inputStream(&fbuffer);
    }
    std::ifstream inputStream("arbol.dat");

    std::cout << "\n***\tLeyendo arbol binario de fichero\t***\n";
    rellenarAbin(inputStream, arbol);
    inputStream.close();

    std::cout << "\n***\tMostrando arbol binario\t***\n";
    imprimirAbin(arbol);

    std::cout << "\nEl arbol tiene " << cuentaNodos(arbol, arbol.raizB()) << " nodos.\n";
    
    return 0;
}