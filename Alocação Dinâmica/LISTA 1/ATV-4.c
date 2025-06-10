#include <stdio.h>
#include <stdlib.h>

int * funQ4(int n, int *vet);
int main(){
	int vet[] = {5, 3, 2, 9, 15};
	int *v = funQ4(5, vet);
	
	int cont = v[0];
	for(int i = 1; i <= cont; i++){
		printf("%d ", v[i]);
	}
}

int * funQ4(int n, int *vet){
	int *vetR, cont = 0;
	
	for(int i = 0; i < n; i++){
		if(vet[i] % 3 == 0 && vet[i] % 5 == 0)
			cont++;
	}
	
	vetR = (int *)malloc((cont+1)*sizeof(int));
	
	vetR[0] = cont;
	int pos = 1;
	for(int i = 0; i < n; i++){
		if(vet[i] % 3 == 0 && vet[i] % 5 == 0){
			vetR[pos] = vet[i];
			pos++;
		}
	}
	return vetR;
}
