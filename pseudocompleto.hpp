#ifndef PSEUDOCOMPLETO_H
#define PSEUDOCOMPLETO_H

#include "abinCelEnlazadas.hpp"
#include "alturaArbolBin.hpp"


//Postcondición: llama a la función 'pseudocompleto()' con el nodo raíz (por defecto)
//				como parámetro.
template <typename T>
	bool pseudocompleto(Abin<T>& Arbol)
	{
		return pseudocompleto(Arbol.raizB(), Arbol);
	}


//Postcondición: devuelve verdadero si el árbol formado por 'nodo' como raíz cumple las condiciones
//			de ser un árbol pseudocompleto. En caso contrario, devuelve falso.
template <typename T>
	bool pseudocompleto(typename Abin<T>::nodo nodo, Abin<T>& Arbol)
	{
		bool esNulo, esHoja, esPadreCompleto;


		if(alturaNodoArbolBin(nodo, Arbol) < 2)
		{

			esNulo = (nodo == Abin<T>::NODO_NULO);
			esHoja = (Arbol.hijoIzqdoB(nodo) == Abin<T>::NODO_NULO) && (Arbol.hijoDrchoB(nodo) == Abin<T>::NODO_NULO);
			esPadreCompleto = (Arbol.hijoIzqdoB(nodo) != Abin<T>::NODO_NULO) && (Arbol.hijoDrchoB(nodo) != Abin<T>::NODO_NULO);

			if(esNulo || esHoja || esPadreCompleto)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			int alturaHIzq = alturaNodoArbolBin(Arbol.hijoIzqdoB(nodo), Arbol);
			int alturaHDer = alturaNodoArbolBin(Arbol.hijoDrchoB(nodo), Arbol);
				
			//Si el subárbol izquierdo es más alto que el derecho, éste siempre devolverá true, porque
			//o bien no tiene nodos en el penúltimo nivel, o los que tiene son todos hoja,
			if(alturaHIzq > alturaHDer)
			{
				return pseudocompleto(Arbol.hijoIzqdoB(nodo), Arbol);
			}
			else
			{
				if(alturaHIzq < alturaHDer)
				{
					return pseudocompleto(Arbol.hijoDrchoB(nodo), Arbol);
				}
				else
				{
					//Devolvemos la unión del resultado de la función pseudocompleto en ambos nodos.
					return pseudocompleto(Arbol.hijoIzqdoB(nodo), Arbol) && pseudocompleto(Arbol.hijoDrchoB(nodo), Arbol);
				}
			}
		}
	}


#endif	//PSEUDOCOMPLETO_H
