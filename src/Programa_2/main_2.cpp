/**
* @file
* @brief Implementação da função principal de Programa_2
* @author Natália Azevedo de Brito (https://github.com/bnatalha/)
* @since 19/05/2017
* @date 21/05/2017
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

	// Lista não aceita elementos repitidos.
	// Testando construtor de lista vazia
	cout << "Creating Lists... ";
	myLista<int> A;	// [] (vazia)
	myLista<char> C(1,'N');	// [N]
	cout << "Done"
		<< " A = " << A << ", C = " << C << endl << endl;

	// Testando empty() e size()
	cout << "Testing empty() and size()... "
		<< "A.size(): " << A.size()
		<< " A.empty(): " << (A.empty()? "true":"false") << endl;

	// Testando push_back() e push_front()
	cout << endl << "> A.push_back(3) ";
	A.push_back(3);
	cout << "> A.push_back(2) ";
	A.push_back(7);
	cout << "> A.push_back(1) ";
	A.push_back(9);
	cout << "> A.push_back(0) ";
	A.push_back(8);
	cout << "> A.push_front(4) ";
	A.push_front(4);
	cout << "> A.push_front(5)" << endl;
	A.push_front(5);

	// Testando construtor cópia
	cout << endl << "Creating List B as a copy of A... ";
	myLista<int> B(A);
	cout << "Done" << " B = " << B << endl;

	cout << endl << "B.size(): " << B.size()
		<< " B.empty(): " << (B.empty()? "true":"false")
		<< " B.front(): " << B.front()
		<< " B.back(): " << B.back() << endl << endl;

	// Testando pop_back()
	cout << "- Popping_back B- " << endl;
	for ( ; B.size() > 0; )
	{
		cout << "B.front(): " << B.front()
			<< " B.back(): " << B.back();
		cout << " > B.pop_back(): " << ( B.pop_back() ? "true":"false" ) << endl;
	}
	cout << "-B- " << endl << endl;
	//cout << "B.front(): " << B.front() << endl;	// Sem elementos, não vai funcionar.

	// Testando pop_front()
	cout << "- Popping_front A- " << endl;
	for ( ; A.size() > 0; )
	{
		cout << "A.front(): " << A.front()
			<< " A.back(): " << A.back();
		cout << " > A.pop_front(): " << ( A.pop_front() ? "true":"false" ) << endl;
	}
	cout << "-A- " << endl << endl;

	// Testando push_front() em lista vazia
	cout << "> B.push_front(0) ";
	B.push_front(0);
	cout << " B.front(): " << B.front()
		<< " B.back(): " << B.back() << endl;
	cout << "> B.push_front(1) ";
	B.push_front(1);
	cout << "B.front(): " << B.front()
		<< " B.back(): " << B.back() << endl << endl;

	// Testando operador =
	cout << "Before assigning: A = " << A << ", B = " << B << endl;
	cout << "Assigning A = B...";
	B = A;
	cout << "Done. A = " << A << ", B = " << B << endl;

	//cout << A.front() << endl;	// lista vazia, segmentation fault

	// Testando remove()
	cout << "Testing remove..." << endl;
	B.push_front(6);
	cout << "B = " << B << endl;	// [ 6 ]
	B.remove(6);
	cout << "B = " << B << endl;	// [ ]

	B.push_front(7);
	B.push_front(7);
	B.push_front(7);
	cout << "B = " << B << endl;	// [ 7 ]
	B.remove(7);
	cout << "B = " << B << endl;	// [ ]

	C.push_front('c');	
	cout << "C = " << C << endl;	// [ c N ]
	C.remove('c');
	cout << "C = " << C << endl;	// [ N ]
	
	C.push_back('d');	
	cout << "C = " << C << endl;	// [ N d ]
	C.remove('d');
	cout << "C = " << C << endl;	// [ N ]
	
	C.push_back('e'); 
	C.push_front('f');
	cout << "C = " << C << endl;	// [ f N e ]
	C.remove('N');
	cout << "C = " << C << endl;	// [ f e ]

	// Testando unique() e push_sorted()
	cout << "Testing and push_sorted()..." << endl;
	B.push_sorted(5);
	cout << "B = " << B << endl;	// [ 5 ]
	B.push_sorted(3);
	cout << "B = " << B << endl;	// [ 5 3 ]
	B.push_sorted(10);
	cout << "B = " << B << endl;	// [ 10 5 3 ]
	B.push_sorted(3);
	cout << "B = " << B << endl;	// [ 10 5 3 ]
	B.push_sorted(7);
	cout << "B = " << B << endl;	// [ 10 7 5 3 ]
	B.push_sorted(0);
	cout << "B = " << B << endl;	// [ 10 7 5 3 0 ]
	B.push_sorted(6);
	cout << "B = " << B << endl;	// [ 10 7 5 3 0 ]

	cout << "Fim." << endl;
	return 0;
}	