/**
* @brief Assinaturas das funções que ajudam a verificar se uma frase é palíndromo
* @author Natália Azevedo de Brito (https://github.com/bnatalha/)
* @since 19/05/2017
* @date 15/05/2017
* @sa http://www.cplusplus.com/ , http://en.cppreference.com/ 
*/

#ifndef PALINDROMO_H
#define PALINDROMO_H

#include "myPilha.h"	// Pilha desenvolvida pelo autor

bool sameValue(const char &a, const char &b); /**< Verifica se dois char são a mesma letra, considerando maiúsculo igual a menúsculo ("A" igual a "a")  */
bool dontMatter(char c);	/**< Verifica se o conteudo de um char não é uma letra VÁLIDA */
void limpaString(string *suja); /**< Limpa a string, tirando caracteres que não sejam letras e depois a compacta para o seu novo tamanho */
bool palindromo(string &s);	/**< Verifica se a string passada é palindromo ou não, a organizando em duas pilhas para isto */

#endif