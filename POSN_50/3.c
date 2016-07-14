#include "stdio.h"

int strlen(char s[]){
    int i;
    for(i = 0; s[i] != '\0'; i++);
    return i;
}

int main(){
    char s[21];
    char out[21];
    int i,j,len,k;
    char ls = 0;
    gets(s);
    len = strlen(s);
    for(i = len-1,j = 0; i >= 0; i--){
        if(s[i] == ls){
            if(k){
                j--;
                k = 0;
            }
        }else{
            out[j] = s[i];
            k = 1;
            j++;
        }
        ls = s[i];
    }
    out[j] = '\0';

    puts(out);
}
