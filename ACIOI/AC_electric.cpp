#include "stdio.h"
#include "algorithm"

unsigned short num[1000000];

int main(){
    int n;
    int i;
    long long power = 0;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &num[i]);
    }
    std::sort(num, num+n);
    for(i = 0; i < n-i-1; i++){
        power += num[n-i-1]-num[i];
    }
    printf("%lld\n", power);
}
