#ifndef _H_CLIENTE
#define _H_CLIENTE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXclientes 40
#define MAXPALAVRA 40
#define erro 0
#define sem_erro 1

/*Defini��o do tipo TAD*/
typedef void* cliente;

/*Prot�tipo das fun��es*/

void destroi_cliente( cliente aux );
cliente cria_cliente( char mail[MAXPALAVRA], int ultimo_produto );
void imp_email( cliente aux1 );
int compara_registo( cliente aux, char email[MAXPALAVRA] );
void escreve_produto( cliente aux, int codigo );
int imp_cliente( cliente aux );
void imp_ficheiro_cliente( cliente aux, FILE* ficheiro_saida );

#endif

