#ifndef ALTURA_ARBOL_BIN_H
#define ALTURA_ARBOL_BIN_H


template <typename T>
    int alturaArbolBin(Abin<T>& arbol)
    {
        return alturaNodoArbolBin(arbol, arbol.raizB());
    }


template <typename T>
    int alturaNodoArbolBin(Abin<T>& arbol, typename Abin<T>::nodo nodo)
    {

        int alturaHijoIzq, alturaHijoDrc;

        if(nodo == Abin<T>::NODO_NULO)
        {
            return -1;
        }
        else
        {
            alturaHijoIzq = alturaNodoArbolBin(arbol, arbol.hijoIzqdoB(nodo));
            alturaHijoDrc = alturaNodoArbolBin(arbol, arbol.hijoDrchoB(nodo));

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