#include <stdio.h>

typedef struct{
	char nome[20];
	int idade;
}Aluno;

int maiorIdade(Aluno *v, int tam);
int main(){
	
	Aluno vet[3] = {{"Joao", 20}, {"Maria", 17}, {"Pedro", 19}};
	
	int resp = maiorIdade(vet, 3);
	
	printf("%d", resp);
	
	
}

int maiorIdade(Aluno *v, int tam){
	
	if(tam == 0)
		return 0;
	
	int cont = maiorIdade(v, tam - 1);
	
	if(v[tam - 1].idade > 18)
		return 1 + cont;
	else
		return cont;
}
