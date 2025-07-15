#include <stdio.h>

int contaUm(int n);
int main(){
	
	int resp = contaUm(5);
	
	printf("%d", resp);
	
}

int contaUm(int n){
	if(n / 2 == 1)
		return 1;
	else{
		int resto = n % 2;
		int cont = (resto == 1) ? 1 : 0;
		
		return cont + contaUm(n / 2);
	}
}
