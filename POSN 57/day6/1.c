#include "stdio.h"

int main(){
    int n,i;
    char c;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        c = i%26+'A';
        putchar(c);
        if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') putchar('\n');
    }
}
