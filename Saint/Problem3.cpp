#include "stdio.h"
#include "string.h"

char s[100];
int n;

int abs(int n){
    return n<0?-n:n;
}

int main(){
    printf("Enter string? ");
    scanf(" %s", s);
    n = strlen(s);

    for(int i = 0; i < n*2-1; i++){
        //prefix
        for(int j = 0; j < n-abs(n-1-i)-1; j++){
            putchar(s[j]);
        }
        //middle
        for(int j = 0; j < n*2-1-2*(n-abs(n-1-i)-1); j++){
            putchar(s[n-abs(n-1-i)-1]);
        }
        //postfix
        for(int j = n-abs(n-1-i)-2; j >= 0; j--){
            putchar(s[j]);
        }
        putchar('\n');
    }
}
