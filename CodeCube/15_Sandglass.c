#include "stdio.h"

void putschar(char c, int n){
    for(;n;n--) putchar(c);
}
int abs(int n){
    return n<0?n*-1:n;
}
int main(){
    int n,i;
    scanf("%d",&n);
    if(n%2){
        for(i = 0; i < n; i++){
            putschar(' ', n/2-abs(n/2-i));
            putschar('*', abs(n/2-i)*2+1);
            putchar('\n');
        }
    }else{
        printf("error\n");
    }
}
