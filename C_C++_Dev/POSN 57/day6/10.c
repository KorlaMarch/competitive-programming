#include "stdio.h"

int main(){
    int n,i,sum = 0;
    scanf("%d", &n);
    for(i = 2; i < n; i++){
        sum += i*(n-i-1);
    }
    printf("sum = %d\n", sum);
}
