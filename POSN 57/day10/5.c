#include "stdio.h"

void copy(char source[],char dest[]){
    int i;
    for(i = 0; source[i] != '\0'; i++){
        dest[i] = source[i];
    }
    dest[i] = '\0';
}

int main(){
    char a[32],b[32];
    gets(a);
    copy(a,b);
    printf("After copy: %s\n", b);
}
