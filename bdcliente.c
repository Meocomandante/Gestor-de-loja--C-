#include "bdcliente.h"

typedef struct _bdcliente{
	cliente cli[TAM_MAX];
	unsigned int ncli;
	
}infobdcliente, *apbdcliente;

/*Cria base de dados cliente*/
/*Input: */
/*Output: Apontador para estrutura bdcliente*/
bdcliente cria_bdcliente( )
{
	apbdcliente aux =(apbdcliente) malloc( sizeof( infobdcliente ) );
	
	if( aux == NULL ) return NULL;
	
	aux->ncli=0;
	
	return (bdcliente)aux;
}

/*Destroi estrutura*/
/*Input: Apontador para estrutura bdcliente*/
/*Output: */
void destroi_bdcliente( bdcliente aux )
{
	free( aux );
}

/*Lista clientes*/
/*Input: Apontador para estrutura bdcliente*/
/*Output: */
void lista_bdcliente( bdcliente aux )
{
	apbdcliente aux1 =(apbdcliente)aux;
	
	int i=0;
	while( i<=(aux1->ncli) )
	{
		imp_email( aux1->cli[i] );
		i++;
	}	
}

/*Lista clientes*/
/*Input: Apontador para estrutura bdcliente e cliente, nome do ficheiro*/
/*Output: Apontador para a estrutura*/
bdcliente ler_ficheiro_bdclientes ( char nome_ficheiro[MAXPALAVRA], bdcliente aux, void* clitemp )
{
	FILE *ficheiro_entrada;
	
	apbdcliente aux1 =(apbdcliente)aux;
	
	int conta_linha=0, ultimo_produto;
	char email[MAXPALAVRA];
	
	if( (ficheiro_entrada =fopen( nome_ficheiro ,"r")) ==NULL )
		printf("Erro de leitura do ficheiro: %s\n",nome_ficheiro);
	else{
		while( !feof(ficheiro_entrada) )
		{
			fscanf(ficheiro_entrada, " \"%[^\"]\" %d \n\r",email, &ultimo_produto);
			clitemp =cria_cliente( email, ultimo_produto );
			aux1->cli[conta_linha] =clitemp;
			conta_linha++;
		}
		fclose(ficheiro_entrada);
		aux1->ncli=conta_linha-1;
	}
	return (bdcliente)aux1;
}

/*Novo Registo de um cliente*/
/*Input: Apontador para estrutura bdcliente e cliente, email e o ultimo produto comprado por este*/
/*Output: Erro ou sem erro*/
int novo_registo( bdcliente aux, void* clitemp, char email[MAXPALAVRA], int ultimo_produto )
{
	apbdcliente aux1 =(apbdcliente)aux;
	
	int pos=0, controlo=sem_erro, i=0;
	
	if ( ((aux1->ncli)>=0)&&((aux1->ncli)<TAM_MAX) )
	{
		while ( i<=aux1->ncli ) 
		{
			controlo =compara_registo( aux1->cli[i], email );
			if ( controlo==erro ) 
			{
				break;
			}
			i++;
		}
		
		if ( controlo ==sem_erro ) 
		{
			(aux1->ncli)++;
			pos =aux1->ncli;
			clitemp =cria_cliente(email, ultimo_produto);
			aux1->cli[pos] =clitemp;
		}
		else
			printf("Cliente ja existe\n");
	}
	else
	{
		return erro;
	}
	return sem_erro;
}

/*Vereifica cliente*/
/*Input: Apontador para estrutura bdcliente email, poiscao do cliente*/
/*Output: Erro ou sem erro*/
int verifica_cliente( bdcliente aux, char email[MAXPALAVRA], int *posicao )
{
	apbdcliente aux1 =(apbdcliente)aux;
	int i=0, controlo =sem_erro;
	
	if ( ((aux1->ncli)>=0) && ((aux1->ncli)<TAM_MAX) )
	{
		while ( i<=(aux1->ncli) ) 
		{
			controlo =compara_registo( aux1->cli[i], email );
			if ( controlo==erro ) {
				*posicao=i;
				return sem_erro;
			}
			i++;
		}
		return erro;
	}
	return erro;
}

/*Escreve ultimo produto na estrutura*/
/*Input: Apontador para estrutura bdcliente ,posicao do cliente e o codigo de produto*/
/*Output: */
void escreve_codigo_produto( bdcliente aux, int *i, int codigo_produto )
{
	apbdcliente aux1 =(apbdcliente)aux;
	
	escreve_produto ( aux1->cli[*i], codigo_produto );
}

/*Lista cliente*/
/*Input: Apontador para estrutura bdcliente, poiscao do cliente*/
/*Output: produto*/
int lista_cliente( bdcliente aux, int i )
{
	apbdcliente aux1 =(apbdcliente) aux;
	int prod=0;
	
	prod=imp_cliente ( aux1->cli[i] );

	return prod;
}

/*Numero de clientes*/
/*Input: Apontador para estrutura bdcliente*/
/*Output: numero de clientes*/
int num_cli ( bdcliente aux )
{
	apbdcliente aux1 =(apbdcliente)aux;
	
	return (aux1->ncli);
}

/*Escreve no ficheio a base de dados dos clientes*/
/*Input: Apontador para estrutura bdcliente e nome do ficheiro*/
/*Output: */
void escrever_ficheiro_clientes ( void* aux, char nome_ficheiro[MAXPALAVRA] )
{
	apbdcliente aux1 =(apbdcliente) aux;
	int i=0;
	
	FILE* ficheiro_saida;
	
	if( (ficheiro_saida =fopen(nome_ficheiro,"w+") )==NULL )
	{
		printf("Erro na abertura do ficheiro %s", nome_ficheiro);
	}
	else
	{
		while( i <= (aux1->ncli) )
		{
			imp_ficheiro_cliente( aux1->cli[i], ficheiro_saida );
			i++;
		}	
		
		fclose(ficheiro_saida);
	}
}

