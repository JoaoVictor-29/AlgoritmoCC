#include <stdio.h>

int fatorial(int n);
int main()
{
    
    int f = fatorial(5);
    
    printf("%d", f);

    return 0;
}

int fatorial(int n){
    if(n == 0){
        return 1;
    }else{
        return n * fatorial(n - 1);
    }
}
