/**
* @file
* @brief Definição e implementação de myLista
* @author Natália Azevedo de Brito (https://github.com/bnatalha/)
* @since 14/05/2017
* @date 19/05/2017
* @sa std::stack (http://www.cplusplus.com/reference/stack/stack/)
*/

#ifndef MYLISTA_H
#define MYLISTA_H

#include "header_2.h"

/**
* @class myPilha
* @brief classe criada para simular a classe std::stack da STL do C++
* @tparam T Tipo dos elementos da pilha
*/
template < typename T >
class myLista
{
	private:

		static const int capacidade = 50;	/**< Capacidade padrão de todas as pilhas */

	public:

		// Construtores

		/**
		* @brief Constroi um objeto myPilha sem passar atributos.
		*/
		myLista()
			: tamanho(0), pilha(new T[capacidade])
		{}
		
		// Destrutor

		/**
		* @brief Desaloca 'pilha' após chamar o destrutor de seus respectivos elementos
		*/
		~myLista()
		{
			delete[] pilha;
		}

		// Metodos

		bool empty();	/**< Verifica se a pilha está vazia */
		int& size();	/**< Retorna uma referência para o tamanho da pilha */
		T& top();	/**< Retorna uma referência para elemento no topo da pilha */
		void push(const T& element);	/**< Acrescenta um elemento no topo da pilha, aumentando o tamanho da pilha */
		void pop();	/**< Remove o elemento do topo da pilha, diminuindo o tamanho da pilha */

};

// Implementações de myLista

/**
* @retval true A lista está vazia
* @retval false A lista \b não está vazia
*/
template <typename T >
bool myLista<T>::empty()
{}


#endif