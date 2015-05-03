#include "stdio.h"

char toUpper(char c){
    if(c >= 'a' && c <= 'z'){
        return c-0x20;
    }else{
        return c;
    }
}

int main(){
    int k,i,c;
    char s[10001];

    scanf(" %s %d", s, &k);
    for(i = c = 0; s[i+1] != '\0'; i++){
        if(toUpper(s[i]) == 'C' && toUpper(s[i+1]) == 'C'){
            c++;
        }
    }
    if(c >= k){
        printf("#OCOMisfun");
        for(i = 0; i < c-k; i++){
            printf(" fun");
        }
    }else{
        printf("OCOM is not fun");
    }
}
