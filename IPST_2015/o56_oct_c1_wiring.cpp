#include "stdio.h"
int t,n,i,j;
int a[100005],b[100005],pa[100005];
char isV[100005];

int cycle(int x){
    if(!b[x]) return 0;
    else if(isV[pa[b[x]]]){
        return 1;
    }else{
        isV[x] = 1;
        printf("%d ",x);
        cycle(pa[b[x]]);
    }
}
int main(){
    for(scanf("%d",&t); t > 0; t--){
        scanf("%d",&n);
        for(i = 1; i <= n; i++){
            scanf("%d",&a[i]);
            pa[a[i]] = i;
            isV[i] = 0;
        }
        for(i = 1; i <= n; i++){
            scanf("%d",&b[i]);
        }
        for(i = 1; i <= n; i++){
            printf("%d:\n",i);
            if(cycle(i)) break;
        }
        if(i==n+1) printf("YES\n");
        else printf("NO\n");
    }
}
