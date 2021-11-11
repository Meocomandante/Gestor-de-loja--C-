#include "produto.h"

typedef struct{
	int codigo_produto;
	char nome_prod[MAXprod];
	int quantidade_prod;
	int quantidade_vendida;
}infoproduto, *approduto;

/*Cria produto*/
/*Input: nome, codigo, quantidade e a quantidade vendida*/
/*Output: Apontador para a estrutura produto*/
produto cria_produto ( char nome[MAXPALAVRA], int codigo, int quantidade, int quant_vendida )
{
	approduto aux =(approduto) malloc( sizeof(infoproduto) );
	
	if (aux == NULL) return NULL;
	
	aux->codigo_produto =codigo;
	strcpy( aux->nome_prod, nome );
	aux->quantidade_prod =quantidade;
	aux->quantidade_vendida =quant_vendida;
	return (produto)aux;
}

/*Destroi a estrutura produto*/
/*Input: Apontador para a estrutura produto*/
/*Output: */
void destroi_produto( produto aux1 )
{
	free( aux1 );
}

/*Imprimir produto*/
/*Input: Apontador para a estrutura produto*/
/*Output: */
void imp_produto( produto aux1 )
{
	approduto aux2 =(approduto)aux1;
	
	printf("<%d> \n<%s> \n<%d> \n\n", aux2->codigo_produto, aux2->nome_prod, aux2->quantidade_prod);
}

/*Incrementa a quantidade do produto*/
/*Input: Apontador para a estrutura produto mais o valor a incrementar*/
/*Output: */
void inc_produto ( produto aux1, int valor_inc )
{
	approduto aux2 =(approduto)aux1;
	
	(aux2->quantidade_prod)+=valor_inc;
}

/*Incrementa a quantidade vendida*/
/*Input: Apontador para a estrutura produto mais o valor que se vendeu*/
/*Output: */
void inc_venda ( produto aux1, int valor_inc )
{
	approduto aux2 =(approduto)aux1;
	
	(aux2->quantidade_vendida)+=valor_inc;
}

/*Decrementa a quantidade em stock de um produto*/
/*Input: Apontador para a estrutura produto mais a quantidade vendida*/
/*Output: sucesso caso o valor em stock seja maior que quantidade vendida, incusesso caso contrario*/
int dec_produto ( produto aux1, int quant_dec )
{
	approduto aux2 =(approduto)aux1;
	
	if( (aux2->quantidade_prod)<quant_dec )
		return erro;
	else
		(aux2->quantidade_prod)-=quant_dec;
	return sem_erro;
	
}

/*Compara o produto na base de dados produto*/
/*Input: Apontador para a estrutura produto mais o produto*/
/*Output: Erro caso encontre, sem erro caso contrairio*/
int compara_produto( int codigo, produto aux )
{
	approduto aux1 =(approduto)aux;
	
	if ( (aux1->codigo_produto) == (codigo) ) 
	{
		return erro;
	}
	return sem_erro;
}

/*Quantidade que foi vendida*/
/*Input: Apontador para a estrutura produto*/
/*Output: Quantidade*/
int quantidade_vendas( produto aux )
{
	approduto aux1 =(approduto)aux;
	
	return aux1->quantidade_vendida;
}

/*Imprime no ficheiro*/
/*Input: Apontador para a estrutura produto mais o nome do ficheiro*/
/*Output: */
void imp_ficheiro( produto aux, FILE* ficheiro_saida )
{
	approduto aux1 =(approduto)aux;
	
	fprintf(ficheiro_saida, " %d \"%s\" %d %d\n", aux1->codigo_produto, aux1->nome_prod, aux1->quantidade_prod, aux1->quantidade_vendida);
}
