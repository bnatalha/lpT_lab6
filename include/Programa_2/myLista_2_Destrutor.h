#ifndef MYLISTA_2_H
#define MYLISTA_2_H

/**
* @brief Destroi a lista, desalocando os elementos nela presentes.
*/
template < typename T>
myLista<T>::~myLista()
{
	clear();
}

#endif