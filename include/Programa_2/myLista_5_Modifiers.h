#ifndef MYLISTA_5_H
#define MYLISTA_5_H

/**
* @brief Remove todos os elementos da lista, a deixando com tamanho = 0.
*/
template < typename T>
void myLista<T>::clear()
{
	while ( sentinela_head != NULL )	// Se tiver mais de um elemento na lista,
	{
		pop_back();
	}
}

/**
* @brief Adiciona um elemento ao fim da lista
* @param elem Elemento a ser adicionado ao fim da lista
*/
template < typename T>
void myLista<T>::push_back( const T& elem )
{
	myNode *new_node = new myNode(elem, sentinela_tail);	// Cria um novo nó dinamicamente com o elemento adicionado, com o anterior dele sendo o último atual (apontado pela cauda)

	if ( empty() ) // Se for o primeiro nó da lista (sentinelas não contam)
		sentinela_head = new_node;	// O nó criado agora é o primeiro da lista	
	
	else // Se já existir algum elemento na lista
		sentinela_tail->proximo = new_node;	// Faz com que o ultimo nó da lista aponte para o nó criado

	sentinela_tail = new_node;	// O nó criado agora é o ultimo da lista

	qtd_elementos++;	// Total de elementos da lista aumenta
	
}

/**
* @brief Remove um elemento do fim da lista, se está não estiver vazia
* @retval true Se um elemento foi retirado
* @retval false Se a lista for vazia
*/
template < typename T>
bool myLista<T>::pop_back()
{
	if ( size() == 0 )
	{
		cout << "pop_back(): A Lista está vazia." << endl;	// ou cout?
		return false;
	}

	myNode *_destruir = sentinela_tail;	// Atribui o endereço apontado pela cauda a um ponteiro
	sentinela_tail = sentinela_tail->anterior;	// A cauda agora aponta para o *penúltimo* nó (ou null, se tamanho da lista for 1)
	sentinela_head = sentinela_tail;
	delete _destruir;	// Deleta o elemento que era o último da lista

	qtd_elementos--;	// Total de elementos da lista diminui

	return true;
	
}

#endif