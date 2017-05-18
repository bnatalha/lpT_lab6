/**
* @brief Definição e implementação de myPilha
* @author Natália Azevedo de Brito (https://github.com/bnatalha/)
* @since 14/05/2017
* @date 15/05/2017
* @sa http://www.cplusplus.com/ , http://en.cppreference.com/ 
*/

#ifndef MYPILHA_H
#define MYPILHA_H

#include "header.h"

/**
* @class myPilha
* @brief classe criada para simular a classe std::stack da STL do C++
* @tparam T Tipo de elementos da pilha
*/
template < typename T >
class myPilha 
{
	//atributos privados
	private:
	static const int capacidade_padrao = 2;	/**< Capacidade padrão (para caso nenhum capacidade seja passada inicialmente para o construtor)*/
	int tamanho;	/**< Quantitade de elementos na pilha */
	int capacidade;	/**< Capacidade da pilha */
	T *pilha = NULL;	/**< Arranjo que será alocado dinamicamente para guardar os elementos da pilha */

	public:
	// ================================================ Construtores

	/**
	* @brief Constroi um objeto myPilha sem passar atributos.
	*/
	myPilha()
		: tamanho(0), capacidade(capacidade_padrao), pilha(new T[capacidade])
	{} //!EXTRA!: tratamento de exceção na alocação dinâmica ()

	/**
	* @brief Constroi um objeto myPilha  partir de uma pilha já definida pelo usuário
	* @param size Será a capacidade da pilha
	*/
	myPilha(const myPilha &my_stack)
		: tamanho(my_stack.tamanho), capacidade(my_stack.capacidade), pilha(new T[capacidade])
	{
		// Copia elementos da pilha passa por argumento para a pilha a ser criada
		for (int i = 0; i < capacidade; ++i)
		{
			this->pilha[i] = my_stack.pilha[i];
		}
		
	}
	
	// ================================================ Destrutor

	/**
	* @brief Desaloca 'pilha' após chamar o destrutor de seus respectivos elementos
	*/
	~myPilha()
	{
		delete[] pilha;
	}

	// ================================================ Metodos

	bool empty();	/**< Verifica se a pilha está vazia */
	int& size();	/**< Retorna uma referência para o tamanho da pilha */
	T& top();	/**< Retorna uma referência para elemento no topo da pilha */
	void push(const T& element);	/**< Acrescenta um elemento no topo da pilha, aumentando o tamanho da pilha */
	void pop();	/**< Remove o elemento do topo da pilha, diminuindo o tamanho da pilha */




};

// Implementação

/**
* @retval true A pilha está vazia
* @retval false A pilha \b não está vazia
*/
template <typename T >
bool myPilha<T>::empty()
{
	return (tamanho == 0);
}

/**
* @return Referência para o tamanho da pilha
*/
template <typename T >
int& myPilha<T>::size()
{
	return tamanho;
}

/**
* @return Referência para o elemento no topo da pilha
*/
template <typename T >
T& myPilha<T>::top()
{
	if (empty())
	{
		cerr << "top(): Não há elementos na pilha (tamanho: "<< tamanho << ")." << endl;
		exit(1);
	}
	//else

	return pilha[tamanho-1];
}

/**
* @param element Elemento do tipo T a ser acrescentado ao topo da pilha
*/
template <typename T >
void myPilha<T>::push(const T& element)
{
	if(tamanho == capacidade)
	{
		cerr << "push(): A capacidade da pilha já foi atingida "
			<< "(tamanho :"<< tamanho << ", capacidade:" << capacidade << ")." << endl;
		exit(1);
	}
	//else

	pilha[tamanho++] = element;	// Acrescenta elemento e depois aumenta o tamanho da pilha
}

template <typename T >
void myPilha<T>::pop()
{
	if (empty())
	{
		cerr << "pop(): Não pode remover elementos de uma pilha de tamanho '"<< tamanho << "'." << endl;
		exit(1);
	}
	//else

	pilha[(tamanho--)-1].~T();	// Remove elemento e depois diminui o tamanho da pilha
}


#endif