#include <stdio.h>

int menorNum(int *v, int j);
int main()
{
    int vet[5], resp;
    
    for(int i = 0; i < 5; i++){
        printf("Digite um numero: ");
        scanf("%d", &vet[i]);
    }
    
    resp = menorNum(vet, 4);
    printf("%d", resp);
    return 0;
}

int menorNum(int *v, int j){
    if(j == 0)
        return v[0];
        
    int menor = menorNum(v, j - 1);
    return (menor < v[j]) ? menor : v[j];
}
