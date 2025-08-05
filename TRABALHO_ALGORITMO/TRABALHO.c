#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int codigo;
	char nome[20];
	char CPF[11];
	char telefone[9];
	char dataNasc[8];
	char endereco[50];
	int ativo;
}Clientes;

typedef struct{
	char dataCompra[8];
	float valorTotal;
	char formaPag[20];
	char quitada;
	int codigoCliente;
	int ativo;
}Compras;


Clientes * cadastrarClientes(Clientes *vetC, int *qtdC);

int main(){
	Clientes *vetCliente = NULL;
	Compras *vetCompra = NULL;
	
	printf("O QUE DESEJA FAZER? \n\n");
	int n, qtdClientes = 0, qtdCompras = 0;
	
	do{
		printf("CADASTRAR CLIENTE (1)\n");
		printf("CADASTRAR COMPRAS (2)\n");
		printf("EXIBIR TODOS OS REGISTROS (3)\n");
		printf("ATUALIZAR DADOS DE CLIENTES (4)\n");
		printf("ATUALIZAR DADOS DE COMPRAS (5)\n");
		printf("ATIVAR OU DESATIVAR UM REGISTRO (6)\n");
		printf("DIGITE 0 PARA FINALIZAR\n");
		scanf("%d", &n);
		if(n == 1)
			vetCliente = cadastrarClientes(vetCliente, &qtdClientes);
	}while(n != 0);
}

Clientes * cadastrarClientes(Clientes *vetC, int *qtdC){
	
	int clientes;
	printf("Quantos clientes deseja cadastrar? ");
	scanf("%d", &clientes);
	
	int qtdNovo = *qtdC + clientes;
	
	vetC = (Clientes *)realloc(vetC, qtdNovo*sizeof(Clientes));
	for(int i = *qtdC; i < qtdNovo; i++){
		printf("Digite o código do cliente: ");
		scanf("%d", &vetC[i].codigo);
		getchar();
		printf("Digite o nome do cliente: ");
		fgets(vetC[i].nome, 20, stdin);
		vetC[i].nome[strcspn(vetC[i].nome, "\n")] = '\0';
		printf("Digite o CPF do cliente: ");
		fgets(vetC[i].CPF, 11, stdin);
		vetC[i].CPF[strcspn(vetC[i].CPF, "\n")] = '\0';
		printf("Digite o telefone do cliente: ");
	    fgets(vetC[i].telefone, 9, stdin);
		vetC[i].telefone[strcspn(vetC[i].telefone, "\n")] = '\0';
		printf("Digite a data de nascimento do cliente: ");
		fgets(vetC[i].dataNasc, 8, stdin);
		vetC[i].dataNasc[strcspn(vetC[i].dataNasc, "\n")] = '\0';
		printf("Digite o endereço do cliente: ");
		fgets(vetC[i].endereco, 50, stdin);
		vetC[i].endereco[strcspn(vetC[i].endereco, "\n")] = '\0';
		
		vetC[i].ativo = 1;
	}
	*qtdC = qtdNovo;
	printf("\n\n");
	
	return vetC;
}

Compras * cadastrarCompras(Compras *vetComp, int *qtdComp){
	
	int compras;
	printf("Quantas compras deseja cadastrar? ");
	scanf("%d", &compras);
	
	int qtdNovoC = *qtdComp + compras;
	
	vetComp = (Compras *)realloc(vetC, qtdNovoC*sizeof(Compras));
	for(int i = *qtdComp; i < qtdNovoC; i++){
		printf("Digite o codigo da compra do cliente: ");
		scanf("%d", &vetComp[i].codigoCliente);
		getchar();
		printf("Digite a data da compra: ");
		fgets(vetComp[i].dataCompra, 8, stdin);
		vetComp[i].dataCompra[strcspn(vetComp[i].dataCompra, "\n")] = '\0';

	}
	
}
