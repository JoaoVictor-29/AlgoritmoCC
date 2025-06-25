#include <stdio.h>

float potencia(int x, int n);
int main()
{
    
    float pot = potencia(5, 3);
    
    printf("%.1f", pot);

    return 0;
}

float potencia(int x, int n){
    if(n == 0){
        return 1;
    }else{
        return x * potencia(x , n - 1);
    }
}
