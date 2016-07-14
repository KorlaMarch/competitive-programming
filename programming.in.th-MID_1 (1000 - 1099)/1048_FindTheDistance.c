#include "stdio.h"

unsigned int pow(int power){
    if(power <= 0){
        return 1;
    }
    return 2*pow(power-1);
}

int main(){
    unsigned int k, n;
    int i;
    unsigned int sum = 0;
    scanf("%u%u", &k, &n);

    for(i = 0; i < k; i++){
        sum += n/pow(i);
        //printf("sum = %d\n", pow(i));
    }
    printf("%d\n", sum);
}
