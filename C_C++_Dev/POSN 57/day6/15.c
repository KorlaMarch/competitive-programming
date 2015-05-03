#include "stdio.h"
#include "math.h"

int main(){
    int n,i,j;
    scanf("%d", &n);
    for(i = 0; i < n*2-1; i++){
        for(j = 0; j < n*2-1; j++){
            if(i==j||n*2-2-i==j){
                printf("%d", n-abs(n-i-1));
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
}
