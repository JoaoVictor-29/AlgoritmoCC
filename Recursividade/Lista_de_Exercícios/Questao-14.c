//NUMERO PAR DECRESCENTE
#include <stdio.h>

void numPar(int n);
int main()
{
    int resp;
    numPar(7);

    return 0;
}

void numPar(int n){
    if(n == 0){
        printf("0");
    }else{
        if(n % 2 == 0)
            printf("%d ", n);
        numPar(n - 1);
    }
}
