#include <stdio.h>

int maiorNum(int *v, int j);
int main()
{
    int vet[5], resp;
    
    for(int i = 0; i < 5; i++){
        printf("Digite um numero: ");
        scanf("%d", &vet[i]);
    }
    
    resp = maiorNum(vet, 4);
    printf("%d", resp);
    return 0;
}

int maiorNum(int *v, int j){
    if(j == 0)
        return v[0];
        
    int maior = maiorNum(v, j - 1);
    return (maior > v[j]) ? maior : v[j];
}
