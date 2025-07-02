#include <stdio.h>

int tribonacci(int n);
int main()
{
    
    int n = 7;
    tribonacci(7);
    
    printf("0 ");
    for(int i = 1; i <= n; i++)
        printf("%d ", tribonacci(i));
        
    return 0;
}

int tribonacci(int n){
    if(n == 0)
        return 0;
    
    if(n == 1)
        return 0;
    
    if(n == 2)
        return 1;
    return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
}
