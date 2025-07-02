#include <stdio.h>

float serie2(int n);
int main()
{
    
    int n = 5;
    float result = serie2(5);
    
    printf("%.1f ", result);
        
    return 0;
}

float serie2(int n){
    if(n == 0)
        return 0;
        
    return (float)((n*n) + 1) / (n + 3) + serie2(n - 1);
}
