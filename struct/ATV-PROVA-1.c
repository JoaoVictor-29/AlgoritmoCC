#include <stdio.h>

typedef struct{
    char nome[50];
    int idade;
    char endereco[100];
}Dados;

int main(){

    Dados vet;
    printf("Nome: ");
    scanf("%s", vet.nome);
    printf("Idade: ");
    scanf("%d", &vet.idade);
    printf("Endereço: ");
    scanf("%s", vet.endereco);
}
