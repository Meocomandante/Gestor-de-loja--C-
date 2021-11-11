#ifndef _H_BDCLIENTE
#define _H_BDCLIENTE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

#define MAXPALAVRA 40
#define TAM_MAX 10
#define erro 0
#define sem_erro 1

/*Defini��o de tad*/
typedef void* bdcliente;

/*Prot�tipo das fun��es*/
bdcliente cria_bdcliente( );
void lista_bdcliente( bdcliente aux );
bdcliente ler_ficheiro_bdclientes( char nome_ficheiro[MAXPALAVRA], bdcliente aux, void* clitemp );
int novo_registo( bdcliente aux, void* clitemp, char email[MAXPALAVRA], int ultimo_produto );
int verifica_cliente( bdcliente aux, char email[MAXPALAVRA], int *posicao );
void escreve_codigo_produto( bdcliente aux, int *i, int codigo_produto );
int lista_cliente( bdcliente aux, int i );
int num_cli( bdcliente aux );
void escrever_ficheiro_clientes ( void* aux, char nome_ficheiro[MAXPALAVRA] );

#endif

