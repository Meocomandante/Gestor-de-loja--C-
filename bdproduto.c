#include "bdproduto.h"

typedef struct{
	produto prod[PROD_MAX];
	unsigned int nprod;
	produto prod_vendido[PROD_MAX];
	unsigned int nvendas;
	int max_vendas;
}infobdproduto, *apbdproduto;

/*Aloca a memoria da estrutura bdproduto*/
/*Input: */
/*Output: Apontador para estrutura*/
bdproduto cria_bdproduto( )
{
	apbdproduto aux =(apbdproduto) malloc(sizeof(infobdproduto));
	
	if( aux == NULL ) return NULL;
	
	aux->nprod=0;
	aux->nvendas=0;
	
	return (bdproduto)aux;
}

/*Destroi a estrutura apontado pelo apontador*/
/*Input: apontador para bdproduto*/
/*Output: */
void destroi_bdproduto( bdproduto aux1 )
{
	free( aux1 );
}

/*Lista os produtos guardados no vector da estrutura bdproduto*/
/*Input: Apontador para bdproduto*/
/*Output: */
void lista_bdproduto( bdproduto aux2 )
{
	apbdproduto aux1=(apbdproduto)aux2;
	int i=0;
	
	while( i<=(aux1->nprod) )
	{
		imp_produto ( aux1->prod[i] );
		i++;
	}
}

/*Le do ficheiro cliente para guardar na estrutura*/
/*Input: nome do ficheiro, apontador para a estrutura bdproduto e para produto*/
/*Output: apontador para a estrutura*/
bdproduto ler_ficheiro_bdproduto ( char nome_ficheiro[MAXPALAVRA], bdproduto aux2, void* prodtemp )
{	
	FILE *ficheiro_entrada;
	apbdproduto aux1 =(apbdproduto)aux2;
	char nome_prod[MAXPALAVRA];
	int codigo_prod=0, quantidade_produto=0, quantidade_vendida=0;
	int conta_linhas=0;
	
	if( (ficheiro_entrada=fopen(nome_ficheiro, "r") )==NULL )
	{
		printf("Erro de Leitura de ficheiro %s\n",nome_ficheiro);
		return erro;
	}
	else
	{
		while( !feof(ficheiro_entrada) )
		{
			fscanf(ficheiro_entrada, "%d \"%[^\"]\" %d %d\n\r", &codigo_prod,nome_prod, &quantidade_produto, &quantidade_vendida );
			prodtemp =cria_produto(nome_prod, codigo_prod, quantidade_produto, quantidade_vendida);
			aux1->prod[conta_linhas] =prodtemp;
			conta_linhas++;
		}
		fclose(ficheiro_entrada);
		aux1->nprod =(conta_linhas-1);
		return (bdproduto)aux1;
	}
}

/*Regista um novo produto*/
/*Input: Apontador para estrutura bdproduto e para produto, codigo, nome do produto e a quantidade*/
/*Output: Sucesso e o nao sucesso*/
int novo_produto( bdproduto aux, void* prodtemp, int codigo, char nome_produto[MAXPALAVRA], int quantidade )
{
	apbdproduto aux1 =(apbdproduto)aux;
	int pos=0, controlo=sem_erro, i=0;
	
	if ( ((aux1->nprod)>=0) && ((aux1->nprod)<=PROD_MAX) ) 
	{
		while( i<=(aux1->nprod) )
		{
			controlo =compara_produto(codigo, aux1->prod[i]);
			
			if (controlo == erro) 
			{
				return 2;
			}
			i++;
		}
		if(controlo == sem_erro)
		{
			(aux1->nprod)++;
			pos =aux1->nprod;
			prodtemp =cria_produto( nome_produto, codigo, quantidade, 0 );
			aux1->prod[pos] =prodtemp;
		}
	}
	else {
		return erro;
	}
	return sem_erro;
}

/*Incrementa um produto por um valor a escolha pelo utilizador*/
/*Input: Apontador para a estrutura bdproduto, codigo e o valor a incrementar*/
/*Output: sucesso ou nao sucesso*/
int incrementa_produto ( bdproduto aux, int codigo, int valor_inc )
{
	apbdproduto aux1 =(apbdproduto)aux;
	int controlo =sem_erro;
	int i=0;
	
	while( i<=(aux1->nprod) )
	{
		controlo =compara_produto( codigo, aux1->prod[i] );
		
		if(controlo == erro)
		{
			inc_produto ( aux1->prod[i], valor_inc );
			return sem_erro;
		}
		i++;
	}
	return erro;
}

/*Imprime um produto*/
/*Input: Apontador para bdproduto e codigo*/
/*Output: sucesso e o nao sucesso*/
int imprimir_produto ( bdproduto aux, int codigo )
{
	apbdproduto aux1 =(apbdproduto)aux;
	int i=0, controlo;
	
	while( i<=(aux1->nprod) )
	{
		controlo =compara_produto(codigo, aux1->prod[i]);
		if(controlo == erro)
		{
			imp_produto( aux1->prod[i] );
			return sem_erro;
		}
		i++;
	}
	return erro;
}

/*Imprimir produto vendido*/
/*Input: Apontador para bdproduto*/
/*Output: Sucesso ou nao sucesso*/
int imprimir_produto_vendido ( bdproduto aux )
{
	apbdproduto aux1 =(apbdproduto)aux;
	int i,pos_ini =(aux1->nvendas)-1;
	
	if ( (aux1->nvendas)!=0 ) {
		
		for ( i=pos_ini; i>=0; i-- ) 
		{
			imp_produto( aux1->prod_vendido[i] );
		}
		return sem_erro;
	}
	return erro;
}
/*vender produto*/
/*Input: Apontador para a estrutura bdproduto, codigo d produto e a quantidade a vebnder*/
/*Output: sucesso ou nao sucesso*/
int vender_produto ( bdproduto aux, int cod, int quant_dec )
{
	apbdproduto aux1 =(apbdproduto)aux;
	int i=0, controlo=0, controlo2=0;
	
	while( i<=(aux1->nprod) )
	{
		controlo =compara_produto( cod, aux1->prod[i] );

		if(controlo == erro)
		{
			controlo2 =dec_produto( aux1->prod[i], quant_dec );
			
			if(controlo2 == sem_erro)
			{
				inc_venda( aux1->prod[i], quant_dec );
				guarda_posicao( aux, aux1->prod[i] );
				return sem_erro;
			}
			else {
				imprimir_produto ( aux, cod );
				return sem_erro;
			}

			return erro;
		}
		i++;
	}
	return erro;
}

/*Guarda por ordem o produto vendido*/
/*Input: Apontador para bdproduto e o apontador do produto acabado de vender*/
/*Output: */
void guarda_posicao( void* aux, void* posicao )
{
	apbdproduto aux1 =(apbdproduto)aux;
	int i;
	
	for( i=0; i<=(aux1->nvendas); i++ )
	{
			
		if(aux1->nvendas == 0)
		{
			(aux1->nvendas)++;
			aux1->prod_vendido[i] =posicao;
			aux1->max_vendas =quantidade_vendas(posicao);
			break;
		}
		else
		{
			if( aux1->max_vendas == quantidade_vendas(posicao) )
			{
				(aux1->nvendas)++;
				aux1->prod_vendido[aux1->nvendas-1] =posicao;
				break;
			}
			else
			{
				if (aux1->max_vendas < quantidade_vendas(posicao)) 
				{
					aux1->max_vendas =quantidade_vendas(posicao);
					limpa_vector(aux);
					(aux1->nvendas)++;
					aux1->prod_vendido[0] =posicao;
					break;
				}
			}
		}
	}
}

/*Limpa um vector*/
/*Input: Apontador para bdproduto*/
/*Output: */
void limpa_vector( bdproduto aux )
{
	apbdproduto aux1 =(apbdproduto)aux;
	int i;
	
	for( i=0; i<=aux1->nvendas; i++ )
	{
		aux1->prod_vendido[i] =NULL;
	}
	aux1->nvendas =0;
}

/*Escreve num ficheiro todos os dados dos produtos*/
/*Input: Apontador para a estrutura bdproduto e o nome do ficheiro*/
/*Output: */
void escrever_ficheiro_produtos ( void* aux, char nome_ficheiro[MAXPALAVRA] )
{
	FILE* ficheiro_saida;
	apbdproduto aux1 =(apbdproduto)aux;
	int i=0;
		
	if( (ficheiro_saida =fopen(nome_ficheiro,"w+") )==NULL )
	{
		printf("Erro na abertura do ficheiro %s",nome_ficheiro);
	}
	else
	{
		while( i<=(aux1->nprod) )
		{
			imp_ficheiro( aux1->prod[i], ficheiro_saida );
			i++;
		}	
		fclose(ficheiro_saida);
	}
}
