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
	// Testando construtor del ista vazia
	cout << "Creating Lists... ";
	myLista<int> A;
	cout << "Done" << endl;

	// Testando empty() e size()
	cout << "A.size(): " << A.size() << endl;
	cout << "A.empty(): " << (A.empty()? "true":"false") << endl;

	// Testando push_back() e push_front()
	cout << endl << "> A.push_back(3) " << endl;
	A.push_back(3);
	cout << "> A.push_back(2) " << endl;
	A.push_back(2);
	cout << "> A.push_back(1) " << endl;
	A.push_back(1);
	cout << "> A.push_back(0) " << endl;
	A.push_back(0);
	cout << "> A.push_front(4) " << endl;
	A.push_front(4);
	cout << "> A.push_front(5) " << endl;
	A.push_front(5);

	// Testando front() e back()
	cout << endl << "A.front(): " << A.front() << endl;
	cout << "A.back(): " << A.back() << endl;

	// Testando construtor cópia
	cout << endl << "Creating List B as a copy of A... ";
	myLista<int> B(A);
	cout << "Done" << endl;
	cout << B << endl;

	cout << endl << "B.size(): " << B.size() << endl;
	cout << "B.empty(): " << (B.empty()? "true":"false") << endl;
	cout << "B.front(): " << B.front() << endl;
	cout << "B.back(): " << B.back() << endl << endl;

	// Testando pop_back()
	cout << "- Popping_back B- " << endl;
	for ( ; B.size() > 0; )
	{
		cout << "B.front(): " << B.front() << endl;
		cout << "B.back(): " << B.back() << endl;
		cout << "B.pop_back(): " << ( B.pop_back() ? "true":"false" ) << endl;
		cout << "--" << endl;
	}
	cout << "-B- " << endl << endl;
	//cout << "B.front(): " << B.front() << endl;	// Sem elementos, não vai funcionar.

	// Testando pop_front()
	cout << "- Popping_front A- " << endl;
	for ( ; A.size() > 0; )
	{
		cout << "A.front(): " << A.front() << endl;
		cout << "A.back(): " << A.back() << endl;
		cout << "A.pop_front(): " << ( A.pop_front() ? "true":"false" ) << endl;
		cout << "--" << endl;
	}
	cout << "-A- " << endl << endl;

	// Testando push_front() em lista vazia
	cout << "> B.push_front(0) " << endl;
	B.push_front(0);
	cout << "B.front(): " << B.front() << endl;
	cout << "B.back(): " << B.back() << endl;
	cout << "> B.push_front(1) " << endl;
	B.push_front(1);
	cout << "B.front(): " << B.front() << endl;
	cout << "B.back(): " << B.back() << endl;

	// Testando operador =
	cout << "Antes de atribuir: A =" << A << ", B=" << B << endl;
	B = A;
	cout << "Antes de A=B : A =" << A << ", B=" << B << endl;

	cout << "Fim." << endl;
	return 0;
}