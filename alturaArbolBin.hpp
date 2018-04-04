#ifndef ALTURA_ARBOL_BIN_H
#define ALTURA_ARBOL_BIN_H


template <typename T>
    int alturaArbolBin(Abin<T>& Arbol)
    {
        return alturaNodoArbolBin(Arbol.raizB(), Arbol);
    }


template <typename T>
    int alturaNodoArbolBin(typename Abin<T>::nodo nodo, Abin<T>& Arbol)
    {

        int alturaHijoIzq, alturaHijoDrc;

        if(nodo == Abin<T>::NODO_NULO)
        {
            return -1;
        }
        else
        {
            alturaHijoIzq = alturaNodoArbolBin(Arbol.hijoIzqdoB(nodo), Arbol);
            alturaHijoDrc = alturaNodoArbolBin(Arbol.hijoDrchoB(nodo), Arbol);

            if(alturaHijoIzq >= alturaHijoDrc)
            {
                return alturaHijoIzq + 1;
            }
            else
            {
                return alturaHijoDrc + 1;
            }
        }
    }


#endif  //ALTURA_ARBOL_BIN_H
