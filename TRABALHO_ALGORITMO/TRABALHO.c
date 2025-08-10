#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int codigo;
	char nome[50];
	char CPF[12];
	char telefone[12];
	char dataNasc[9];
	char endereco[50];
	int ativo;
}Clientes;

typedef struct{
	char dataCompra[9];
	float valorTotal;
	char formaPag[20];
	char quitada;
	int codigoCliente;
	int ativo;
}Compras;


Clientes * cadastrarClientes(Clientes *vetComp, int *qtdC);
void salvar_arquivoBin_cliente(Clientes *vet_Cliente,int quant_Cliente);
void salvar_arquivoBin_compra(Clientes *vet_Compra,int quant_Compra);

int main(){
	Clientes *vetCliente = NULL;
	Compras *vetCompra = NULL;
    FILE *pont_compra;
    FILE *pont_cliente;
	
	printf("O QUE DESEJA FAZER? \n\n");
	int n, qtdClientes = 0, qtdCompras = 0;
	
	do{
		printf("CADASTRAR CLIENTE (1)\n");
        printf("SALVAR ARQUIVO BINARIO (2)\n");
		printf("CADASTRAR COMPRAS (3)\n");
		printf("EXIBIR TODOS OS REGISTROS (4)\n");
		printf("ATUALIZAR DADOS DE CLIENTES (5)\n");
		printf("ATUALIZAR DADOS DE COMPRAS (6)\n");
		printf("ATIVAR OU DESATIVAR UM REGISTRO (7)\n");
		printf("DIGITE 0 PARA FINALIZAR\n");
		scanf("%d", &n);
		switch (n)
        {
        case 1:
           vetCliente = cadastrarClientes(vetCliente, &qtdClientes);
            break;
        case 2:
          void salvar_arquivoBin_cliente(Clientes *vet_Cliente,int quant_Cliente);
          void salvar_arquivoBin_compra(Clientes *vet_Compra,int quant_Compra);
           break;
        default:
            break;
        } 
	}while(n != 0);
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

			printf("Digite o CPF do cliente: ");
			fgets(vetC[i].CPF, 12, stdin);
			vetC[i].CPF[strcspn(vetC[i].CPF, "\n")] = '\0';

			for(int j = 0; j < i; j++){
				if(vetC[j].CPF == vetC[i].CPF){
					printf("CPF já existente!\n");
					codigoVal = 0;
					break;
				}
			}
		
		
		printf("Digite o telefone do cliente: ");
	      fgets(vetC[i].telefone, 12, stdin);
		vetC[i].telefone[strcspn(vetC[i].telefone, "\n")] = '\0';
		printf("Digite a data de nascimento do cliente: ");
		  fgets(vetC[i].dataNasc, 9, stdin);
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
    pont_arqBin = fopen("cliente.txt","wb");
      if(pont_arqBin){
          fprintf(pont_arqBin,"%d\n",quant_Cliente);
          fwrite(vet_Cliente,sizeof(Clientes),quant_Cliente,pont_arqBin);
          fclose(pont_arqBin);
      }
      else{
        printf("ERROOOO- MELHOR CONSERTAR");
      }
}
void salvar_arquivoBin_compra(Clientes *vet_Compra,int quant_Compra){
    FILE *pont_arqBin;
    pont_arqBin = fopen("compra.txt","wb");
      if(pont_arqBin){
          fprintf(pont_arqBin,"%d\n",quant_Compra);
          fwrite(vet_Compra,sizeof(Clientes),quant_Compra,pont_arqBin);
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
		scanf("%d", &vetComp[i].quitada);
		printf("Digite o valor total: ");
		scanf("%f", &vetComp[i].valorTotal);
		
		vetComp[i].ativo = 1;
	}
	*qtdComp = qtdNovoC;
	printf("\n\n");
	
	return vetComp;
}

// Implementação da função de importação de dados (módulo 2)
/*void importarDados(Clientes **vetCliente, int *qtdClientes, Compras **vetCompra, int *qtdCompras) {
    FILE *arqBinClientes, *arqBinCompras;
    FILE *arqTexto;
    char linha[256];
    char *token;

    //abrir o arquivo Externo.txt
    arqTexto = fopen("Externo.txt", "r");
    if (arqTexto == NULL) {
        printf("Erro ao abrir o arquivo Externo.txt\n");
        return;
    }

    arqBinClientes = fopen("clientes.bin", "ab");
    arqBinCompras = fopen("compras.bin", "ab");
    if (arqBinClientes == NULL || arqBinCompras == NULL) {
        printf("Erro ao abrir arquivos binários.\n");
        fclose(arqTexto);
        if (arqBinClientes) fclose(arqBinClientes);
        if (arqBinCompras) fclose(arqBinCompras);
        return;
    }

    *vetCliente = (Clientes *)realloc(*vetCliente, (*qtdClientes) * sizeof(Clientes));
    *vetCompra = (Compras *)realloc(*vetCompra, (*qtdCompras) * sizeof(Compras));

    while (fgets(linha, sizeof(linha), arqTexto) != NULL) {
        if (strstr(linha, "Data:") != NULL) {
            Compras novaCompra;
            Clientes novoCliente;
            
            memset(&novaCompra, 0, sizeof(Compras));
            memset(&novoCliente, 0, sizeof(Clientes));
            novaCompra.ativo = 1;
            novaCompra.quitada = 'n';
            novoCliente.ativo = 1;
            strcpy(novoCliente.CPF, "Nao Informado");
            strcpy(novoCliente.dataNasc, "Nao Informado");
            strcpy(novoCliente.endereco, "Nao Informado");

            token = strtok(linha, ":");
            token = strtok(NULL, "\n");
            strcpy(novaCompra.dataCompra, token + 1);

            fgets(linha, sizeof(linha), arqTexto);
            token = strtok(linha, ":");
            token = strtok(NULL, "\n");
            novaCompra.valorTotal = atof(token + 1);
            
            fgets(linha, sizeof(linha), arqTexto);
            token = strtok(linha, ":");
            token = strtok(NULL, "\n");
            strcpy(novaCompra.formaPag, token + 1);
            
            fgets(linha, sizeof(linha), arqTexto);
            token = strtok(linha, ":");
            token = strtok(NULL, "\n");
            novaCompra.codigoCliente = atoi(token + 1);
            novoCliente.codigo = novaCompra.codigoCliente;

            (*qtdCompras)++;
            *vetCompra = (Compras *)realloc(*vetCompra, (*qtdCompras) * sizeof(Compras));
            if (*vetCompra == NULL) {
                printf("Erro ao realocar memória para compras.\n");
                exit(1);
            }
            (*vetCompra)[*qtdCompras - 1] = novaCompra;

            fwrite(&novaCompra, sizeof(Compras), 1, arqBinCompras);

            if (!verificaClienteExistente(*vetCliente, *qtdClientes, novoCliente.codigo)) {
                while (fgets(linha, sizeof(linha), arqTexto) != NULL && strlen(linha) > 1 && strstr(linha, "Data:") == NULL) {
                    if (strstr(linha, "Nome:") != NULL) {
                        token = strtok(linha, ":");
                        token = strtok(NULL, "\n");
                        strcpy(novoCliente.nome, token + 1);
                    } else if (strstr(linha, "Rua:") != NULL) {
                        token = strtok(linha, ":");
                        token = strtok(NULL, "\n");
                        strcat(novoCliente.endereco, "Rua: ");
                        strcat(novoCliente.endereco, token + 1);
                    } else if (strstr(linha, "Número:") != NULL) {
                        token = strtok(linha, ":");
                        token = strtok(NULL, "\n");
                        strcat(novoCliente.endereco, ", Número: ");
                        strcat(novoCliente.endereco, token + 1);
                    } else if (strstr(linha, "Bairro:") != NULL) {
                        token = strtok(linha, ":");
                        token = strtok(NULL, "\n");
                        strcat(novoCliente.endereco, ", Bairro: ");
                        strcat(novoCliente.endereco, token + 1);
                    } else if (strstr(linha, "Telefone:") != NULL) {
                        token = strtok(linha, ":");
                        token = strtok(NULL, "\n");
                        strcpy(novoCliente.telefone, token + 1);
                    }
                }
                
                (*qtdClientes)++;
                *vetCliente = (Clientes *)realloc(*vetCliente, (*qtdClientes) * sizeof(Clientes));
                if (*vetCliente == NULL) {
                    printf("Erro ao realocar memória para clientes.\n");
                    exit(1);
                }
                (*vetCliente)[*qtdClientes - 1] = novoCliente;

                fwrite(&novoCliente, sizeof(Clientes), 1, arqBinClientes);
            }
            if (strstr(linha, "Data:") != NULL) {
                fseek(arqTexto, -strlen(linha), SEEK_CUR);
            }
        }
    }
    
    printf("Importação de dados do Externo.txt concluída com sucesso.\n");
    fclose(arqTexto);
    fclose(arqBinClientes);
    fclose(arqBinCompras);
}
//verificar se o cliente existe
int verificaClienteExistente(Clientes *vetCliente, int qtdClientes, int codigo) {
    for (int i = 0; i < qtdClientes; i++) {
        if (vetCliente[i].codigo == codigo) {
            return 1;
        }
    }
    return 0;
}

// Funções para exibir dados (teste)
void exibirClientes(Clientes *vetC, int qtdC) {
    printf("\n--- LISTA DE CLIENTES ---\n");
    if (qtdC == 0) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }
    for (int i = 0; i < qtdC; i++) {
        printf("Código: %d, Nome: %s, Ativo: %d\n", vetC[i].codigo, vetC[i].nome, vetC[i].ativo);
    }
}

void exibirCompras(Compras *vetComp, int qtdComp) {
    printf("\n--- LISTA DE COMPRAS ---\n");
    if (qtdComp == 0) {
        printf("Nenhuma compra cadastrada.\n");
        return;
    }
    for (int i = 0; i < qtdComp; i++) {
        printf("Código do Cliente: %d, Valor: %.2f, Data: %s, Ativo: %d\n", vetComp[i].codigoCliente, vetComp[i].valorTotal, vetComp[i].dataCompra, vetComp[i].ativo);
    }
}

// Funções para salvar e carregar dados em arquivos binários
void salvarDados(Clientes *vetC, int qtdC, Compras *vetComp, int qtdComp) {
    FILE *arqClientes = fopen("clientes.bin", "wb");
    FILE *arqCompras = fopen("compras.bin", "wb");

    if (arqClientes != NULL) {
        fwrite(vetC, sizeof(Clientes), qtdC, arqClientes);
        fclose(arqClientes);
    }
    if (arqCompras != NULL) {
        fwrite(vetComp, sizeof(Compras), qtdComp, arqCompras);
        fclose(arqCompras);
    }
}
//carregar dados
void carregarDados(Clientes **vetC, int *qtdC, Compras **vetComp, int *qtdComp) {
    FILE *arqClientes = fopen("clientes.bin", "rb");
    FILE *arqCompras = fopen("compras.bin", "rb");

    if (arqClientes != NULL) {
        fseek(arqClientes, 0, SEEK_END);
        long tamanho = ftell(arqClientes);
        rewind(arqClientes);

        *qtdC = tamanho / sizeof(Clientes);
        *vetC = (Clientes *)realloc(*vetC, (*qtdC) * sizeof(Clientes));
        if (*vetC == NULL) {
            printf("Erro ao carregar dados de clientes.\n");
            exit(1);
        }
        fread(*vetC, sizeof(Clientes), *qtdC, arqClientes);
        fclose(arqClientes);
    }
    
    if (arqCompras != NULL) {
        fseek(arqCompras, 0, SEEK_END);
        long tamanho = ftell(arqCompras);
        rewind(arqCompras);

        *qtdComp = tamanho / sizeof(Compras);
        *vetComp = (Compras *)realloc(*vetComp, (*qtdComp) * sizeof(Compras));
        if (*vetComp == NULL) {
            printf("Erro ao carregar dados de compras.\n");
            exit(1);
        }
        fread(*vetComp, sizeof(Compras), *qtdComp, arqCompras);
        fclose(arqCompras);
    }
}*/