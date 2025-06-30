#include <stdio.h>

int fatorial_duplo(int n);
int main()
{
    
    int result = fatorial_duplo(5);
    
    printf("%d", result);
    return 0;
}

int fatorial_duplo(int n){
    if(n == 1){
        return 1;
    }else{
        return n * fatorial_duplo(n - 2);
    }
}
