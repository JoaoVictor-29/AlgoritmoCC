#include <stdio.h>

float funQ1(float *v, int tam);
int main()
{
    float vet[] = {3, 2, 1, 4};
    
    float resp = funQ1(vet, 3);
    printf("%.2f", resp);
    return 0;
}

float funQ1(float *v, int tam){
    if(tam == 0)
        return v[0];
    else
        return v[tam] * funQ1(v, tam - 1);
}
