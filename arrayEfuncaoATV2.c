#include <stdio.h>

void imparPar(int *vet1, int *vetImpar, int *vetPar, int *contI, int *contP);
int main(){

    int vet1[5] = {2,3,1,6,5}, vetImpar[5], vetPar[5];
    int contI, contP;
    imparPar(vet1, vetImpar, vetPar, &contI, &contP);

    printf("Vetor Par: \n");
    for(int i = 0; i < contP; i++)
        printf(" %d", vetPar[i]);

    printf("\n");

    printf("Vetor Impar: \n");
    for(int i = 0; i < contI; i++)
        printf(" %d", vetImpar[i]);

}

void imparPar(int *vet1, int *vetImpar, int *vetPar, int *contI, int *contP){

    *contI = 0;
    *contP = 0;
    for(int i = 0; i < 5; i++){
        if(vet1[i] % 2 == 0){
            vetPar[*contP] = vet1[i];
            (*contP)++;
        }else{
            vetImpar[*contI] = vet1[i];
            (*contI)++;
        }
    }

}
