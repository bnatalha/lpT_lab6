#ifndef MYLISTA_1_H
#define MYLISTA_1_H

/**
* @brief Constrói uma lista vazia
*/
template < typename T>
myLista<T>::myLista()
	: sentinela_head(NULL), sentinela_tail(NULL), qtd_elementos(0)
{}

#endif