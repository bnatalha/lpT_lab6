#ifndef MYPILHA_H
#define MYPILHA_H

#include "header.h"

// Definição
class myPilha 
{
	//atributos privados
	private:
	int tamanho;
	int capacidade;
	int *pilha = NULL;

	public:
	// ================================================ construtores

	/**
	* @brief Constroi um objeto Empresa sem precisar de uma lista
	* @param name Será o nome da empresa
	* @param code Será o CNPJ da empresa
	*/
	myPilha()
	{
		tamanho = 0;
		capacidade = 20;
		pilha = new int [capacidade];
		// ACIMA: teste para alocar?
	}
	// ================================================ destrutor
	//metodos


};

// Implementação

#endif