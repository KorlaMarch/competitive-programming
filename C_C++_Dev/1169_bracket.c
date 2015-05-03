#include "stdio.h"

int main(){
    char s[201];
    int i,wc = 0,b = 0;
    scanf(" %s", s);
    for(i = 0; s[i] != '\0'; i++){
        if(s[i] == '('){
            b++;
        }else{
            b--;
        }
        if(b < 0){
            wc++;
            b = 0;
        }
    }
    printf("%d\n", wc+b);
}
