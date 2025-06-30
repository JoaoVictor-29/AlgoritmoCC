#include <stdio.h>

float serie(int n);
int main()
{
    
    float result = serie(4);
    
    printf("%.2f", result);
    return 0;
}

float serie(int n){
    if(n == 1){
        return 2;
    }else{
        return ((1 + (n*n)) / n) + serie(n - 1);
    }
}
