#include <stdio.h>

float areaQuadrado(float *area, float *perimetro, float lado);
int main(){
	
	float lado = 5, area, perimetro;
	
	area = areaQuadrado(&area, &perimetro, lado);
	
	printf("Area do Quadrado: %.2f        Perimetro do Quadrado: %.2f", area, perimetro);
	
	return 0;
}

float areaQuadrado(float *area, float *perimetro, float lado){
	
	*area = lado * lado;
	*perimetro = 4 * lado;
	
	return *area;
}
