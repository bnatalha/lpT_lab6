#ifndef MYLISTA_1_H
#define MYLISTA_1_H

/**
* @brief Constrói uma lista vazia
*/
template < typename T>
myLista<T>::myLista()
	: sentinela_head(NULL), sentinela_tail(NULL), qtd_elementos(0)
{}

/**
* @brief Constrói uma lista a partir de uma lista já existente
* @param copy Lista a ser copiada
*/
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

/**
* @brief Constrói uma lista com 'n' elementos, todos elementos sendo 'val'
* @param n Quantidade de elementos a ser criados
* @param val Valor que cada elemento criado a partir desta função receberá
*/
template < typename T>	// fill;
myLista<T>::myLista(const int& n, const T& val)
: sentinela_head(NULL), sentinela_tail(NULL), qtd_elementos(0)
{
	while (size() < n)	// Enquanto o tamanho da lista for menor que 'n'
		push_front(val);	// Adiciona a lista nós com elemento 'val'
}

#endif