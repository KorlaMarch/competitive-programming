#include "stdio.h"

int main(){
    int i;
    char s[32];
    gets(s);

    putchar(s[0]);
    for(i = 1; s[i] != '\0'; i++){
        if(s[i-1] == s[i]){
            putchar('x');
        }
        putchar(s[i]);
    }
}
