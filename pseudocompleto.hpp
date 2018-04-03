#ifndef PSEUDOCOMPLETO_H
#define PSEUDOCOMPLETO_H

#include "abinCelEnlazadas.hpp"
#include "alturaArbolBin.hpp"
#include "profundidadNodo.hpp"


//Postcondición: llama a la función 'pseudocompleto()' con la altura y el nodo raíz (por defecto)
//				como parámetro.
template <typename T>
	bool pseudocompleto(Abin<T>& arbol)
	{
		return pseudocompleto(arbol, arbol.raizB(), alturaArbolBin(arbol));
	}

//Postcondición: llama a la función 'pseudocompleto()' con la altura del árbol como parámetro,
//				por si al usuario se le ha olvidado pasarlo.
template <typename T>
	bool pseudocompleto(Abin<T>& arbol, typename Abin<T>::nodo nodo)
	{
		return pseudocompleto(arbol, nodo, alturaArbolBin(arbol));
	}


//Postcondición: devuelve verdadero si el árbol formado por 'nodo' como raíz cumple las condiciones
//				de ser un árbol pseudocompleto. En caso contrario, devuelve falso.
template <typename T>
	bool pseudocompleto(Abin<T>& arbol, typename Abin<T>::nodo nodo, int alturaArbol)
	{
		//Comprobamos primero si el árbol está vacío, no sólo porque es una condición suficiente para que
		//el árbol sea considerado como pseudocompleto, sino porque así prevenimos errores de acceso a
		//posiciones inexistentes de memoria.
		if(arbol.arbolVacioB())
		{
			return true;
		}
		else
		{
			//Si estamos en el penúltimo nivel.
			if(profundidadNodo(arbol, nodo) >= alturaArbol -1)
			{
				//Si el nodo es pseudocompleto (es nodo hoja o tiene exactamente dos hijos).
				if(esNodoPseudocompleto(arbol, nodo))
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
				int alturaHIzq = alturaNodoArbolBin(arbol, arbol.hijoIzqdoB(nodo));
				int alturaHDer = alturaNodoArbolBin(arbol, arbol.hijoDrchoB(nodo));
				
				//Si el subárbol izquierdo tiene una diferencia de altura mayor que el derecho de
				//más de uno, ignoramos el derecho, pues no tiene ningún nodo en el penúltimo nivel.
				if(alturaHIzq > alturaHDer -1)
				{
					return pseudocompleto(arbol, arbol.hijoIzqdoB(nodo));
				}

				//Si, por el contrario, el subárbol derecho supera en altura por dos o más al
				//subárbol izquierdo, ignoramos este por el mismo motivo.
				if(alturaHDer > alturaHIzq -1)
				{
					return pseudocompleto(arbol, arbol.hijoDrchoB(nodo));
				}

				//Si ninguno de los subárboles supera en altura al otro por dos o más, devolvemos
				//la unión de los resultados de ambos.
				return pseudocompleto(arbol, arbol.hijoIzqdoB(nodo)) && pseudocompleto(arbol, arbol.hijoDrchoB(nodo));
			}
		}
	}

//Postcondición: si 'nodo' es un nodo hoja (no tiene hijos) o, por el contrario, tiene exactamente
//				dos hijos, devuelve verdadero. En caso de ser un nodo nulo o de tener solo un hijo
//				(los otros dos posibles casos) devuelve falso.
template <typename T>
	bool esNodoPseudocompleto(Abin<T>& arbol, typename Abin<T>::nodo nodo)
	{
		bool resultado;

		resultado = false;

		if(nodo != Abin<T>::NODO_NULO)
		{
			if(arbol.hijoIzqdoB(nodo) == Abin<T>::NODO_NULO)
			{
				if(arbol.hijoDrchoB(nodo) == Abin<T>::NODO_NULO)
					resultado = true;
			}
			else if(arbol.hijoDrchoB(nodo) != Abin<T>::NODO_NULO)
			{
					resultado = true;
			}
		}

		return resultado;	
	}


#endif	//PSEUDOCOMPLETO_H
