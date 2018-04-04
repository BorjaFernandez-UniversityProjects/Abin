#ifndef ARBOLES_SIMILARES_H
#define ARBOLES_SIMILARES_H



template <typename T>
	bool arbolesSimilares(Abin<T>& ArbolA, Abin<T>& ArbolB)
	{
		return arbolesSimilares(ArbolA.raizB(), ArbolB.raizB(), ArbolA, ArbolB);
	}

template <typename T>
	bool arbolesSimilares(Abin<T>::nodo nodoA, Abin<T>::nodo nodoB, Abin<T>& ArbolA, Abin<T>& ArbolB)
	{
		if(nodoA == Abin<T>::NODO_NULO && nodoB == Abin<T>::NODO_NULO)
		{
			return true;
		}
		else
		{
			if(nodoA != Abin<T>::NODO_NULO && nodoB != Abin<T>::NODO_NULO)
			{
				return arbolesSimilares(ArbolA.hijoIzqdoB(nodoA), ArbolB.hijoIzqdoB(nodoB), ArbolA, ArbolB) &&
						arbolesSimilares(ArbolA.hijoDrchoB(nodoA), ArbolB.hijoDrchoB(nodoB), ArbolA, ArbolB);
			}
			else
			{
				return false;
			}
		}
	}


#endif	//ARBOLES_SIMILARES_H
