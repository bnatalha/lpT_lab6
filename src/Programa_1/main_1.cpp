/**
* @file
* @brief Implementação da função principal de Programa_1
* @author Natália Azevedo de Brito (https://github.com/bnatalha/)
* @since 14/05/2017
* @date 19/05/2017
*/

#include "header_1.h"
#include "myPilha.h"
#include "palindromo.h"

/**
* @brief Diz se algumas frases são palíndromas ou não
*/
int main(int argc, char const *argv[])
{
	string exemplo1("Socorram-me, SUBI NO ONIBUS EM MARROCOS"); // palíndromo
	string exemplo2("arara");	// palíndromo
	string exemplo3("araa");	// não é palíndromo

	cout << "Strings exemplo: \"" 
		<< exemplo1 << "\", \"" << exemplo2 << "\" e \"" << exemplo3 << "\"." << endl;
	
	// EXTRA! Corrigir para ser passagem por referência para 'limpaString'
	cout << "Tratando as strings 'exemplo'...";
	limpaString(&exemplo1);
	limpaString(&exemplo2);
	limpaString(&exemplo3);
	cout << "Pronto." << endl;

	cout << '\"' << exemplo1 << '\"';
	cout << ( palindromo(exemplo1) ? " é":" não é" )<< " palíndromo." << endl;
	cout << '\"' << exemplo2 << '\"';
	cout << ( palindromo(exemplo2) ? " é":" não é" )<< " palíndromo." << endl;
	cout << '\"' << exemplo3 << '\"';
	cout << ( palindromo(exemplo3) ? " é":" não é" )<< " palíndromo." << endl;

	cout << "Fim." << endl;
	return 0;
}