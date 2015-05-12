#include "stdio.h"
char charCode(char c){
    return c>='a'?c-'a':c-'A';
}
char s[1000002],m[1000002],key[1000002];
int i,j;
int main(){
    scanf(" %s %s",s,m);
    for(i=0; s[i]; i++){
        j = (charCode(s[i])+26-charCode(m[i]))%26+'0';
        if(j>'9') break;
        key[i] = j;
    }
    key[i] = '\0';
    if(s[i]) printf("R.I.P.\n");
    else printf("%s\n",key);
}
