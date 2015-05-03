#include "stdio.h"

int main(){
    int num[10];
    int i,sum = 0;
    for(i = 0; i < 10; i++){
        scanf("%d", num+i);
    }

    for(i = 0; i < 10; i++){
        sum += *(num+i);
    }

    printf("Sum = %d\n", sum);
}
