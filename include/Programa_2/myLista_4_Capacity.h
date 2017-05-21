#ifndef MYLISTA_4_H
#define MYLISTA_4_H

/**
* @brief Checa se a quantidade de nós da lista
* @return atributo qtd_elementos
*/
template < typename T>
int myLista<T>::size()
{
	return qtd_elementos;
}

/**
* @brief Checa se a lista está vazia
*/
template < typename T>
bool myLista<T>::empty()
{
	return ( size() == 0 );
}


#endif