#ifndef _H_LOJA
#define _H_LOJA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "produto.h"
#include "cliente.h"
#include "bdcliente.h"
#include "bdproduto.h"

#define COMANDO_TAM 2
#define LIMPA_ECRAN 15
#define MAXPALAVRA 40
#define erro 0
#define sem_erro 1
#define TAM_MAX 10

/*Defini��o de TAD.*/
typedef bdproduto base_produto;
typedef bdcliente base_cliente;

/*Prot�tipo das fun��es*/
int sting_converte_int( char string[] );
int verifica_mail( char email[MAXPALAVRA] );
void comando_RC( void* _cliente, void* base_cliente , char email[] );
void comando_RP( void* _produto, void* base_produto, char comando2[], char nome_produto[], int quantidade );
void comando_IP( bdproduto base_produto, char comando2[], int valor_inc );
void comando_CP( bdproduto base_produto, char comando2[] );
void comando_VP( bdproduto base_produto, bdcliente base_cliente, char comando2[], char email[], int quantidade );
void comando_LC( bdcliente base_cliente, bdproduto base_produto );
void comando_TP( bdproduto base_produto );

#endif
