#include <stdio.h>

typedef struct{
    char nome[50];
    int matricula;
    float nota[3];
}Aluno;

void dadosAluno(Aluno *v, int tam);

int main(){

    Aluno vet[5];
    dadosAluno(vet, 5);
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
