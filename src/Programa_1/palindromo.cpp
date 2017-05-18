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
	
	int slow = 0;	//indice 
	int fast = 0;	//indice

	while( suja[0][fast] != '\0' )
	{
		if( !dontMatter( suja->at(fast) ) ){
			suja[0][slow] = suja[0][fast];
			slow++;
		}
		fast++;
	}

	suja->resize(slow);		//novo tamanho, baseado na quantidade de vezes que slow andou
	suja->shrink_to_fit();	//compacta a string para seu novo tamanho.
}

/**
* @param s string já limpa a ser verificada 
* @retval true 's' é palindromo
* @retval false 's' não é palindromo
*/
bool palindromo(string &s){	// size retorna
	
	myPilha<char> A;
	myPilha<char> B;

	// preenchendo pilhas
	for (auto i (0u); i < s.size()/2; ++i)
	{
		A.push(s.at(0+i));
		B.push(s.at( s.size()-1 -i));
	}	// Despreza elemento do meio (se o tamanho for impar)

	for (unsigned int i = 0u; i < s.size()/2; ++i)	// ou até pilhas.empty()
	{
		if ( sameValue ( A.top(), B.top() ) == false ) return false;
		else 
		{
			A.pop();
			B.pop();
		}
	}
	return true;

}