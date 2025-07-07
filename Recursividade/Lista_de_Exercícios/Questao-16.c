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
    if(v[0] > v[1]){
        return v[0];
    }else{
        if(v[j] > v[j-1])
            return maiorNum(v, j - 1);
    }
}
