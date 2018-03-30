#ifndef PROFUNDIDAD_NODO_H
#define PROFUNDIDAD_NODO_H


template <typename T>
    int profundidadNodo(Abin<T>& arbol, typename Abin<T>::nodo nodo)
    {

        if(nodo == arbol.raizB())
        {
            return 0;
        }
        else
        {
            return 1 + profundidadNodo(arbol, arbol.padreB(nodo));
        }
    }


#endif  //PROFUNDIDAD_NODO_H