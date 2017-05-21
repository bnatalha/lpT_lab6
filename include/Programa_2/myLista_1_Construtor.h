#ifndef MYLISTA_1_H
#define MYLISTA_1_H

/**
* @brief Constrói uma lista vazia
*/
template < typename T>
myLista<T>::myLista()
	: sentinela_head(NULL), sentinela_tail(NULL), qtd_elementos(0)
{}

template < typename T>
myLista<T>::myLista( const myLista & copy )
	: sentinela_head(NULL), sentinela_tail(NULL), qtd_elementos(0)
{
	myNode * _pointer = copy.sentinela_head;

	while (_pointer != NULL)
	{
		push_back(_pointer->elemento);
		_pointer = _pointer->proximo;
	}

}

#endif