#include <stdio.h>
#include <stdlib.h>

float * vetPG(int N, float R, float a1);
int main(){
	
	float *vet = vetPG(10, 2, 2);
	
	for(int i = 0; i < 10; i++)
		printf("%.2f ", vet[i]);
	
}

float * vetPG(int N, float R, float a1){
	
	float *vetor;
	
	vetor = (float *)malloc(N * sizeof(float));
	
	vetor[0] = a1;
	
	for(int i = 1; i < N; i++){
		vetor[i] = vetor[i-1] * R;
	}
	return vetor;
}
