#include <stdio.h>

float fatorial(int n);
float calcularSerie(int n);
int main()
{
    //float vet[] = {3, 2, 1, 4};
    
    fatorial(4);
    float resp = calcularSerie(4);
    printf("%.2f", resp);
    return 0;
}

float fatorial(int n){
    if(n == 0)
        return 1;
    else
        return (float)n * fatorial(n - 1);
}

float calcularSerie(int n){
    if(n == 1){
        return 1;
    }else{
        return ((float)(n * n) / fatorial(n)) + calcularSerie(n - 1); 
    }
}
