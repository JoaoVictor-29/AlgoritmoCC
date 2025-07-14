#include <stdio.h>

int fatorial(int n);
int calcularSerie(int n);
int main()
{
    //float vet[] = {3, 2, 1, 4};
    
    fatorial(4);
    int resp = calcularSerie(4);
    printf("%d", resp);
    return 0;
}

int fatorial(int n){
    if(n == 0)
        return 1;
    else
        return n * fatorial(n - 1);
}

int calcularSerie(int n){
    if(n == 1){
        return 1;
    }else{
        return calcularSerie(n * n) / fatorial(n - 1); 
    }
}
