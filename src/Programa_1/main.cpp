/**
* @brief Onde fica a função principal
* @author Natália Azevedo de Brito (https://github.com/bnatalha/)
* @since 14/05/2017
* @date 15/05/2017
* @sa http://www.cplusplus.com/ , http://en.cppreference.com/ 
*/

#include "header.h"
#include "myPilha.h"
#include "palindromo.h"

/**
* @brief Despreza 'ç'
*/
int main(int argc, char const *argv[])
{
	// pega string
	string str("Socorram-me, SUBI NO ONIBUS EM MARROCOS");
	// chama func palindromo
	limpaString(&str);	// !! Corrigir para por referência

	cout << str << endl;

	// diz se é ou nao é palindromo
	cout << ( palindromo(str) ? "é":"não é" )<< " palíndromo." << endl;

	cout << "Fim." << endl;
	return 0;
}