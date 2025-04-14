#include <stdio.h>

int trocaValores(int *num1, int *num2);
int main(){

    int num1 = 1, num2 = 2, troca;

    troca = trocaValores(&num1, &num2);

    printf("num1 = %d    num2 = %d", num1, num2 );

    return 0;
}

int trocaValores (int *num1, int *num2 ){

    int aux = *num1;
    *num1 = *num2;
    *num2 = aux;

    return num1;
}
