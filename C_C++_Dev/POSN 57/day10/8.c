#include "stdio.h"

int main(){
    char s[32];
    int sum,i;
    gets(s);
    for(i = sum = 0; s[i] != '\0'; i++){
        sum += s[i];
    }
    sum %= 100;
    printf("check sum = %d\n", sum);
}
