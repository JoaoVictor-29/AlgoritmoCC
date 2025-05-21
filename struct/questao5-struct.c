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
        printf("Digite a nota da primeira prova: ");
        scanf("%f", &v[i].nota[0]);
        printf("Digite a nota da segunda prova: ");
        scanf("%f", &v[i].nota[1]);
        printf("Digite a nota da terceira prova: ");
        scanf("%f", &v[i].nota[3]);
    }

}
