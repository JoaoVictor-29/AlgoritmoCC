#include <stdio.h>

float mediaVetor(int *v, int j);
int main(){
	
	int vet[4];
	
	for(int i = 0; i < 4; i++){
		printf("Digite um número: ");
		scanf("%d", &vet[i]);
	}
	
	float resp = mediaVetor(vet, 3);
	
	printf("%.2f", resp);
	
}

float mediaVetor(int *v, int j){
	if(j == 0)
		return v[0];
	
	return (v[j] + mediaVetor(v, j - 1) * j) / (j + 1);
}
