#include "stdio.h"

int x;
long long sum;

int main(){
    printf("Enter number? ");
    scanf("%d", &x);
    //count how many five
    for(long long mul = 5; mul <= x; mul *= 5){
        sum += x/mul;
    }

    printf("%lld",sum);
    return 0;

}
