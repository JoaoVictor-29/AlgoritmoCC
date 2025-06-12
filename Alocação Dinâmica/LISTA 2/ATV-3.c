#include <stdio.h>
#include <stdlib.h>

int * intersecao(int *v1, int n1, int *v2, int n2, int *tam);
int main(){
	
	int v1[] = {11, 10, 45, 7, 4}, v2[] = {24, 4, 16, 81, 10, 12}, tam;
	 
	 int *v = intersecao(v1, 5, v2, 6, &tam);
	 
	 for(int i = 0; i < tam; i++)
		printf("%d " , v[i]);
}

int * intersecao(int *v1, int n1, int *v2, int n2, int *tam){
	int *v3;
	int cont = 0;
	
	v3 = (int *)malloc(2*sizeof(int));
	for(int i = 0; i < n1; i++){
		for(int j = 0; j < n2; j++){
			if(v1[i] == v2[j])
				cont++;
		}
	}
	
	int k = 0;
	for(int i = 0; i < n1; i++){
		for(int j = 0; j < n2; j++){
			if(v1[i] == v2[j]){
				v3[k] = v1[i];
				k++;
			}
		}
	}
	*tam = cont;
	return v3;
}
