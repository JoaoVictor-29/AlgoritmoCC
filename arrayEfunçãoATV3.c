#include <stdio.h>

int returnValor(int *vet, int *val);
int main(){
	
	int vet[5] = {2,3,1,4,8}, val;
	
	val = returnValor(vet, &val);
	
	printf("Posição que o numero está inserida: %d", val);
	
}

int returnValor(int *vet, int *val){
	
	*val = -1;
	int n = 8;
	for(int i = 0; i < 5; i++){
		if(vet[i] == n){
			*val = i;
		}
	}
	
	return *val;
}
