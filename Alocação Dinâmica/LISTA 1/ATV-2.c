#include <stdio.h>
#include <stdlib.h>

float *notaAluno(int n);
void *informaçãoAluno(int n, float *v);
int main()
{
    int n;
    float *v;
    printf("Quantas notas quer inserir: ");
    scanf("%d", &n);
    v = notaAluno(n);
    informaçãoAluno(n, v);
    
    for(int i = 0; i < n; i++){
        printf("%.2f ", v[i]);
    }
    
    return 0;
}

float *notaAluno(int n){
    float *vet;
    vet = (float *)malloc(n*sizeof(float));
    for(int i = 0; i < n; i++){
        printf("Digite a nota: ");
        scanf("%f", &vet[i]);
    }
    return vet;
}

void *informaçãoAluno(int n, float *vet){
    float maior, media;
    for(int i = 0; i < n; i++){
        if(vet[i] > maior)
            maior = vet[i];
    }
    printf("Maior: %.2f ", maior);
}
