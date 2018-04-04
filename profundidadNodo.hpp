#ifndef PROFUNDIDAD_NODO_H
#define PROFUNDIDAD_NODO_H


template <typename T>
    int profundidadNodo(typename Abin<T>::nodo nodo, Abin<T>& Arbol)
    {

        if(nodo == arbol.raizB())
        {
            return 0;
        }
        else
        {
            return 1 + profundidadNodo(Arbol.padreB(nodo), Arbol);
        }
    }


#endif  //PROFUNDIDAD_NODO_H
