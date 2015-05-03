#include "stdio.h"

int main(){
    char s[256];
    int key,i;
    gets(s);
    scanf("%d", &key);
    for(i = 0; s[i] != '\0'; i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            putchar((s[i]-'A'+key)%26+'A');
        }else if(s[i] >= 'a' && s[i] <= 'z'){
            putchar((s[i]-'a'+key)%26+'a');
        }else{
            putchar(s[i]);
        }
    }
}
