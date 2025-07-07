//NUMERO PAR CRESCENTE
#include <stdio.h>

void numPar(int n);
int main()
{
    int resp;
    numPar(10);

    return 0;
}

void numPar(int n){
    if(n == 0){
        printf("0 ");
    }else{
        numPar(n - 2);
        printf("%d ", n);
    }
}
