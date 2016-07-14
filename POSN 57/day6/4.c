#include "stdio.h"

int len(char s[]){
    int i;
    for(i = 0; s[i] != '\0'; i++);
    return i;
}
int main(){
    char s[256];
    char key[16];
    char c;
    int i,j,ls,lk;
    gets(s);
    gets(key);
    ls = len(s);
    lk = len(key);
    for(i = 0; i <= ls-lk; i++){
        for(j = 0; j < lk; j++){
            c = s[i+j];
            if(c >= 'A' && c <= 'Z'){
                c = (c-'A'+key[j]-'0')%26+'A';
            }else if(c >= 'a' && c <= 'z'){
                c = (c-'a'+key[j]-'0')%26+'a';
            }
            s[i+j] = c;
        }

    }
    printf("%s\n", s);
}
