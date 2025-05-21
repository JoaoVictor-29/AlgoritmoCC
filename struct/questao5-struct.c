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

void encontrar(Aluno *v, int *indice){
    //maior nota da primeira
    indice[0] = 0;
    //maior media
    indice[1] = 0;
    //menor media
    indice[2] = 0;
    for(int i = 1; i < 5; i ++){
        //verificar maior nota da primeira prova
        if(v[i].nota[0] > v[indice[0].notas[0])
            indice[0] = i;
        //verificar maior media
        if((v[indice[1].nota[0] + v[indice[1].nota[1] + v[indice[1].nota[2]) / 3 < (v[indice[1].nota[0] + v[indice[1].nota[1] + v[indice[1].nota[2]) / 3)
            indice[1] = i;
        if((v[indice[1].nota[0] + v[indice[1].nota[1] + v[indice[1].nota[2]) / 3 < (v[indice[1].nota[0] + v[indice[1].nota[1] + v[indice[1].nota[2]) / 3)
            indice[2] = i;
    }
}
