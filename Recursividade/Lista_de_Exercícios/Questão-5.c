#include <stdio.h>

void inverta(char *s);
int main()
{
    
    //char result = inverta(5);
    char s[8] = {'K', 'A', 'Y', 'L', 'A', 'N', 'E', '\0'};
    inverta(s);
    
    //printf("%s", result);
    return 0;
}

void inverta(char *s){
    if(*s == '\0'){
        return;
    }else{
        inverta(s + 1);
        printf("%c", *s);
    }
}
