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
	cout << "Creating stacks A, B and C..."; 
	myPilha<int> A;	// capacidade: padrão (2)
	myPilha<char> B(3);	// capacidade: 3
	//myPilha<myPilha<int>> C;
	cout << "Done" << endl;
	//myPilha<myPilha<int>> C;

	// Testes com pilhas vazias
	cout << "A is" << (A.empty()? "":" not") << " empty." << endl;
	cout << "B is" << (B.empty()? "":" not") << " empty." << endl;
	cout << "--" << endl;

	// Testando push
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
	B.push('b');

	C.push(A);
	//C.push(myPilha<int>(40));


	return 0;
}