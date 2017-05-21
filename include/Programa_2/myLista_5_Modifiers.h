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
	
	if (size() == 1 )	// Se a lista possuir apenas um elemento
		sentinela_head = NULL;	// Aponta a cabeça para NULL
	
	if( sentinela_tail != NULL )	// Se o rabo não estiver apontando para NULL (se a lista possuir mais de um elemento)
		sentinela_tail->proximo = NULL;	// // O novo ultimo nó não tem mais ligação com o antigo ultimo nó


	delete _destruir;	// Deleta o elemento que era o último da lista

	qtd_elementos--;	// Total de elementos da lista diminui

	return true;	
}

/**
* @brief Adiciona um elemento ao início da lista
* @param elem Elemento a ser adicionado ao início da lista
*/
template < typename T>
void myLista<T>::push_front( const T& elem )
{
	myNode *new_node = new myNode(elem, NULL, sentinela_head);	// Cria um novo nó dinamicamente com o elemento adicionado, com o próximo dele sendo o primeiro atual (apontado pela cabeça)

	if ( empty() ) // Se for o primeiro nó da lista (sentinelas não contam)
		sentinela_tail = new_node;	// O nó criado agora é o primeiro da lista	
	
	else // Se já existir algum elemento na lista
		sentinela_head->anterior = new_node;	// O primeiro nó da lista agora tem um nó anterior: O nó criado

	sentinela_head = new_node;	// O nó criado é o novo primeiro nó da lista

	qtd_elementos++;	// Total de elementos da lista aumenta	
}

/**
* @brief Remove um elemento do início lista, se está não estiver vazia
* @retval true Se um elemento foi retirado
* @retval false Se a lista for vazia
*/
template < typename T>
bool myLista<T>::pop_front()
{
	if ( size() == 0 )
	{
		cout << "pop_front(): A Lista está vazia." << endl;	// ou cerr?
		return false;
	}
	myNode *_destruir = sentinela_head;	// Atribui o endereço apontado pela cabeça a um ponteiro
	sentinela_head = sentinela_head->proximo;	// A cabeça agora aponta para o *segundo* nó (ou null, se tamanho da lista for 1)

	if (size() == 1 )	// Se a lista possuir apenas um elemento
		sentinela_tail = NULL;	// Aponta a cauda para NULL

	if( sentinela_head != NULL )	// Se a cabeça não estiver apontando para NULL (se a lista possuir mais de um elemento)
		sentinela_head->anterior = NULL;	// O novo primeiro nó não tem mais ligação com o antigo primeiro nó
	
	delete _destruir;	// Deleta o elemento que era o primeiro da lista

	qtd_elementos--;	// Total de elementos da lista diminui

	return true;	
}

#endif