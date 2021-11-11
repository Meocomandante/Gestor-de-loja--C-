#include "loja.h"

int main ( ) 
{
		
	cliente _cliente;
	bdcliente base_cliente;
	bdproduto base_produto;
	produto _produto;
	
	char comando[COMANDO_TAM], comando2[MAXPALAVRA], nome[MAXPALAVRA];
	int ciclo=1, quantidade=0, i=0;
	
	base_cliente =cria_bdcliente();
	base_produto =cria_bdproduto();
	base_cliente =ler_ficheiro_bdclientes ("clientes.txt", base_cliente, _cliente );
	base_produto =ler_ficheiro_bdproduto("inventario.txt", base_produto, _produto);
	
	while(ciclo)
	{
		
		scanf(" %s",comando);
		
		for( i=0; i<=COMANDO_TAM; i++ )
			comando[i]=toupper( comando[i] );
		
		
		if( !strcmp( comando, "RC" ) )
		{
			scanf(" \"%[^\"]\"",comando2);
			
			comando_RC(  _cliente, base_cliente, comando2 );
		}
		if( !strcmp( comando, "RP" ) )
		{
			scanf(" \"%[^\"]\" \"%[^\"]\" %d",comando2, nome, &quantidade);
			
			comando_RP ( _produto, base_produto, comando2, nome, quantidade );
		}
		if( !strcmp( comando, "IP" ) )
		{
			scanf(" \"%[^\"]\" %d",comando2, &quantidade);
			
			comando_IP( base_produto, comando2, quantidade );
		}
		if( !strcmp( comando, "CP" ) )
		{
			scanf(" \"%[^\"]\"",comando2);
			
			comando_CP( base_produto, comando2 );
		}
		if( !strcmp( comando, "VP" ) )
		{
			scanf(" \"%[^\"]\" \"%[^\"]\" %d", comando2, nome, &quantidade);
			
			comando_VP ( base_produto, base_cliente, comando2, nome, quantidade );
		}
		if( !strcmp( comando, "LC" ) )
			comando_LC ( base_cliente, base_produto );
		if( !strcmp( comando, "TP" ) )
			comando_TP ( base_produto );
		if( !strcmp( comando, "S" ) )
		{
			escrever_ficheiro_clientes( base_cliente, "clientes.txt" );
			escrever_ficheiro_produtos( base_produto, "inventario.txt" );
			ciclo =0;
		}
		printf("\n");
	}
	
	return 0;
}
