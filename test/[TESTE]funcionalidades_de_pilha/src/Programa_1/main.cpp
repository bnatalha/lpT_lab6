/**
* @brief Onde fica a função principal
* @author Natália Azevedo de Brito (https://github.com/bnatalha/)
* @since 14/05/2017
* @date 15/05/2017
* @sa http://www.cplusplus.com/ , http://en.cppreference.com/ 
*/

#include "header.h"
#include "myPilha.h"

/*! \mainpage My Personal Index Page
*
* \section intro_sec Introduction
*
* This is the introduction.
*
* \section install_sec Installation
*
* \subsection step1 Step 1: Opening the box
*
* etc...
*/

/**
* @brief Executa teste em myPilha
*/
int main(int argc, char const *argv[])
{
	// Criando pilhas
	cout << "Creating stacks A, B..."; 
	myPilha<int> A;	// capacidade: padrão (2)
	myPilha<char> B;	// capacidade: padrão (2)
	cout << "Done" << endl;

	// Testes com pilhas vazias
	cout << "A is" << (A.empty()? "":" not") << " empty." << endl;
	cout << "B is" << (B.empty()? "":" not") << " empty." << endl;
	cout << "--" << endl;

	// Testando push
	cout << "Testing push():" << endl;
	int a = 1;
	char b = 'a';

	A.push(a);
	cout << "A's top element is " << A.top() << endl;
	cout << "Current size:" << A.size() << endl;
	A.push(2);
	cout << "A's top element is " << A.top() << endl;
	cout << "Current size:" << A.size() << endl;
//	A.push(3);	// exceeding capacity
//	cout << "A's top element is " << A.top() << endl;
//	cout << "Current size:" << A.size() << endl;

	B.push(b);
	cout << "B's top element is " << B.top() << endl;
	cout << "Current size:" << B.size() << endl;
	B.push('b');
	cout << "B's top element is " << B.top() << endl;
	cout << "Current size:" << B.size() << endl;

	cout << "-" << endl;

	// Testanto Construtor myPilha(myPilha)
	cout << "Creating stacks C from stack A..."; 
	myPilha<int> C(A);

	// Testando pop
	cout << "Testing pop():" << endl;
	for (int i = 0; i <= C.size(); ++i)
	{
		cout << "C's top element is " << C.top() << endl;
		cout << "Current size:" << C.size() << endl;
		C.pop();
		cout << "popping.." << endl;
	}

	cout << endl;

	// Testando pop
	for (int i = 0; i < 2; ++i)
	{
		cout << "A's top element is " << A.top() << endl;
		cout << "Current size:" << A.size() << endl;
		A.pop();
		cout << "popping.." << endl;
	}

	cout << "Fim." << endl;
	return 0;
}