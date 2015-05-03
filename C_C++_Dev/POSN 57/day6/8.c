#include "stdio.h"

int main(){
    char is_prime[300001] = {};
    int i,j;
    long long unsigned sum = 0;
    for(i = 2; i <= 300000; i++){
        //printf("s%d ", is_prime[i]);
        if(!is_prime[i]){
            printf("%d ", i);
            sum += i;
            for(j = i*2; j <= 300000; j += i){
                is_prime[j] = 1;
            }
        }
    }
    printf("\nSum = %llu\n", sum);
}
