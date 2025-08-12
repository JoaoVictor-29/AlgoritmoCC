#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int codigo;
	char nome[50];
	char CPF[14];
	char telefone[12];
	char dataNasc[13];
	char endereco[50];
	int ativo;
}Clientes;

typedef struct{
	char dataCompra[13];
	float valorTotal;
	char formaPag[25];
	char quitada;
	int codigoCliente;
	int ativo;
}Compras;


Clientes * cadastrarClientes(Clientes *vetComp, int *qtdC);
void salvar_arquivoBin_cliente(Clientes *vet_Cliente,int quant_Cliente);
Compras * cadastrarCompras(Compras *vetComp, int *qtdComp);
void salvar_arquivoBin_compra(Compras *vet_Compra,int quant_Compra);
void exibirRegistrosCliente(Clientes *vetC, int qtdC);
void exibirRegistrosCompras(Compras *vetComp, int qtdComp);
void statusCliente(Clientes *vetC, int qtdC);
void statusCompras(Compras *vetComp, int qtdComp);

int main(){
	Clientes *vetCliente = NULL;
	Compras *vetCompra = NULL;
    //FILE *pont_compra;
    //FILE *pont_cliente;
	
	printf("O QUE DESEJA FAZER? \n\n");
	int n, qtdClientes = 0, qtdCompras = 0;
	
	do{
		printf("CADASTRAR CLIENTE (1)\n");
        printf("SALVAR ARQUIVO BINARIO (2)\n");
		printf("CADASTRAR COMPRAS (3)\n");
		printf("EXIBIR REGISTROS DE CLIENTES (4)\n");
		printf("EXIBIR REGISTROS DE COMPRAS (5)\n");
		printf("ATUALIZAR DADOS DE CLIENTES (6)\n");
		printf("ATUALIZAR DADOS DE COMPRAS (7)\n");
		printf("ATIVAR OU DESATIVAR UM REGISTRO DE CLIENTE (8)\n");
		printf("ATIVAR OU DESATIVAR UM REGISTRO DE COMPRA (9)\n");
		printf("DIGITE 0 PARA FINALIZAR\n");
		scanf("%d", &n);
		switch (n)
        {
        case 1:
           vetCliente = cadastrarClientes(vetCliente, &qtdClientes);
            break;
        case 2:
          salvar_arquivoBin_cliente(vetCliente, qtdClientes);
          salvar_arquivoBin_compra(vetCompra, qtdCompras);
          printf("\nArquivo salvo com sucesso!\n\n");
           break;
		case 3 :
			vetCompra = cadastrarCompras(vetCompra, &qtdCompras);
			break;
		case 4:
			exibirRegistrosCliente(vetCliente, qtdClientes);
			break;
		case 5:
			exibirRegistrosCompras(vetCompra, qtdCompras);
			break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            statusCliente(vetCliente, qtdClientes);
            break;
        case 9:
            statusCompras(vetCompra, qtdCompras);
        default:
            break;
        } 
	}while(n != 0);

	free(vetCliente);
	free(vetCompra);
}
Clientes * cadastrarClientes(Clientes *vetC, int *qtdC){
	
	int clientes;
	printf("Quantos clientes deseja cadastrar? ");
	scanf("%d", &clientes);
	
	int qtdNovo = *qtdC + clientes;
	
	vetC = (Clientes *)realloc(vetC, qtdNovo*sizeof(Clientes));
	
	for(int i = *qtdC; i < qtdNovo; i++){
		int codigoVal; //pra garantir que o codigo não vai se repetir
		do{
			codigoVal = 1;
			printf("Digite o código do cliente: ");
			scanf("%d", &vetC[i].codigo);
			
			for(int j = 0; j < i; j++){
				if(vetC[j].codigo == vetC[i].codigo){
					printf("Código já existente!\n");
					codigoVal = 0;
					break;
				}
			}
				
		}while(!codigoVal);
		getchar();
		printf("Digite o nome do cliente: ");
		fgets(vetC[i].nome, 20, stdin);
		vetC[i].nome[strcspn(vetC[i].nome, "\n")] = '\0';
		
		do{
			codigoVal = 1;
			printf("Digite o CPF do cliente: ");
			fgets(vetC[i].CPF, 14, stdin);
			vetC[i].CPF[strcspn(vetC[i].CPF, "\n")] = '\0';
			
			for(int j = 0; j < i; j++){
				if(strcmp(vetC[j].CPF, vetC[i].CPF) == 0){
					printf("CPF já existente!\n");
					codigoVal = 0;
					break;
				}
			}
		}while(!codigoVal);
		
		printf("Digite o telefone do cliente: ");
	    fgets(vetC[i].telefone, 12, stdin);
		vetC[i].telefone[strcspn(vetC[i].telefone, "\n")] = '\0';
		printf("Digite a data de nascimento do cliente: ");
		fgets(vetC[i].dataNasc, 13, stdin);
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
//funções de salvar no arquivo binario (Da pra jogarem num sub menu dos cadastros pra n ficar mt cheio o menu principal)
void salvar_arquivoBin_cliente(Clientes *vet_Cliente,int quant_Cliente){
    FILE *pont_arqBin;
    pont_arqBin = fopen("cliente.bin","wb");
      if(pont_arqBin){
          fwrite(&quant_Cliente, sizeof(int), 1, pont_arqBin);
          fwrite(vet_Cliente,sizeof(Clientes),quant_Cliente,pont_arqBin);
          fclose(pont_arqBin);
      }
      else{
        printf("ERROOOO- MELHOR CONSERTAR");
      }
}
void salvar_arquivoBin_compra(Compras *vet_Compra,int quant_Compra){
    FILE *pont_arqBin;
    pont_arqBin = fopen("compra.bin","wb");
      if(pont_arqBin){
          fwrite(&quant_Compra, sizeof(int), 1, pont_arqBin);
          fwrite(vet_Compra,sizeof(Compras),quant_Compra,pont_arqBin);
          fclose(pont_arqBin);
      }
      else{
        printf("ERROOOO- MELHOR CONSERTAR");
      }
}

Compras * cadastrarCompras(Compras *vetComp, int *qtdComp){
	
	int compras;
	printf("Quantas compras deseja cadastrar? ");
	scanf("%d", &compras);
	
	int qtdNovoC = *qtdComp + compras;
	
	vetComp = (Compras *)realloc(vetComp, qtdNovoC*sizeof(Compras));
	for(int i = *qtdComp; i < qtdNovoC; i++){
		printf("Digite o codigo da compra do cliente: ");
		scanf("%d", &vetComp[i].codigoCliente);
		getchar();
		printf("Digite a data da compra: ");
		fgets(vetComp[i].dataCompra, 13, stdin);
		vetComp[i].dataCompra[strcspn(vetComp[i].dataCompra, "\n")] = '\0';
		printf("Digite a forma de pagamento: (Cartao de credito, PIX, Dinheiro, Boleto) ");
		fgets(vetComp[i].formaPag, 25, stdin);
		vetComp[i].formaPag[strcspn(vetComp[i].formaPag, "\n")] = '\0';
		printf("A compra está quitada? ");
		scanf("%s", &vetComp[i].quitada);
		printf("Digite o valor total: ");
		scanf("%f", &vetComp[i].valorTotal);
		
		vetComp[i].ativo = 1;
	}
	*qtdComp = qtdNovoC;
	printf("\n\n");
	
	return vetComp;
}

void exibirRegistrosCliente(Clientes *vetC, int qtdC){
	
	if(qtdC == 0){
		printf("Nenhum registro de cliente!\n\n");
		return;
	}
	
	printf("---REGISTROS DE CLIENTES ATIVOS---\n\n");
	
	for(int i = 0; i < qtdC; i++){
		if(vetC[i].ativo == 1){
			printf("Codigo do cliente: %d\n", vetC[i].codigo);
			printf("Nome: %s\n", vetC[i].nome);
			printf("CPF: %s\n", vetC[i].CPF);
			printf("Telefone: %s\n", vetC[i].telefone);
			printf("Data de Nascimento: %s\n", vetC[i].dataNasc);
			printf("Endereço: %s\n\n", vetC[i].endereco);
		}
	}
	
}

void exibirRegistrosCompras(Compras *vetComp, int qtdComp){
	
	if(qtdComp == 0){
		printf("Nenhum registro de compra!\n\n");
		return;
	}
	
	printf("---REGISTROS DE COMPRAS ATIVAS---\n\n");
	
	for(int i = 0; i < qtdComp; i++){
		if(vetComp[i].ativo == 1){
			printf("Codigo da compra: %d\n", vetComp[i].codigoCliente);
			printf("Data da Compra: %s\n", vetComp[i].dataCompra);
			printf("Forma de pagamento: %s\n", vetComp[i].formaPag);
			printf("Valor: %2.f\n", vetComp[i].valorTotal);

		}
	}
}


void statusCliente(Clientes *vetC, int qtdC){ //Função pra desativar cliente
	if(qtdC == 0)
		printf("Nenhum cliente cadastrado!\n\n");
		
	int codBusca;
	printf("Digite o codigo do cliente que deseja buscar: \n");
	scanf("%d", &codBusca);
	
	int encontrado = 0;
	for(int i = 0; i < qtdC; i++){
		if(vetC[i].codigo == codBusca){
			encontrado = 1;
			
			printf("Cliente encontrado: %s \n", vetC[i].nome);
			printf("Status do cliente: %s\n", vetC[i].ativo == 1? "Ativo" : "Inativo");
			
			int opcaoAtivo;
			printf("-----O QUE DESEJA FAZER: -----	\n\n");
			printf("ATIVAR CLIENTE (1)\n");
			printf("DESATIVAR CLIENTE (2)\n");
			printf("CANCELAR (3)\n");
			scanf("%d", &opcaoAtivo);
			
			if(opcaoAtivo == 1){
				vetC[i].ativo = 1;
				printf("Cliente ativado!\n\n");
			}
			if(opcaoAtivo == 2){
				vetC[i].ativo = 0;
				printf("Cliente desativado!\n\n");
			}
			if(opcaoAtivo == 3)
				printf("Operação cancelada!\n");
				
			break;
		}
	}
	if(!encontrado)
		printf("Cliente não encontrado!");
}

void statusCompras(Compras *vetComp, int qtdComp){
	if(qtdComp == 0){
		printf("Nenhum cliente cadastrado!\n\n");
		return;
	}
		
	int codBusca;
	printf("Digite o codigo da compra que deseja buscar: \n");
	scanf("%d", &codBusca);
	
	int encontrado = 0;
	for(int i = 0; i < qtdComp; i++){
		if(vetComp[i].codigoCliente == codBusca){
			encontrado = 1;
			
			printf("Compra encontrada\n\n!");
			printf("Status da compra: %s\n\n", vetComp[i].ativo == 1? "Ativo" : "Inativo");
			
			int opcaoAtivo;
			printf("-----O QUE DESEJA FAZER: -----	\n\n");
			printf("ATIVAR COMPRA (1)\n");
			printf("DESATIVAR COMPRA (2)\n");
			printf("CANCELAR (3)\n");
			scanf("%d", &opcaoAtivo);
			
			if(opcaoAtivo == 1){
				vetComp[i].ativo = 1;
				printf("Compra ativada!\n\n");
			}
			if(opcaoAtivo == 2){
				vetComp[i].ativo = 0;
				printf("Compra desativada!\n\n");
			}
			if(opcaoAtivo == 3)
				printf("Operação cancelada!\n");
				
			break;
		}
	}
	if(!encontrado)
		printf("Compra não encontrada!");
}
