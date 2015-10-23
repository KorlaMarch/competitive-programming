#include "stdio.h"

int main(){
    char s[25];
    int i;
    scanf(" %s",s);
    for(i = 0; s[i]; i++){
        if(i%2==0){
            putchar((s[i]-'0'+9)%10+'0');
        }else{
            putchar((s[i]-'0'+1)%10+'0');
        }
    }
    return 0;
}
