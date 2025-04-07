/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    int vet[10] = {2,4,6,9,1,3,6,7,1,8}, num;

    printf("Digite um numero: ");
    scanf(" %d", &num);

    for(int i = 0; i < 10; i++){
        if(num == vet[i])
            printf("o numero esta no vetor!");
    }

    return 0;
}