#include <stdio.h>

int fibonacci(int n);
int main()
{
    
    int n = 10;
    fibonacci(10);
    
    for(int i = 1; i <= n; i++)
        printf("%d ", fibonacci(i));
        
    return 0;
}

int fibonacci(int n){
    int x;
    if(n == 1){
        return 1;
    }
    if(n == 2){
        return 1;
    }
    return fibonacci(n - 2) + fibonacci(n - 1);
}
