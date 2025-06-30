#include <stdio.h>

int potencia(int i, int j);
int main()
{
    
    int result = potencia(2, 3);
    
    printf("%d", result);
    return 0;
}

int potencia(int i, int j){
    if(j == 0){
        return 1;
    }else{
        return i * potencia(i, j - 1);
    }
}
