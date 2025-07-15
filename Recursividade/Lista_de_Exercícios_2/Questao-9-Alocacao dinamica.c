#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char descricao[40];
	float preco;
	int quantidadeEstoque;
}Produto;

Produto * alocamais6(Produto *produto, int tamanho, int *tamNovo);
int main(){
	int tamanho = 10, tamNovo;
	Produto *produtos;
	produtos = (Produto *) malloc(tamanho*sizeof(Produto));
	for (int i = 0; i < tamanho; i++) {
		printf("Descrição do produto %d: ", i + 1);
		scanf("\n%[^\n]", produtos[i].descricao);
		printf("Preço do produto %d: ", i + 1);
		scanf("%f", &produtos[i].preco);
		printf("Quantidade em estoque %d: ", i + 1);
		scanf("%d", &produtos[i].quantidadeEstoque);
	}
		
	produtos = alocamais6(produtos, tamanho, &tamNovo);
		
	free(produtos);
	return 0;

}

Produto * alocamais6(Produto *produto, int tamanho, int *tamNovo){
	
	Produto *prod2;
	
	*tamNovo = tamanho + 6;
	
	prod2 = (Produto *)realloc(produto, *tamNovo * sizeof(Produto));
	
		for (int i = tamanho; i < *tamNovo; i++) {
		printf("Descrição do produto %d: ", i + 1);
		scanf("\n%[^\n]", prod2[i].descricao);
		printf("Preço do produto %d: ", i + 1);
		scanf("%f", &prod2[i].preco);
		printf("Quantidade em estoque %d: ", i + 1);
		scanf("%d", &prod2[i].quantidadeEstoque);
	}
	return prod2;
}
