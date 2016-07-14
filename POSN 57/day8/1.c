#include "stdio.h"

int mutiString(char* s){
    int n = 0;
    while(*s != '\0'){
         n *= 10;
         n += *s-'0';
         s++;
    }
    return n*2;
}

int main(){
    char s[64];
    gets(s);

    printf("%d\n", mutiString(s));
}
