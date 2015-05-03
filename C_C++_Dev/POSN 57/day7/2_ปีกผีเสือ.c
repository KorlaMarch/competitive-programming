#include "stdio.h"

int abs(int i){
    return i < 0 ? i*-1 : i;
}

int main(){
    int n,i,j;
    scanf("%d", &n);
    for(i = 0; i < n*2-1; i++){
        for(j = 0; j < n*2-1; j++){
            if(j <= n-abs(n-i-1)-1 || j > n+abs(n-i-1)-2){
                printf("*");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
}
