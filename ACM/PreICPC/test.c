#include "stdio.h"

int main(){
    int i,j;
    long long int sum = 0;
    //freopen("out.txt","w",stdout);
    //printf("500 500\n");
    for(i = 1; i <= 500; i++){
        sum += i*i;
        printf("%d %lld\n",i*i,sum);
    }
}
