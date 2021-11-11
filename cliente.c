#include "cliente.h"

typedef struct{
	char email[MAXclientes];
	int ult_prod;/*produto*/
}infocliente , *apcliente;

/*Cria um cliente */
/*Input: email e o ultimo produto */
/*Output: aux(apontador da estrutura cliente) */
cliente cria_cliente( char mail[MAXPALAVRA], int ultimo_produto )
{
	apcliente aux =(apcliente)malloc( sizeof(infocliente) );
	
	
	if( aux == NULL ) return NULL;
	
	strcpy( aux->email, mail );
	aux->ult_prod =ultimo_produto;
	
	return (cliente)aux;
}

/*Destroi cliente */
/*Input: aux(apontador da estrutura cliente) */
/*Output: */
void destroi_cliente( cliente aux )
{
	free( aux );
}

/*Imprime os dados do cliente no ecran */
/*Input: aux(apontador da estrutura cliente) */
/*Output: */
void imp_email ( cliente aux )
{
	apcliente aux1 =(apcliente)aux;
	
	printf("%s %d\n", aux1->email , aux1->ult_prod);	
}

/*Compara um registo do cliente */
/*Input: aux (apontador da estrutura cliente) e o email */
/*Output: erro, caso encontre, sem_erro caso nao encontre */
int compara_registo( cliente aux, char email[MAXPALAVRA] )
{
	apcliente aux1 =(apcliente)aux;
	
	if ( !(strcmp( aux1->email, email )) ) {
		return erro;
	}
	return sem_erro;	
}

/*Escreve um o ultimo produt comprado pelo cliente na estrutura */
/*Input: aux (apontador da estrutura cliente) e codigo do produto */
/*Output:  */
void escreve_produto ( cliente aux, int codigo )
{
	apcliente aux1 =(apcliente)aux;
	
	aux1->ult_prod =codigo;
}

/*Imprime o email do cliente */
/*Input: aux (apontador da estrutura cliente) e o email */
/*Output: o ultimo produto do cliente */
int imp_cliente( cliente aux )
{
	apcliente aux1 =(apcliente) aux;
	
	printf("<%s>\n", aux1->email );
	
	return aux1->ult_prod;
}

/*Regista os dados de todos os clientes existentes da estrutura de dados num ficheiro */
/*Input: aux (apontador da estrutura cliente) e o apontador do ficheiro */
/*Output: ficheiro inventario.txt */
void imp_ficheiro_cliente( cliente aux, FILE* ficheiro_saida )
{
	apcliente aux1 =(apcliente)aux;
	
	fprintf(ficheiro_saida, " \"%s\" %d \n", aux1->email, aux1->ult_prod );
}
