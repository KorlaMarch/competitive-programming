#include "stdio.h"

int t,m,n,l,k,i,j,x,mx;
int si[1002],wi[1002];

int main(){
    for(scanf("%d",&t); t > 0; t--){
        scanf("%d%d%d%d",&n,&m,&l,&k);
        x = m/l;
        mx = 0;
        for(j = 0; j < k; j++){
            scanf("%d%d", si+j, wi+j);
            if(wi[j]>=n*x){
                wi[j] -= n*x;
                mx += x;
            }else{
                mx += wi[j]/n;
                if(wi[j]%n) mx++;
                wi[j] = 0;
            }
        }
        x = m%l;
        for(i = 0; i<k&&si[i]<=x; i++){
            if(wi[i]) mx++;
        }
        printf("%d\n",mx);
    }
}
