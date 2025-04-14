#include <stdio.h>

void converteSegundos(int *hora, int *min, int *seg, int totalSegundo);
int hora, min, seg, totalSegundo = 3789;

int main(){
	
	converteSegundos(&hora, &min, &seg, totalSegundo);
	printf("hora: %d\n", hora);
	printf("min: %d\n", min);
	printf("seg: %d", seg);
	
	
}

void converteSegundos(int *hora, int *min, int *seg, int totalSegundo){
	
	*hora = totalSegundo / 3600;
	*min = (totalSegundo % 3600) / 60;
	*seg = totalSegundo % 60;
	
}
