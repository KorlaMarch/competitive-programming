#include "stdio.h"
#include "string.h"

char toU(char c){
    if(c>='a'&&c<='z') return c-0x20;
    else return c;
}

int main(){
    char s[1001];
    int i=0,w=0;
    scanf(" %s", s);
    if(strlen(s)>=4) for(i = 0; s[i+3]; i++){
        if(toU(s[i])=='S'&&toU(s[i+1])=='I'&&toU(s[i+2])=='P'&&toU(s[i+3])=='A'){
            putchar('\"');
            putchar(s[i]);
            putchar(s[i+1]);
            putchar(s[i+2]);
            putchar(s[i+3]);
            putchar('\"');
            i += 3;
            w++;
        }else putchar(s[i]);
    }
    for(; s[i]; i++) putchar(s[i]);
    printf("\n%d\n",w);
}
