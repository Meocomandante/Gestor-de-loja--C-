#ifndef _H_PRODUTO
#define _H_PRODUTO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXprod 40
#define MAXPALAVRA 40
#define erro 0
#define sem_erro 1

/*Defini��o do tipo de TAD*/
typedef void* produto;

/*Prot�tipo das fun��es*/
produto cria_produto( char nome[MAXPALAVRA], int codigo, int quantidade, int quant_vendida );
void destroi_produto( produto aux1 );
void imp_produto( produto aux1 );/*fora do tad*/
void inc_produto( produto aux1, int valor_inc );
void inc_venda( produto aux1, int valor_inc );
int dec_produto( produto aux1, int quant_dec );
int compara_produto( int codigo, produto aux );
int quantidade_vendas( produto aux );
void imp_ficheiro( produto aux, FILE* ficheiro_saida );

#endif
