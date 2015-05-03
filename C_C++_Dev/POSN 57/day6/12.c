#include "stdio.h"

int main(){
    int n,i;
    int fq[10] = {};
    scanf("%d", &n);
    for(i = 1; n != 0; i*=10, n/=10){
        fq[n%10]++;
        printf("%7dth digit is %d\n", i, n%10);
    }
    printf("Frequency:\n");
    for(i = 0; i < 10; i++){
        if(fq[i]) printf("%d = %d\n", i, fq[i]);
    }
}
