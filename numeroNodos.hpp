#ifndef NUMERONODOS_H
#define NUMERONODOS_H



template <typename T>
    int cuentaNodos(Abin<T>& arbol, typename Abin<T>::nodo n)
    {
        if(n != Abin<T>::NODO_NULO)
        {
            return 1 + cuentaNodos(arbol, arbol.hijoIzqdoB(n)) + cuentaNodos(arbol, arbol.hijoDrchoB(n));
        }
        else
        {
            return 0;
        }
    }


#endif  //NUMERONODOS_H