/*
 * 
 * Implementación del TAD Árbol Binario mediante
 * un celdas enlazadas.
 *
 */

#ifndef ABIN_CEL_ENLAZADAS_H
#define ABIN_CEL_ENLAZADAS_H

#include <cassert>

template <typename T> class Abin
{

    struct celda;       //declaración adelantada privada

    public:
        typedef celda* nodo;
        static const nodo NODO_NULO;

        Abin();                     //ctor.
        Abin(const Abin<T>& a);     //ctor. de copia
        ~Abin();                    //dtor;
        Abin<T>& operator =(const Abin<T>& a);      //Sobrecarga del operador de asignación para trabajar con árboles.

        void insertarRaizB(const T& e);
        void insertarHijoIzqdoB(nodo n, const T& e);
        void insertarHijoDrchoB(nodo n, const T& e);
        void eliminarHijoIzqdoB(nodo n);
        void eliminarHijoDrchoB(nodo n);
        void eliminarRaizB();
        bool arbolVacioB() const;
        const T& elemento(nodo n) const;        //acceso a elto, lectura
        T& elemento(nodo n);                    //acceso a elto, lectura/escritura
        nodo raizB() const;                     //Devuelve el nodo correspondiente a la raíz.
        nodo padreB(nodo n) const;              //Devuelve el nodo padre del nodo pasado como parámetro.
        nodo hijoIzqdoB(nodo n) const;          //Devuelve el nodo hijo izquierdo del nodo pasado por parámetro.
        nodo hijoDrchoB(nodo n) const;          //Devuelve el nodo hijo derecho del nodo pasado por parámetro.

    private:
        struct celda
        {
            T elto;
            nodo padre, hizq, hder;
            celda(const T& e, nodo p = NODO_NULO) :
                elto(e),
                padre(p),
                hizq(NODO_NULO),
                hder(NODO_NULO)
            {}
        };
        nodo r;
        //Nodo raíz del árbol, debe apuntar siempre al primer elemento de la lista
        //de celdas, o al nodo nulo si el árbol está vacío.

        void comprobarNodo(nodo n) const;       //Comprueba que el nodo n sea no-nulo;
        void destruirNodos(nodo& n);
        nodo copiar(nodo n);
};

/********************************/
/********************************/
/*  Definición del nodo nulo    */
/********************************/
/********************************/

template <typename T>
    const typename Abin<T>::nodo Abin<T>::NODO_NULO(0);



/********************************/
/********************************/
/*  Definición de los métodos   */
/********************************/
/********************************/


template <typename T>
    inline Abin<T>::Abin() : r(NODO_NULO) {}


template <typename T>
    inline void Abin<T>::insertarRaizB(const T& e)
    {
        assert(r == NODO_NULO);        //Asegurarse de que el árbol está vacío (raíz == vacío)

        r = new celda(e);
        //Como es el nodo raíz, llamamos al constructor de celda sin pasarle padre por parámetro.
    }


template <typename T>
    inline void Abin<T>::insertarHijoIzqdoB(Abin<T>::nodo n, const T& e)
    {
        comprobarNodo(n);
        assert(n->hizq == NODO_NULO);

        n->hizq = new celda(e, n);
    }


template <typename T>
    inline void Abin<T>::insertarHijoDrchoB(Abin<T>::nodo n, const T& e)
    {
        comprobarNodo(n);
        assert(n->hder == NODO_NULO);

        n->hder = new celda(e, n);
    }


template <typename T>
    inline void Abin<T>::eliminarHijoIzqdoB(Abin<T>::nodo n)
    {
        comprobarNodo(n);
        assert(n->hizq != NODO_NULO);
        assert(n->hizq->hizq == NODO_NULO && n->hizq->hder == NODO_NULO);

        delete(n->hizq);
        n->hizq = NODO_NULO;
    }


template <typename T>
    inline void Abin<T>::eliminarHijoDrchoB(Abin<T>::nodo n)
    {
        comprobarNodo(n);
        assert(n->hder != NODO_NULO);
        assert(n->hder->hizq == NODO_NULO && n->hder->hder == NODO_NULO);

        delete(n->hder);
        n->hder = NODO_NULO;
    }


template <typename T>
    inline void Abin<T>::eliminarRaizB()
    {
        comprobarNodo(r);
        assert(r->hizq == NODO_NULO && r->hder == NODO_NULO);

        delete(r);
        r = NODO_NULO;
    }


template <typename T>
    inline Abin<T>::~Abin()
    {
        destruirNodos(r);       //vacía el árbol
    }


template <typename T>
    inline bool Abin<T>::arbolVacioB() const
    {
        return (r == NODO_NULO);
    }


template <typename T>
    inline const T& Abin<T>::elemento(Abin<T>::nodo n) const
    {
        comprobarNodo(n);

        return n->elto;
    }


template <typename T>
    inline T& Abin<T>::elemento(Abin<T>::nodo n)
    {
        comprobarNodo(n);

        return n->elto;
    }


template <typename T>
    inline typename Abin<T>::nodo Abin<T>::raizB() const
    {
        return r;
    }


template <typename T>
    inline typename Abin<T>::nodo Abin<T>::padreB(Abin<T>::nodo n) const
    {
        comprobarNodo(n);

        return n->padre;
    }


template <typename T>
    inline typename Abin<T>::nodo Abin<T>::hijoIzqdoB(Abin<T>::nodo n) const
    {
        comprobarNodo(n);

        return n->hizq;
    }


template <typename T>
    inline typename Abin<T>::nodo Abin<T>::hijoDrchoB(Abin<T>::nodo n) const
    {
        comprobarNodo(n);

        return n->hder;
    }


template <typename T>
    inline Abin<T>::Abin(const Abin<T>& a)
    {
        //Llamamos al método copiar para asignar recursivamente cada celda al nuevo árbol.
        r = copiar(a.r);
    }


template <typename T>
    Abin<T>& Abin<T>::operator =(const Abin<T>& a)
    {
        if(this != &a)              //Evitamos la autoasignación.
        {
            this->~Abin();          //Destruimos el arbol existente (miembro izquierdo).
            r = copiar(a.r);
        }
        return *this;
    }


/********************************/
/*      MÉTODOS PRIVADOS        */
/********************************/

template <typename T>
    void Abin<T>::destruirNodos(Abin<T>::nodo& n)
    {
        if(n != NODO_NULO)
        {
            destruirNodos(n->hizq);
            destruirNodos(n->hder);

            delete n;
            n = NODO_NULO;
        }
    }


template <typename T>
    typename Abin<T>::nodo Abin<T>::copiar(Abin<T>::nodo n)
    {
        nodo m = NODO_NULO;

        if(n != NODO_NULO)
        {
            m = new celda(n->elto);

            m->hizq = copiar(n->hizq);
            if(m->hizq != NODO_NULO)
            {
                m->hizq->padre = m;
            }
            
            m->hder = copiar(n->hder);
            if(m->hder != NODO_NULO)
            {
                m->hder->padre = m;
            }
        }
        return m;
    }


template <typename T>
    void Abin<T>::comprobarNodo(Abin<T>::nodo n) const
    {
        assert(n != NODO_NULO);     //El nodo n es válido.
    }


#endif //ABIN_CEL_ENLAZADAS_H
