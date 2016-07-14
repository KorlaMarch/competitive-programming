#include "stdio.h"

char binary[32] = {};
int n;

void printBinary(int x){
    int i;
    for(i = 0; x; i++){
        binary[i] = (x&1);
        x = (x>>1);
    }
    if(n-i) printf("%0*d", n-i, 0);
    for(i--; i >= 0; i--){
        putchar(binary[i]+'0');
    }
    printf("\n");
}

int main(){
    int i,j;
    scanf("%d", &n);
    j = (1 << n);

    for(i = 0; i < j; i++){
        printBinary(i);
    }
}
