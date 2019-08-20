#ifndef ARBOL_BIN_REFLEJADO_HPP
#define ARBOL_BIN_REFLEJADO_HPP

#include "abinCelEnlazadas.hpp"


// Con esta función vamos creando un árbol vacío que es reflejo del actual
template <typename T> 
Abin<T> arbolBinReflejado(const Abin<T>& ArbolOrigen)
{
    Abin<T> ArbolReflejo{};

    ArbolReflejo.insertarRaizB(ArbolOrigen.elemento(ArbolOrigen.raizB()));
    arbolBinReflejado(ArbolOrigen, Arbolorigen.raizB(),
                        ArbolReflejo, ArbolReflejo.raizB());

    return ArbolReflejo;
}

template <typename T>
void arbolBinReflejado(const Abin<T>& ArbolOrigen, typename Abin<T>::nodo nodoOrigen,
                        Abin<T>& ArbolReflejo, typename Abin<T>::nodo nodoReflejo)
{
    T& elto;

    // Si existe subárbol izquierdo
    if (ArbolOrigen.hijoIzqdoB(nodoOrigen) != Abin<T>::NODO_NULO)
    {
        elto = ArbolOrigen.elemento(ArbolOrigen.hijoIzqdoB(nodoOrigen));
        ArbolReflejo.insertarHijoDrchoB(nodoReflejo, );
    }
    // Si existe subárbol derecho
    if (ArbolOrigen.hijoDrchoB(nodoOrigen) != Abin<T>::NODO_NULO)
    {
        elto = ArbolOrigen.elemento(ArbolOrigen.hijoDrchoB(nodoOrigen));
        ArbolReflejo.insertarHijoIzqdoB(nodoReflejo, elto);
    }
    // Recorremos el árbol reflejo en el sentido inverso que el original
    arbolBinReflejado(ArbolOrigen, ArbolOrigen.hijoIzqdoB(nodoOrigen),
                        ArbolReflejo, ArbolReflejo.HijoDrchoB(nodoReflejo));
    arbolBinReflejado(ArbolOrigen, ArbolOrigen.hijoDrchoB(nodoOrigen),
                        ArbolReflejo, ArbolReflejo.hijoIzqdoB(nodoReflejo));
}



// Con esta función creamos una copia del árbol y vamos intercambiando los
// nodos simétricos del árbol para hacerlo reflejo del original
template <typename T>
Abin<T> arbolBinReflejadoCopia(const Abin<T>& ArbolOrigen)
{
    Abin<T> ArbolReflejo{ArbolOrigen};

    arbolBinReflejadoCopia(ArbolOrigen, ArbolOrigen.raizB(),
                            ArbolReflejo, ArbolReflejo.raizB());

    return ArbolReflejo;
}

template <typename T>
void arbolBinReflejadoCopia(const Abin<T>& ArbolOrigen, typename Abin<T>::nodo nodoOrigen,
                        Abin<T>& ArbolReflejo, typename Abin<T>::nodo nodoReflejo)
{
    if (nodoOrigen != Abin<T>::NODO_NULO)
    {
        ArbolReflejo.elemento(nodoReflejo) = ArbolOrigen.elemento(nodoOrigen);
    }

    arbolBinReflejadoCopia(ArbolOrigen, ArbolOrigen.hijoIzqdoB(nodoOrigen),
                        ArbolReflejo, ArbolReflejo.HijoDrchoB(nodoReflejo));
    arbolBinReflejadoCopia(ArbolOrigen, ArbolOrigen.hijoDrchoB(nodoOrigen),
                        ArbolReflejo, ArbolReflejo.hijoIzqdoB(nodoReflejo));
}

#endif  //ARBOL_BIN_REFLEJADO_HPP