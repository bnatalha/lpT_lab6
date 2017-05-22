/**
* @file
* @brief Definição de myLista e implemnetação das sobrecargas de operadores dela
* @author Natália Azevedo de Brito (https://github.com/bnatalha/)
* @since 14/05/2017
* @date 21/05/2017
* @sa std::stack (http://www.cplusplus.com/reference/stack/stack/, http://en.cppreference.com/w/cpp/container/list)
*/

#ifndef MYLISTA_H
#define MYLISTA_H

#include "header_2.h"
#include <ostream>

/**
* @class myLista
* @brief Classe criada para simular a classe std::list da STL do C++, só que já ordenada 
* (neste exemplo, na ordem decrescente)
* @tparam T Tipo dos elementos da lista
*/
template < typename T >
class myLista
{
	private:

		/**
		* @struct myNode
		* @brief Estrutura que define um nó dá lista
		*/
		struct myNode
		{
			T elemento;	/**< Elemento que o nó guarda */
			myNode* anterior; /**< Ponteiro para o nó anterior (no sentido do início) da lista */
			myNode* proximo; /**< Ponteiro para o próximo nó (no sentido do fim) da lista */

			/**
			* @brief Construtor de myNode
			*/
			myNode(const T& data, myNode* prevNode = NULL, myNode* nextNode = NULL)
				:	elemento(data), anterior(prevNode), proximo(nextNode)
			{}
		};

		myNode *sentinela_head;	/**< Ponteiro para o nó do início (head) da lista */
		myNode *sentinela_tail;	/**< Ponteiro para o nó do fim (tail) da lista */
		int qtd_elementos;	/**< A quantidade de elementos armazenados na lista */

	public:
		// Iterador (Não foi feito)

		// Construtor
		myLista();
		myLista( const myLista & copy );
		// range
		myLista(const int& n, const T& val);	// Invalidado pela nova implementação dos metodos push (só entra algum elemento na lista caso ele ainda não exista nela)
		
		// Destrutor
		~myLista();

		// Acesso a elementos
		T& front();
		T& back();
		
		// Capacidade
		int size();
		bool empty();

		// Modificadores
		void push_sorted(const T& elem );
		//void pop_sorted();
		void push_back( const T& elem );	// bool se tiver como checar se pode ser alocado ou não
		bool pop_back();
		void push_front( const T& elem );
		bool pop_front();
		void clear();
		//erase()	iterator
		//insert()	iterator

		// Operações
		void remove(const T& val);
		// > Auxiliares dos modificadores
		bool existent_element(const T& elem);
		//sort();

		// Sobrecarga de operadores
		myLista<T>& operator= (const myLista<T> copy);
		// PARA TESTE: sobrecarga operador <<
		template <typename foo>
		friend std::ostream& operator<< (std::ostream& out, const myLista<foo> copy);
};

// Implementação de Sobrecargas


/**
* @brief	Sobrecarga do operador "="
* @param copy Lista a ser copiada
*/
template <typename T>
myLista<T>& myLista<T>::operator= (const myLista<T> copy)
{
	// EXTRA !: checar se listas são iguais (operator ==) antes da atribuição
	clear();	// Destroi os elementos da lista que vai ser modificada
	
	myNode *_pointer = copy.sentinela_head;	// Cria um ponteiro não constante para o início da lista a ser copiada
	while( _pointer != NULL )	// Enquanto ponteiro não chegar no fim da lista a ser copiada (NULL)
	{
		push_back(_pointer->elemento);	// Acrescenta o elemento do nó da vez ao fim desta lista
		_pointer = _pointer->proximo;	// Ponteiro anda no sentido do fim da lista a ser copida
	}

	return *this;
}

/**
* @brief	Sobrecarga do operador "="
* @param copy lista a ser copiada
* @param out ostream a ser usada
* @sa Explicação para uso do typename dentro da função em http://stackoverflow.com/questions/610245/
*/
template <typename foo>
std::ostream& operator<< (std::ostream& out, const myLista<foo> copy)
{
	typename myLista<foo>::myNode *_pointer = lista.sentinela_head;	// Ponteiro para o primeiro nó da lista

	out << "[ ";
	while( _pointer != NULL )
	{
		out << _pointer->elemento << (_pointer->proximo == NULL ? " ": ", ");
		_pointer = _pointer->proximo;
	}
	out << "]";

	return out;
}

#include "myLista_0_Iterator.h"
#include "myLista_1_Construtor.h"
#include "myLista_2_Destrutor.h"
#include "myLista_3_Acess.h"
#include "myLista_4_Capacity.h"
#include "myLista_5_Modifiers.h"
#include "myLista_6_Operations.h"

#endif