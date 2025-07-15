#include <stdio.h>

int buscaBin(int *v, int inicio, int fim, int n);
int main(){
	int vet[] = {3, 4, 6, 8, 9}, tam = 5;
	
	int resp = buscaBin(vet, 0, tam - 1, 8);
	
	printf("%d", resp);
}

int buscaBin(int *v, int inicio, int fim, int n){
	
	if(inicio <= fim){
		int meio = inicio + (fim - inicio) / 2;
		if(v[meio] == n){
			return meio;
		}
		if(v[meio] > n){
			return buscaBin(v, inicio, meio - 1, n);
		}else{
			return buscaBin(v, meio + 1, fim, n);
		}
	}
	return -1;
}
