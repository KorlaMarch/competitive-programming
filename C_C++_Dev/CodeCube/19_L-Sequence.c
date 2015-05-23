#include "stdio.h"

int main(){
    int n,k,i,j,p,mn;
    int se[1000];
    scanf("%d%d",&n,&k);
    k = n-k;
    for(i = 0; i < n; i++){
        scanf("%d",se+i);
    }
    for(i=p=0; i < k; i++,p++){
        for(j=p,mn=100001;j<=n-k+i;j++){
            if(se[j]<mn){
                p = j;
                mn = se[j];
            }
        }
        printf("%d ",mn);
    }
}
