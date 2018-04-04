/*
 * 
 * Implementación del TAD Árbol Binario mediante
 * un vector de posiciones relativas.
 *
 */


#ifndef ABIN_VEC1_HPP
#define ABIN_VEC1_HPP

#include <cassert>
#include <cstring>

template <typename T>
    class Abin
    {

        public:
            typedef int nodo;   //índice del vector entre 0 y maxNodos-1
            static const nodo NODO_NULO;
            explicit Abin(size_t maxNodos, const T& e_nulo = T());  //ctor
                    //e_nulo representa el valor nulo del tipo que compone los nodos del árbol.
            ~Abin();
            Abin(const Abin<T>& a);                 //ctor. de copia
            Abin<T>& operator =(const Abin<T>& a);  //Sobrecarga del operador de asignación para trabajar con árboles.

            void insertarRaizB(const T& e);
            void insertarHijoIzqdoB(nodo n, const T& e);
            void insertarHijoDrchoB(nodo n, const T& e);
            void eliminarHijoIzqdoB(nodo n);
            void eliminarHijoDrchoB(nodo n);
            bool arbolVacioB() const;
            void eliminarRaizB();
            const T& elemento(nodo n) const;    //acceso a elto. para lectura.
            T& elemento(nodo n);                //acceso a elto. para lectura/escritura.
            nodo raizB() const;                 //Devuelve el nodo correspondiente a la raíz.
            nodo padreB(nodo n) const;          //Devuelve el nodo padre del nodo pasado como parámetro.
            nodo hijoIzqdoB(nodo n) const;      //Devuelve el nodo hijo izquierdo del nodo pasado por parámetro.
            nodo hijoDrchoB(nodo n) const;      //Devuelve el nodo hijo derecho del nodo pasado por parámetro.

        private:
            void comprobarNodo(nodo n) const;
            void comprobarHijoIzqdoB(nodo n) const;
            void comprobarHijoDrchoB(nodo n) const;
            T* nodos;       //El vector que contiene los nodos del árbol.
            int maxNodos;   //El tamaño del vector.
            T ELTO_NULO;    //Una celda marcada con este valor se considera vacía.
    };


/********************************/
/********************************/
/*  Definición del nodo nulo    */
/********************************/
/********************************/

template <typename T>
    const typename Abin<T>::nodo Abin<T>::NODO_NULO(-1);



/********************************/
/********************************/
/*  Definición de los métodos   */
/********************************/
/********************************/

template <typename T>
    Abin<T>::Abin(size_t maxNodos, const T& e_nulo):
        nodos(new T[maxNodos]),
        maxNodos(maxNodos),
        ELTO_NULO(e_nulo)
    {
        nodo n;
        //marcar todas las celdas libres
        for(n = 0; n <= maxNodos -1; n++)
        {
            nodos[n] = ELTO_NULO;
        }
    }


template <typename T>
    inline void Abin<T>::insertarRaizB(const T& e)
    {
        assert(nodos[0] == ELTO_NULO);  //Asegurarse de que el árbol está vacío (raíz == vacío)

        nodos[0] = e;
    }


template <typename T>
    void Abin<T>::insertarHijoIzqdoB(Abin<T>::nodo n, const T& e)
    {
        comprobarNodo(n);
        comprobarHijoIzqdoB(n);

        nodos[2*n + 1] = e;
    }


template <typename T>
    void Abin<T>::insertarHijoDrchoB(Abin<T>::nodo n, T& e)
    {
        comprobarNodo(n);
        comprobarHijoDrchoB(n);

        nodos[2*n +1] = e;
    }


template <typename T>
    void Abin<T>::eliminarHijoIzqdoB(Abin<T>::nodo n)
    {
        comprobarNodo(n);
        comprobarHijoIzqdoB(n);

        if(4*n +4 < maxNodos)
        {
            //Comprobamos que los (posibles) nodos hijo del nodo hijo izqdo. de n pueden caber
            //en el vector, para evitar errores al acceder a su posición para comprobar si son nulos.
            //En concreto, comprobamos el supuesto lugar del hijo derecho por ser el más lejano.
            assert(nodos[4*n +3] == ELTO_NULO &&        //Asegurarse de que el hijo izqdo. de n es un nodo hoja.
                nodos[4*n +4] == ELTO_NULO);
        }
        else if(4*n +3 < maxNodos)      
        {
            //Cabe la posibilidad de que no haya hueco para el hijo derecho del hijo izqdo. de n,
            //pero sí para el izquierdo, puesto que ocupa una posición anterior en el vector.
            assert(nodos[4*n +3] == ELTO_NULO);
        }

        nodos[2*n +1] = ELTO_NULO;      //Con todo comprobado, podemos asignar el elemento nulo
                                        //al nodo hijo izqdo. de n.
    }


template <typename T>
    void Abin<T>::eliminarHijoDrchoB(Abin<T>::nodo n)
    {
        comprobarNodo(n);
        comprobarHijoDrchoB(n);

        if(4*n +6 < maxNodos)
        {
            //Comprobamos que los (posibles) nodos hijo del nodo hijo drcho. de n pueden caber
            //en el vector, para evitar errores al acceder a su posición para comprobar si son nulos.
            //En concreto, comprobamos el supuesto lugar del hijo derecho por ser el más lejano.
            assert(nodos[4*n +3] == ELTO_NULO &&        //Asegurarse de que el hijo drcho. de n es un nodo hoja.
                nodos[4*n +4] == ELTO_NULO);
        }
        else if(4*n +5 < maxNodos)      
        {
            //Cabe la posibilidad de que no haya hueco para el hijo derecho del hijo drcho. de n,
            //pero sí para el izquierdo, puesto que ocupa una posición anterior en el vector.
            assert(nodos[4*n +5] == ELTO_NULO);
        }

        nodos[2*n +2] = ELTO_NULO;      //Con todo comprobado, podemos asignar el elemento nulo
                                        //al nodo hijo drcho. de n.
    }



template <typename T>
    inline void Abin<T>::eliminarRaizB()
    {
        assert(nodos[0] != ELTO_NULO);      //El árbol no está vacíol.
        assert(nodos[1] != ELTO_NULO &&
                nodos[2] != ELTO_NULO);     //El nodo raíz es un nodo hoja.

        nodos[0] = ELTO_NULO);
    }


template <typename T>
    inline Abin<T>::~Abin()
    {
        delete[] nodos;
    }

template <typename T>
    inline bool Abin<T>::arbolVacioB() const
    {
        return (nodos[0] == ELTO_NULO);
    }

template <typename T>
    inline const T& Abin<T>::elemento(Abin<T>::nodo n) const
    {
        comprobarNodo(n);

        return nodos[n];
    }


template <typename T>
    inline T& Abin<T>::elemento(Abin<T>::nodo n)
    {
        comprobarNodo(n);

        return nodos[n];
    }


template <typename T>
    inline typename Abin<T>::nodo Abin<T>raizB() const
    {
        //Si el árbol está vacío, devuelve nodo nulo.
        //En caso contrario, devuelve 0 (el primer elemento del vector y la posición del nodo raíz).
        return (nodos[0] == ELTO_NULO) ? NODO_NULO : 0;
    }


template <typename T>
    inline typename Abin<T>::nodo Abin<T>::padreB(Abin<T>::nodo n) const
    {
        comprobarNodo(n);

        //Si el nodo n es la raíz, devuelve nodo nulo.
        //En caso contrario, calcula la posición del vector en la que estaría el nodo padre de n.
        return (n == 0) ? NODO_NULO : (n-1)/2;
    }


template <typename T>
    inline typename Abin<T>::nodo Abin<T>::hijoIzqdoB(Abin<T>::nodo n) const
    {
        comprobarNodo(n);

        //Si el hijo izqdo. de n quedaría fuera del vector, o si está vacío, devuelve nodo nulo.
        //En caso contrario, devuelve la posición relativa al hijo izqdo. de n.
        return (2*n+1 >= maxNodos || nodos[2*n+1] == ELTO_NULO) ? NODO_NULO : 2*n+1;
    }


template <typename T>
    inline typename Abin<T>::nodo Abin<T>::hijoDrchoB(Abin<T>::nodo n) const
    {
        comprobarNodo(n);

        //Si el hijo drcho. de n quedaría fuera del vector, o si está vacío, devuelve nodo nulo.
        //En caso contrario, devuelve la posición relativa al hijo drcho. de n.
        return (2*n+2 >= maxNodos || nodos[2*n+2] == ELTO_NULO) ? NODO_NULO : 2*n+2;
    }


template <typename T>
    Abin<T>::Abin(const Abin<T>& a) :
        nodos(new T[a.maxNodos]),
        maxNodos(a.maxNodos),
        ELTO_NULO(a.ELTO_NULO)          //Constructor de copia
    {
        nodo n;

        for(n = 0; n < maxNodos; n++)
        {
            nodos[n] = a.nodos[n];
        }
    }


template <typename T>
    Abin<T>& Abin<T>::operator =(const Abin<T>& a)
    {
        nodo n;

        if(this != &a)          //Evitamos la autoasignación.
        {
            //Destruir el vector y crear uno nuevo si es necesario.
            if(maxNodos != a.maxNodos)
            {
                delete[] nodos;
                maxNodos = a.maxNodos;
                nodos = new T[maxNodos];
            }
            ELTO_NULO = a.ELTO_NULO;

            for(n = 0; n < maxNodos; n++)   //Copiamos manualmente el vector.
            {
                nodos[n] = a.nodos[n];
            }
        }
        return *this;
    }


/********************************/
/*      MÉTODOS PRIVADOS        */
/********************************/

template <typename t>
    void Abin<T>::comprobarNodo(Abin<T>::nodo n) const
    {
        assert(n >= 0 && n < maxNodos);         //El nodo n es válido (está en el rango del vector).
        assert(nodos[n] != ELTO_NULO);          //El nodo n no está vacío.
    }


template <typename T>
    void Abin<T>::comprobarHijoIzqdoB(Abin<T>::nodo n) const
    {
        assert((2*n +1) < maxNodos);            //El hijo izqdo. del nodo n tiene cabida en el vector.
        assert(nodos[2*n +1] == ELTO_NULO);     //El nodo n no tiene hijo izqdo.
    }

template <typename T>
    void Abin<T>::comprobarHijoDrchoB(Abin<T>::nodo n) const
    {
        assert((2*n +2) < maxNodos);            //El hijo drcho. del nodo n tiene cabida en el vector.
        assert(nodos[2*n +2] == ELTO_NULO);     //El nodo n no tiene hijo drcho.
    }




#endif  //ABIN_VEC1_HPP