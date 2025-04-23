#include <stdio.h>

void questao6(int n, int *qtdPar, int *qtdImpar, int *qtdM35){
    int valor;
    *qtdPar = 0;
    *qtdImpar = 0;
    *qtdM35 = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &valor);
        if(valor % 2 == 0)
            (*qtdPar)++;
        else
            (*qtdImpar)++;
        if((valor % 3 ==0) && (valor % 5 == 0))
            (*qtdM35)++;
    }

}

int main(){

    int a , b, c;
    questao6(5, &a, &b, &c);
    printf("\n %d  %d  %d", a, b, c);

}
