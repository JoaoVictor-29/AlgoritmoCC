#include <stdio.h>

void vetorOrdenado(int *v, int tam);
int buscaBinaria(int *v, int n, int tam);

int main(){
	
	int vet[5] = {5, 2, 8, 0, 3};
	
	vetorOrdenado(vet, 5);
	
	int encontrado = buscaBinaria(vet, 7, 5);
	if(encontrado != -1)
		printf("%d ", encontrado);
	else
		printf("-1");
	
}

void vetorOrdenado(int *v, int tam){
	
	int aux = 0;
	for(int i = 0; i < tam - 1; i++){
		for(int j = 0; j < tam - i - 1; j++){
			if(v[j] > v[j+1]){
				aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
			}
		}
	}
	
}

int buscaBinaria(int *v, int n, int tam){
	
	int meio, inicio = 0, fim = tam - 1;
	
	while(inicio <= fim){
		meio = (inicio + fim) / 2;
		
		if(v[meio] == n)
			return meio;
		else if(v[meio] < n)
			inicio = meio + 1;
		else
			fim = meio - 1;
		
	}
	return -1;
}
