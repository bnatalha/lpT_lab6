/**
* @file
* @brief Implementações das funções em palindromo.h
* @author Natália Azevedo de Brito (https://github.com/bnatalha/)
* @since 19/05/2017
* @date 19/05/2017
*/

#include "palindromo.h"

/**
* @param a Referência a um char
* @param b Referência a um char
* @retval true 'a' e 'b' são a mesma letra
* @retval false 'a' e 'b' não são a mesma letra
*/
bool sameValue(const char &a, const char &b)
{
	if ( ( int(a) - int(b) ) == 32 or  ( int(a) - int(b) ) == -32
		or ( int(a) - int(b) ) == 0) return true;
	return false;
}


/**
* @param c Caractere a ser verificado.
* @retval true 'c' não é letra (segundo a tabela ASCII)
* @retval false 'c' é letra (segundo a tabela ASCII)
*/
bool dontMatter(char c){
	if ( int(c) < 65 or int(c) >  122 ) return true;
	return false;
}

/**
* @param *suja Ponteiro para a string a ser limpada
*/
void limpaString(string *suja){
	
	int slow = 0;	// Indice lento
	int fast = 0;	// Indice rápido

	while( suja[0][fast] != '\0' )	// Enquanto não chegar no fim da string
	{
		if( !dontMatter( suja->at(fast) ) ){	// Se o char em [fast] for válido (se for uma letra entre 'a' e 'A' na tabela ASCII)
			suja[0][slow] = suja[0][fast];	// [slow] (string definitiva) recebe o char válido
			slow++;
		}
		fast++;
	}

	suja->resize(slow);		// Novo tamanho, baseado na quantidade de vezes que slow andou
	suja->shrink_to_fit();	// Compacta a string para seu novo tamanho.
}

/**
* @param s String já limpa a ser verificada 
* @retval true 's' é palindromo
* @retval false 's' não é palindromo
*/
bool palindromo(string &s){
	
	myPilha<char> A;	// Pilha que guardará a primeira metade de 's'
	myPilha<char> B;	// Pilha que guardará a segunda metade de 's'

	// Preenchendo pilhas...
	for (auto i (0u); i < s.size()/2; ++i) // O(n/2)
	{
		// Despreza a letra do meio (se a quantidade de letras for um número ímpar)
		A.push(s.at(0+i));	// Pega do início de 's'
		B.push(s.at( s.size()-1 -i));	// Pega do fim de 's'
	}

	// Verificando conteúdo das pilhas...
	for (auto i(0u); i < s.size()/2; ++i)	// (?) poderia ser até A.empty()
	{
		if ( sameValue ( A.top(), B.top() ) == false ) return false;	// Se encontrar algum par de letras que  não sejam iguauis, retorna falso
		else // Se os topos de A e B forem iguais, ainda pode ser palíndromo
		{
			A.pop();	// Descarta topo vez de A
			B.pop();	// Descarta topo da vez de B
		}
	}
	return true;

}	// (!) Poderia ter feito uma pilha de pares de char