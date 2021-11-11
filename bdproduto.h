#ifndef _H_BDPRODUTO
#define _H_BDPRODUTO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

#define MAXPALAVRA 40
#define PROD_MAX 40
#define erro 0
#define sem_erro 1

/*Defini��o do tipo de TAD*/
typedef void* bdproduto;

/*Prot�tipo das fun��es*/
bdproduto cria_bdproduto( );
void destroi_bdproduto( bdproduto aux1 );
void lista_bdproduto( bdproduto aux2 );
bdproduto ler_ficheiro_bdproduto( char nome_ficheiro[MAXPALAVRA], bdproduto aux2, void* prodtemp );
int novo_produto( bdproduto aux, void* prodtemp, int codigo, char nome_produto[MAXPALAVRA], int quantidade );
int incrementa_produto( bdproduto aux, int codigo, int valor_inc );
int imprimir_produto( bdproduto aux, int codigo );
int vender_produto( bdproduto aux, int cod, int quant_dec );
void guarda_posicao( void* aux, void* posicao );
void escrever_ficheiro_produtos ( void* aux, char nome_ficheiro[MAXPALAVRA] );
void limpa_vector( bdproduto aux );
int imprimir_produto_vendido ( bdproduto aux );

#endif


