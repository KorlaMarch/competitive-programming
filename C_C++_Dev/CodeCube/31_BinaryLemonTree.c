#include "stdio.h"

int main(){
    long long cat[10001];
    int n,i,j;
    scanf("%d",&n);
    cat[0] = 1;
    for(i = 1; i <= n; i++){
        cat[i] = 0;
        for(j = 0; j < i; j++){
            cat[i] = (cat[i]+cat[j]*cat[i-j-1])%909091;
        }
    }
    printf("%lld\n",cat[n]);
}
