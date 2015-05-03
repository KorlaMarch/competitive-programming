#include "stdio.h"

int main(){
    long long v[2] = {}, pow = 3;
    int n,i;
    scanf("%d", &n);
    for(i = 2; i <= n; i++){
        v[i%2] = (pow-v[(i+1)%2])%1000000007;
        if(v[i%2] < 0){
            v[i%2] += 1000000007;
        }
        pow *= 3;
        pow %= 1000000007;
    }
    printf("%I64d\n", v[n%2]%1000000007);
}
