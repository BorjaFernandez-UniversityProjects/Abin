#ifndef NODOS_NOSTALGICOS_H
#define NODOS_NOSTALGICOS_H

#include "abinCelEnlazadas.hpp"
#include "profundidad.hpp"
#include "numeroNodos.hpp"



template <typename T>
	double ratioNodosNostalgicos(Abin<T>& Arbol)
	{
		return (double) cuentaNodosNostalgicos(Arbol) / cuentaNodos(Arbol);
	}


template <typename T>
	int cuentaNodosNostalgicos(Abin<T>& Arbol)
	{
		return cuentaNodosNostalgicos(Arbol.raizB(), Arbol);
	}


template <typename T>
	int cuentaNodosNostalgicos(typename Abin<T>::nodo nodo, Abin<T>& Arbol)
	{
		if(nodo == Abin<T>::NODO_NULO)
		{
			return 0;
		}
		else
		{
			if(esNodoNostalgico(nodo, Arbol)
			{
				return 1 + cuentaNodosNostalgicos(Arbol.hijoIzqdoB(nodo), Arbol) + cuentaNodosNostalgicos(Arbol.hijoDrchoB(nodo), Arbol);
			}
			else
			{
				return cuentaNodosNostalgicos(Arbol.hijoIzqdoB(nodo), Arbol) + cuentaNodosNostalgicos(Arbol.hijoDrchoB(nodo), Arbol);
			}
		}
	}


template <typename T>
	bool esNodoNostalgico(typename Abin<T>::nodo nodo, Abin<T>& Arbol)
	{

		if(profundidadNodo(nodo, Arbol) > cuentaNodos(nodo, Arbol) -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}







#endif	//NODOS_NOSTALGICOS_H
