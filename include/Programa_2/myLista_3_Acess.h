#ifndef MYLISTA_3_H
#define MYLISTA_3_H

/**
* @brief Acessa o elemento mais a frente na lista
* @return O elemento do nó apontado pela cabeça;
*/
template < typename T>
T& myLista<T>::front()
{
	// exceção caso lista esteja vazia (?)
	return (sentinela_head->elemento);
}

/**
* @brief Acessa o elemento no último nó da lista
* @return O elemento do nó apontado pela cauda;
*/
template < typename T>
T& myLista<T>::back()
{
	// exceção caso lista esteja vazia (?)
	return (sentinela_tail->elemento);
}
#endif