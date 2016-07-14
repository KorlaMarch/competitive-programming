#include <stdio.h>

int main(){
    int x;
    printf("\n\tInput = "); scanf("%d", &x);
    printf("\n\tOutout =  %c\n", x%26 + 0x40);
    return 0;
}
