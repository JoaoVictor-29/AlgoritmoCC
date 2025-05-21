#include <stdio.h>

typedef struct{
    char nome[50];
    int matricula;
    float nota[3];
}Aluno;

void dadosAluno(Aluno *v, int tam);
void encontrar(Aluno *v, int *indice);
void statusAluno(Aluno *v);

int main(){

    Aluno vet[5];
    int ind[3];
    dadosAluno(vet, 3);
    encontrar(vet, ind);
    
    for(int i = 0; i < 3; i++)
		printf("NOME: %s \nMATRICULA: %d\nNOTAS: %.2f %.2f %.2f\n\n", vet[i].nome, vet[i].matricula, vet[i].nota[0], vet[i].nota[1], vet[i].nota[2]);
		
	printf("MAIOR NOTA 1 PROVA: %s \nMAIOR MEDIA: %s\nMENOR MEDIA: %s\n", vet[ind[0]].nome, vet[ind[1]].nome, vet[ind[2]].nome);
		
	statusAluno(vet);
}

void dadosAluno(Aluno *v, int tam){

    for(int i = 0; i < tam; i++){
        printf("Digite o nome do aluno: ");
        scanf("%s", v[i].nome);
        printf("Digite o número de matricula: ");
        scanf("%d", &v[i].matricula);
        printf("Digite as notas: ");
        scanf("%f %f %f", &v[i].nota[0], &v[i].nota[1], &v[i].nota[2]);
    }
}

void encontrar(Aluno *v, int *indice){
    //maior nota da primeira
    indice[0] = 0;
    //maior media
    indice[1] = 0;
    //menor media
    indice[2] = 0;
    for(int i = 1; i < 3; i ++){
        //verificar maior nota da primeira prova
        if(v[i].nota[0] > v[indice[0]].nota[0])
            indice[0] = i;
        //verificar maior media
        if((v[indice[1]].nota[0] + v[indice[1]].nota[1] + v[indice[1]].nota[2]) / 3 < (v[indice[1]].nota[0] + v[indice[1]].nota[1] + v[indice[1]].nota[2]) / 3)
            indice[1] = i;
        if((v[indice[1]].nota[0] + v[indice[1]].nota[1] + v[indice[1]].nota[2]) / 3 > (v[indice[1]].nota[0] + v[indice[1]].nota[1] + v[indice[1]].nota[2]) / 3)
            indice[2] = i;
    }
}

void statusAluno(Aluno *v){
	for(int i = 0; i < 3; i++){
		if((v[i].nota[0] + v[i].nota[1] + v[i].nota[2]) / 3 > 6.0)
			printf("%s ---> APROVADO!\n", v[i].nome);
		else
			printf("%s ---> APROVADO!\n", v[i].nome);
	}
}
