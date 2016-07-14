#include "stdio.h"

int abs(int n){
    return n<0?n*-1:n;
}

int main(){
    int n,x,i,j;
    scanf("%d",&n);
    x = (n-1)/2;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(abs(x-j)<=x-abs(x-i)) putchar('*');
            else putchar('-');
        }
        putchar('\n');
    }
}
