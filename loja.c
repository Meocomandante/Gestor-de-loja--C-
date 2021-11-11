#include "loja.h"

/*Converte uma string para um inteiro*/
/*Input: string*/
/*Output: resultado (inteiro que reside na string)*/
int sting_converte_int( char string[] )
{
	int n_caracteres; 
	int i=0, resultado=0;
	
	n_caracteres =strlen(string);
	
	for( i=0; i<n_caracteres; i++ )
	{
		resultado =(resultado*10)+string[i]-'0';
	}
	return resultado;
}

/*Verifica o email, ou seja verifica se a string contem um @*/
/*Input: email*/
/*Output: Erro caso nao tenha @ e sem_erro caso tenha @*/
int verifica_mail( char email[] )
{
	if( strchr(email,'@') != NULL )
		return sem_erro;
	return erro;
}

/*Comando RC gere os dados de entrada e saida para poder registar um novo cliente*/
/*Input: Apontador para a estrutura ciente, e para a base de cliente e o email*/
/*Output: */
void comando_RC( void* _cliente, void* base_cliente , char email[] )
{
	int ver_mem =sem_erro,ver_email =sem_erro;
	
	ver_email =verifica_mail(email);
	
	if( ver_email == sem_erro )
		ver_mem =novo_registo( base_cliente, _cliente, email, 0 );
		
	else
		printf("Nao escreveu um email\n");
	
	if( ver_mem == erro )
		printf("Erro! Memoria cheia\n");
}

/*Comando RP gere os dados de entrada e saida para poder registar um novo produto*/
/*Input: Apontador para as estruturas produto e bdproduto, comando2(codigo do produto), nome produto e a quantidade*/
/*Output: */
void comando_RP ( void* _produto, void* base_produto, char comando2[], char nome_produto[], int quantidade )
{
	int codigo=0, ver_mem=0;
	
	codigo =sting_converte_int(comando2);
	
	ver_mem =novo_produto( base_produto, _produto, codigo, nome_produto, quantidade );
	
	if (ver_mem == erro)
	{
		printf("Erro! Memoria cheia\n");
	}
	else
		if(ver_mem == 2)
		{
			printf("\nProduto ja existe!!\n");	
		}
			else
				if (ver_mem == sem_erro)
				printf("\nProduto registado\n");
}

/*Comando IP, gere os dados de entrada e saida para poder incrementar um produto existente*/
/*Input: Apontadore para a base de dados bdproduto comando2(codigo do produto) e o valor a incrementar*/
/*Output:*/
void comando_IP( bdproduto base_produto, char comando2[], int valor_inc )
{
	int codigo=0, controlo=0;

	codigo =sting_converte_int(comando2);
	
	controlo =incrementa_produto ( base_produto, codigo, valor_inc );
	
	if(controlo==erro)
		printf("Produto nao registado\n");
	else
		printf("Sucesso ao incrementar o produto\n");
}

/*Comando CP, gere os dados de enrada e saida para poder consultar os dados de um dado produto*/
/*Input: Apontador para a base de dados bdproduto e o comando2(codigo produto)*/
/*Output: */
void comando_CP( bdproduto base_produto, char comando2[] )
{
	int codigo=0, controlo =sem_erro;
	
	codigo =sting_converte_int( comando2 );
	
	controlo =imprimir_produto ( base_produto, codigo );
	
	if(controlo == erro)
		printf("Produto nao registado\n");
}

/*Comando VP, gere os dados de entrada e siada para vender um produto*/
/*Input: Apontadores para as bases de dados bdproduto e bdcliente, comando2(codigo do produto), o email do cliente mais a quantidade que se pretende vender*/
/*Output: */
void comando_VP ( bdproduto base_produto, bdcliente base_cliente, char comando2[], char email[], int quantidade )
{
	int controlo =sem_erro, controlo2 =sem_erro;
	int posicao=0,codigo_venda=0;
	
	codigo_venda =sting_converte_int(comando2);
	
	controlo =verifica_cliente( base_cliente, email, &posicao );
	
	if(controlo == sem_erro)
	{
		controlo2 =vender_produto( base_produto, codigo_venda, quantidade );
		if( controlo2 == erro)
			printf("Produto nao registado\n");
	}
		else
			printf("Erro! Nao existe cliente registado\n");
	if( (controlo == sem_erro) && (controlo2 == sem_erro) )
	{
		escreve_codigo_produto( base_cliente, &posicao, codigo_venda );
	}
}

/*Comando LC, gere os dados de entrada para poder listar todos o clientes existentes na base de dados*/
/*Input: Apontador para a base de dados bdcliente e bdproduto*/
/*Output: */
void comando_LC ( bdcliente base_cliente, bdproduto base_produto )
{
	int prod, i, num=0, lixo;
	
	num =num_cli( base_cliente );
	
	for( i=0; i<=num; i++ )
	{
		prod =lista_cliente( base_cliente, i);
		lixo =imprimir_produto(base_produto, prod);
	}
}

/*Comando TP, mostra o ranking do produto mais vendido*/
/*Input: Apontador para a base de dados bdproduto*/
/*Output: */
void comando_TP ( bdproduto base_produto )
{
	int controlo =sem_erro;
	
	controlo =imprimir_produto_vendido ( base_produto );
	
	if(controlo == erro)
		printf("Nao vendeu nenhum produto\nComo tal nao é possivel fazer o ranking\n");
}

