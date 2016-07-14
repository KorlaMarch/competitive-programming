#include "stdio.h"
#include "conio.h"

int main(){
    int n,i;
    char bit[32] = {};
    scanf("%d", &n);
    for(i = 0; n > 0; i++){
        bit[i] = n%2;
        n = n/2;
    }
    for(i = 7; i >= 0; i--) putchar('0'+bit[i]);
    getch();
}
