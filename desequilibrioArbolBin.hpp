#ifndef DESEQUILIBRIO_ARBOL_BIN_H
#define DESEQUILIBRIO_ARBOL_BIN_H


template <typename T>
    int desequilibrioArbolBin(Abin<T>& arbol)
    {
        return desequilibrioNodoBin(arbol, arbol.raizB());
    }


template <typename T>
    int desequilibrioNodoBin(Abin<T>& arbol, Abin<T>::nodo nodo)
    {
        int diferenciaAltura, alturaHIzq, alturaHDer;

        alturaHIzq = alturaNodoArbolBin(arbol, arbol.hijoIzqdoB(nodo));
        alturaHDer = alturaNodoArbolBin(arbol, arbol.hijoDrchoB(nodo));

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