#include <stdio.h>

void numInvertido(int n);
int main()
{
    int n = 123;
    numInvertido(123);
    return 0;
}

void numInvertido(int n){
    if(n == 0)
        return;
        
    int ultimo = n % 10;
    printf("%d", ultimo);
    
    numInvertido(n / 10);
}
