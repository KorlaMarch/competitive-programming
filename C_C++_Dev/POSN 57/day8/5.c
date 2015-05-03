#include "stdio.h"

int main(){
    int patten[32];
    int n,i,j;
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d",&patten[i]);
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(i == n/2 || j == n/2){
                printf("%d", patten[(j+i)%n]);
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
}
