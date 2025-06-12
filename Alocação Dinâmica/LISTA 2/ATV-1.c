#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char nome[20];
	int idade;
	float salarioBase;
	float totalVendido;
	float comissao;
}Vendedor;

Vendedor * cadastrarVend(Vendedor *v, int *qtdV);
void mostrarVend(Vendedor *v, int *qtdV);
void comissaoVend(Vendedor *v, int *qtdV);


int main(){
	Vendedor *vet = NULL;
	
	printf("O que deseja fazer? \n");
	int n, qtdV = 0;
	do{
		printf("Cadastrar vendedores (1)\n");
		printf("Mostrar os dados de todos os vendedores cadastrados (2)\n");
		printf("Calcular comissões (3)\n");
		printf("Saio do programa (0)\n\n");
		scanf("%d", &n);
		if(n == 1){
			vet = cadastrarVend(vet, &qtdV);	
		}else if(n == 2){
			mostrarVend(vet, &qtdV);
		}else if(n == 3){
			comissaoVend(vet, &qtdV);
		}
	}while(n != 0);
	
	free(vet);
}

Vendedor * cadastrarVend(Vendedor *v, int *qtdV){
	
	int vendN;
	printf("Quantos vendedores deseja cadastrar? ");
	scanf("%d", &vendN);
	
	int qtdVN = *qtdV + vendN;
	
	v = (Vendedor *)realloc(v, qtdVN*sizeof(Vendedor));
	
	for(int i = *qtdV; i < qtdVN; i++){
		printf("Diigite o nome: ");
		scanf("%s", v[i].nome);
		printf("Digite a idade: ");
		scanf("%d", &v[i].idade);
		printf("Digite o salário Base: ");
		scanf("%f", &v[i].salarioBase);
		printf("Digite o valor total de vendas: ");
		scanf("%f", &v[i].totalVendido);
	}
	*qtdV = qtdVN;
	
	printf("\n\n");
	
	return v;
}

void mostrarVend(Vendedor *v, int *qtdV){
	for(int i = 0; i < *qtdV; i++){
		printf("Nome: %s\n", v[i].nome);
		printf("Idade: %d\n", v[i].idade);
		printf("Salario Base: %.2f\n", v[i].salarioBase);
		printf("Valor total de vendas: %.2f\n\n", v[i].totalVendido);
	}
}

void comissaoVend(Vendedor *v, int *qtdV){
	if(*qtdV > 0){
		for(int i = 0; i < *qtdV; i++){
			v[i].comissao = v[i].totalVendido * 0.03;
			printf("Comissão para %s: %2.f\n", v[i].nome, v[i].comissao);
		}
	}
}
