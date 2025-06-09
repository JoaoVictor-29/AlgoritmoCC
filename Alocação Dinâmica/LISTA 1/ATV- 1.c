#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, *vet;
    printf("Digite a quantidade do vetor: ");
    scanf("%d", &n);
    
    vet = (int *)malloc(n*sizeof(int));
    for(int i = 0; i < n; i++){
        vet[i] = i;
    }
    
    for(int i = 0; i < n; i++){
        printf("%d ", vet[i]);
    }
    
    return 0;
}
