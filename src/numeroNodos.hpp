#ifndef NUMERO_NODOS_H
#define NUMERO_NODOS_H


//Función base, llama a la función genérica con el nodo raíz como segundo parámetro
template <typename T>
    int cuentaNodos(Abin<T>& Arbol)
    {
        return cuentaNodos(Arbol.raizB(), Arbol);
    }

//Postcondición: devuelve el número de nodos del árbol a partir del nodo pasado por parámetro (incluído).
template <typename T>
    int cuentaNodos(typename Abin<T>::nodo nodo, Abin<T>& Arbol)
    {
        if(nodo == Abin<T>::NODO_NULO)
        {
            return 0;
        }
        else
        {
            return 1 + cuentaNodos(Arbol.hijoIzqdoB(n), Arbol) + cuentaNodos(Arbol.hijoDrchoB(nodo), Arbol);
        }
    }


#endif  //NUMERO_NODOS_H
