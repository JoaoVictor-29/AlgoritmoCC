#include <stdio.h>

int somaVetor(int *v, int j);
int main()
{
    
    int vet[] = {5, 4};
    
    int resp = somaVetor(vet, 1);
    
    printf("%d", resp);

    return 0;
}

int somaVetor(int *v, int j){
    if(j == 0){
        return v[0];
    }else{
        return v[j] + somaVetor(v, j - 1);
    }
}
