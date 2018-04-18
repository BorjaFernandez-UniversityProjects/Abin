#ifndef DESEQUILIBRIO_ARBOL_BIN_H
#define DESEQUILIBRIO_ARBOL_BIN_H

//Función llamadora de 'desequilibrioNodoBin'
template <typename T>
    int desequilibrioArbolBin(Abin<T>& Arbol)
    {
        return desequilibrioNodoBin(Arbol.raizB(), Arbol);
    }


//Precondición: ninguna.
//Postcondición: devuelve el desequilibrio del nodo 'n' en el árbol 'Arbol'.
template <typename T>
    int desequilibrioNodoBin(typename Abin<T>::nodo nodo, Abin<T>& Arbol)
    {
        int diferenciaAltura, alturaHIzq, alturaHDer;

        alturaHIzq = alturaNodoArbolBin(Arbol.hijoIzqdoB(nodo), Arbol);
        alturaHDer = alturaNodoArbolBin(Arbol.hijoDrchoB(nodo), Arbol);

        if(alturaHIzq >= alturaHder)
        {
            diferenciaAltura = alturaHIzq - alturaHDer;
        }
        else
        {
            diferenciaAltura = alturaHDer - alturaHIzq;
        }

        return diferenciaAltura;
    }

#endif  //DESEQUILIBRIO_ARBOL_BIN_H