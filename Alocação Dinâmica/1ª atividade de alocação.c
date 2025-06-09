
#include <stdio.h>

int main()
{
    
    return 0;
}

Aluno * retornarAluno(int n){
    Aluno *vet;
    vet = (iny *)malloc(n*sizeof(Aluno));
    for(int i = 0; i < n; i++){
        printf("Nome: ");
        scanf("%s", vet[i].nome);
        printf("Idade: ");
        scanf("%d", &vet[i].idade);
        printf("Nota: ");
        scanf("%f", &vet[i].nota);
}
