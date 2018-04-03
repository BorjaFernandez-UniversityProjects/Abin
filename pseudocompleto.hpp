#ifndef PSEUDOCOMPLETO_H
#define PSEUDOCOMPLETO_H

#include "abinCelEnlazadas.hpp"
#include "alturaArbolBin.hpp"

template <typename T>
	bool pseudocompleto(Abin<T>& arbol, typename Abin<T>::nodo nodo, int alturaArbol=0)
	{
		if(arbol.arbolVacioB())
		{
			return true;
		}
		else
		{
			if(profundidadNodo(arbol, nodo) == alturaNodoArbolBin(arbol, nodo) -1)
			{
				if(esNodoPseudocompleto(arbol, nodo)
				{
					return true;
				}
			}

		}


	}


template <typename T>
	bool esNodoPseudocompleto(Abin<T>& arbol, Abin<T>::nodo nodo)
	{
		bool resultado;

		resultado = false;

		if(arbol.hijoIzqdoB(nodo) == Abin<T>::NODO_NULO)
		{
			if(arbol.hijoDrchoB(nodo) == Abin<T>::NODO_NULO)
				resultado = true;
		}
		else
		{
			if(arbol.hijoDrchoB(nodo) != Abin<T>::NODO_NULO)
				resultado = true;
		}

		return resultado;	
	}















#endif	//PSEUDOCOMPLETO_H
