/**
* @file
* @brief Definição e implementação de myLista
* @author Natália Azevedo de Brito (https://github.com/bnatalha/)
* @since 14/05/2017
* @date 19/05/2017
* @sa std::stack (http://www.cplusplus.com/reference/stack/stack/, http://en.cppreference.com/w/cpp/container/list)
*/

#ifndef MYLISTA_H
#define MYLISTA_H

#include "header_2.h"

/**
* @class myLista
* @brief Classe criada para simular a classe std::list da STL do C++
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

		// Construtor
		myLista();
		
		// Destrutor
		~myLista();

		// Acesso a elementos
		T& front();
		//back()
		
		// Capacidade
		int size();
		bool empty();

		// Modificadores
		void push_back( const T& elem );	// bool se tiver como checar se pode ser alocado ou não
		bool pop_back();
		//push_front()
		//pop_front()
		void clear();
		//erase()
		//insert()

		// Operações
		//merge()	??
		//remove()
		//unique() ()usar nos modificadores
		//sort()

		// sobrecarga operador=
};

#include "myLista_0_Iterator.h"
#include "myLista_1_Construtor.h"
#include "myLista_2_Destrutor.h"
#include "myLista_3_Acess.h"
#include "myLista_4_Capacity.h"
#include "myLista_5_Modifiers.h"
#include "myLista_6_Operations.h"

#endif