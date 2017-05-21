#ifndef MYLISTA_3_H
#define MYLISTA_3_H

/**
* @brief Acessa o elemento mais a frente na lista
* @return O elemento do nó apontado pela cabeça;
*/
template < typename T>
T& myLista<T>::front()
{
	return (sentinela_head->elemento);
}

#endif