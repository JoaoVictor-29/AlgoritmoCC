#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char nome[20];
	char dataNascimento[10];
	char cpf[12];
	float rendaFamiliar;
}Aluno;

Aluno * manipulaArrayDinamico(int qtdAluno);
int main(){
	Aluno *v = manipulaArrayDinamico(3);
	
	for(int i = 0; i < 3; i++){
		printf("Nome: %s\n", v[i].nome);
		printf("data de nascimento: %s\n", v[i].dataNascimento);
		printf("cpf: %s\n", v[i].cpf);
		printf("renda familiar: %2.f\n", v[i].rendaFamiliar);
	}
}

Aluno * manipulaArrayDinamico(int qtdAluno){
	Aluno *vet;
	vet = (Aluno *)malloc(qtdAluno*sizeof(Aluno));
	for(int i = 0; i < qtdAluno; i++){
		printf("Digite o nome do aluno: ");
		scanf("%s", vet[i].nome);
		printf("Digite a data de nascimento: ");
		scanf("%s", vet[i].dataNascimento);
		printf("DIgite o CPF: ");
		scanf("%s", vet[i].cpf);
		printf("Digite a renda familiar: ");
		scanf("%f", &vet[i].rendaFamiliar);
	}
	return vet;
}
