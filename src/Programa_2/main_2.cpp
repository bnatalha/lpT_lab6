/**
* @file
* @brief Implementação da função principal de Programa_2
* @author Natália Azevedo de Brito (https://github.com/bnatalha/)
* @since 19/05/2017
* @date --/05/2017
* @sa std::list (http://www.cplusplus.com/reference/list/list/)
*/

#include "header_2.h"
#include "myLista.h"

/*
Implemente em C++ as respectivas classes, atributos e métodos (incluindo construtores e destrutor)
necessários para atender às especificações de uma lista duplamente encadeada ordenada com
sentinelas genérica, ou seja, capaz de operar com qualquer tipo de dado. Note que o fato da lista ser
ordenada implica em alterações apenas na inserção e eliminação dos itens.
*/

/**
* @brief Testa o comportamento da classe myLista e seus métodos
*/
int main(int argc, char const *argv[])
{
	cout << "Creating Lists... ";
	myLista<int> A;
	cout << "Done" << endl;

	cout << "A.size(): " << A.size() << endl;
	cout << "A.empty(): " << (A.empty()? "true":"false") << endl;

	cout << "> A.push_back(3) " << endl;
	A.push_back(3);

	cout << "> A.front(): " << A.front() << endl;

	cout << "Fim." << endl;
	return 0;
}