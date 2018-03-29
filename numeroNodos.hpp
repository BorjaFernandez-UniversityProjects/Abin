#ifndef NUMERO_NODOS_H
#define NUMERO_NODOS_H


//Precondición: devuelve el n
template <typename T>
    int cuentaNodos(Abin<T>& arbol)
    {
        if(n == Abin<T>::NODO_NULO)
        {
            return 0;
        }
        else
        {
            return 1 + cuentaNodos(arbol, arbol.hijoIzqdoB(n)) + cuentaNodos(arbol, arbol.hijoDrchoB(n));
        }
    }


#endif  //NUMERO_NODOS_H