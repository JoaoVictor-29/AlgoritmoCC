#include <stdio.h>

typedef struct{

    char nome[20];
    int idade;
    float nota;

}Aluno;

void lerDados(Aluno *vetAlunos, int tam);
void alunoAprovacao(Aluno *vetAlunos, int tam);
void ordenarAluno(Aluno *vetAlunos, int tam);

int main(){

    Aluno vetAlunos[3];
    lerDados(vetAlunos, 3);
    alunoAprovacao(vetAlunos, 3);
    ordenarAluno(vetAlunos, 3);

    for(int i = 0; i < 3; i++)
        printf("%s -> %d \n", vetAlunos[i].nome, vetAlunos[i].idade);

}

void lerDados(Aluno *vetAlunos, int tam){

    for(int i = 0; i < tam; i++){
        scanf("%s", vetAlunos[i].nome);
        scanf("%d", &vetAlunos[i].idade);
        scanf("%f", &vetAlunos[i].nota);
    }
}

void alunoAprovacao(Aluno *vetAlunos, int tam){

    int aprovado = 0;
    for(int i = 0; i < tam; i++){
        if(vetAlunos[i].nota >= 6){
            aprovado = 1;
            printf("aluno: %s --- APROVADO\n", vetAlunos[i].nome);
        }else{
            aprovado = 0;
            printf("aluno: %s --- REPROVADO\n", vetAlunos[i].nome);
        }
    }
}

void ordenarAluno(Aluno *vetAlunos, int tam){
    for(int i = 0; i < tam - 1; i++){
        for(int j = 0; j < tam - i - 1; j++){
            if(vetAlunos[j].idade > vetAlunos[j+1].idade){
                Aluno Aux;
                Aux = vetAlunos[j];
                vetAlunos[j] = vetAlunos[j+1];
                vetAlunos[j+1] = Aux;
            }
        }
    }
}
