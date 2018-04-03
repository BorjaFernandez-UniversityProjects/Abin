#ifndef NUMERO_NODOS_H
#define NUMERO_NODOS_H


//Función base, llama a la función genérica con el nodo raíz como segundo parámetro
template <typename T>
    int cuentaNodos(Abin<T>& arbol)
    {
        return cuentaNodos(arbol, arbol.raizB());
    }

//Postcondición: devuelve el número de nodos del árbol.
template <typename T>
    int cuentaNodos(Abin<T>& arbol, typename Abin<T>::nodo nodo)
    {
        if(nodo == Abin<T>::NODO_NULO)
        {
            return 0;
        }
        else
        {
            return 1 + cuentaNodos(arbol, arbol.hijoIzqdoB(n)) + cuentaNodos(arbol, arbol.hijoDrchoB(nodo));
        }
    }


#endif  //NUMERO_NODOS_H