#include "stdio.h"
#include "algorithm"

int n,k,i,j,x,d;
int qs[1005],mx[1005];
int main(){
    scanf("%d%d",&n,&k);
    for(i = 1; i <= n; i++){
        scanf("%d",&qs[i]);
        qs[i] += qs[i-1];
    }
    for(i = 1; i <= n; i++){
        for(j = i; j <= n; j++){
            d = qs[j]-qs[i-1];
            if(mx[j-i+1]==0||d<mx[j-i+1]){
                mx[j-i+1] = d;
            }
        }
    }
    for(i = 0; i < k; i++){
        scanf("%d",&x);
        d = std::upper_bound(mx,mx+n,x)-mx;
        if(mx[d]<=x) printf("%d\n",d);
        else printf("%d\n",d-1);
    }
}

