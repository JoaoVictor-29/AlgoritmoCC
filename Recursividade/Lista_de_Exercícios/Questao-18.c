#include <stdio.h>

int numRept(int n);
int main(){
	
	int resp = numRept(762021192);
	printf("%d", resp);
	
}

int numRept(int n){
	if(n == 0){
		return 0;
	}
	
	int ult = n % 10;
	int cont = (ult == 2) ? 1 : 0;
	
	return cont + numRept(n/10);
		
}
