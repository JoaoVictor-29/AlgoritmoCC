#include <stdio.h>

int multiplicacao(int n1, int n2);
int main()
{
    
    int result = multiplicacao(3, 4);
    
    printf("%d", result);
    return 0;
}

int multiplicacao(int n1, int n2){
    if(n2 == 0){
        return 0;
    }else{
        return n1 + multiplicacao(n1, n2 - 1);
    }
}
