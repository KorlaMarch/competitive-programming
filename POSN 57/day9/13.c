#include "stdio.h"

int strlen(char s[]){
    int i;
    for(i = 0; s[i] != '\0'; i++);
    return i;
}

int main(){
    char s[32];
    int i;
    gets(s);
    for(i = strlen(s)-1; i >= 0; i--){
        printf("%c", s[i]);
    }
}
