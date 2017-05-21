#ifndef MYLISTA_6_H
#define MYLISTA_6_H

/**
* @brief Remove da listas, os nós cujos elementos sejam iguais a 'val'
* @param val Valor buscado para ser removido
*/
template < typename T>
void myLista<T>::remove(const T& val)
{
	myNode * _pointer = sentinela_head;	// Cria ponteiro para o início da lista, a partir da sentinela da cabeça
	myNode * _destruir= NULL;	// Ponteiro para o nó a ser destruído

	while(_pointer != NULL)	// Enquanto o ponteiro não percorrer toda a lista
	{
		if(_pointer->elemento == val)	// Se achou valor
		{
			// Verificando posição do nó apontado pelo ponteiro na lista
			if(_pointer->anterior == NULL and _pointer->proximo == NULL)
			// H-> [val] <-T (Se só existe este nó na lista)
			{
				pop_front();
				_pointer = NULL;
			}
			else if(_pointer->anterior != NULL and _pointer->proximo == NULL)	// Já percorreu toda a lista
			// H-> [n_0]...[n_k-1][val] <-T (Se só existe nó anterior a este e não depois dele)
			{
				_pointer = _pointer->proximo;	// Avança o ponteiro para o fim da lista
				pop_back();
				//_pointer = NULL;
			}
			else if(_pointer->anterior == NULL and _pointer->proximo != NULL)
			// H-> [val][n_1]...[n_k] <-T Se só existe nó depois deste e não antes dele)
			{	
				//_pointer é igual a head
				_pointer = _pointer->proximo;	// Avança o ponteiro para o fim da lista
				pop_front();	// Destroi o elemento (supostamente no início da lista)

			}
			else if(_pointer->anterior != NULL and _pointer->proximo != NULL)
			// H-> [n_0]...[n_z][val][n_z+2]...[n_k] <-T (Se existe nó antes e depois deste)
			{
				// Inicialmente: [x]-[val]-[y],	onde "-" indica que estão conectados em ambos sentidos (anterior e proximo)
				
				_pointer->anterior->proximo = _pointer->proximo;	// Pega o nó anterior ao selecionado e o conecta com o próximo do atual
				// [x]->[z]  [x]<-[val]-[z]
				
				_pointer->proximo->anterior = _pointer->anterior;	// Pega o nó depois do selecionado e o conecta com o anterior do selecionado
				// [x]-[z] [x]<-[val]->[z]
				
				_destruir = _pointer;	// Atribui ao ponteiro destrutor qual o nó a ser destruído
				// _destruir -> [val]
				
				_pointer = _pointer->proximo; //	Avança o ponteiro em direção ao fim da lista
				// _pointer -> [val]
				
				delete _destruir; // Destrói o nó [val]

				qtd_elementos--; // Diminui o contador de elementos da lista
			}
		}
		else // Se não achar elemento
		{
			_pointer = _pointer->proximo;	// Avança o ponteiro;
		}
	}
}

#endif