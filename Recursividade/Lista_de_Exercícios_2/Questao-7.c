#include <stdio.h>

int contaPares(int *v, int tam);
int main(){
	
	int vet[] = {3, 6, 1, 8, 4};
	
	int resp = contaPares(vet, 4);
	printf("%d", resp);
	
}

int contaPares(int *v, int tam){
	if(tam == 0)
		return 0;
	else{
		int cont = (v[tam] % 2 == 0) ? 1 : 0;
		return cont + contaPares(v, tam - 1);
	}
}
