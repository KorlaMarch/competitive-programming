#include "stdio.h"
#include "algorithm"

int n,k,i,x;
int qs[100005];
int main(){
    scanf("%d%d",&n,&k);
    for(i = 1; i <= n; i++){
        scanf("%d",&qs[i]);
        qs[i] += qs[i-1];
    }
    for(i = 0; i < k; i++){
        scanf("%d",&x);
        printf("%d\n",std::upper_bound(qs,qs+n+1,x)-qs-1);
    }
}
