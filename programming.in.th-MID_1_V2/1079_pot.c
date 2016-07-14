#include "stdio.h"

int main(){
    int n,k,i,sum;
    int way[100001];
    scanf("%d%d",&n,&k);
    way[0] = 1;
    for(i = 1,sum = 1; i <= n; i++){
        way[i] = sum;
        sum = (sum+way[i])%2009;
        if(i-k>=0) sum = (sum-way[i-k]+2009)%2009;
    }
    printf("%d\n", way[n]);
}
