#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char nome[20];
	int idade;
	float salarioBase;
	float totalVendido;
}Vendedor;

Vendedor * cadastrarVend(Vendedor *v, int *qtdV);
void mostrarVend(Vendedor *v, int *qtdV);

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
		}
	}while(n != 0);
	
	free(vet);
}

Vendedor * cadastrarVend(Vendedor *v, int *qtdV){
	
	printf("Quantos vendedores deseja cadastrar? ");
	scanf("%d", qtdV);
	
	v = (Vendedor *)malloc(*qtdV*sizeof(Vendedor));
	
	for(int i = 0; i < *qtdV; i++){
		printf("Diigite o nome: ");
		scanf("%s", v[i].nome);
		printf("Digite a idade: ");
		scanf("%d", &v[i].idade);
		printf("Digite o salário Base: ");
		scanf("%f", &v[i].salarioBase);
		printf("Digite o valor total de vendas: ");
		scanf("%f", &v[i].totalVendido);
	}
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
