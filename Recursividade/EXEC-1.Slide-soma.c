#include <stdio.h>

int soma(int n);
int main()
{
    
    int f = soma(5);
    
    printf("%d", f);

    return 0;
}

int soma(int n){
    if(n == 0){
        return 0;
    }else{
        return n + soma(n - 1);
    }
}
