#include "stdio.h"

int n,m,i,j,k,l,s,mx;
int li[105];

int main(){
    freopen("speeding.in","r",stdin);
    freopen("speeding.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=k=0; i < n; i++){
        scanf("%d%d",&l,&s);
        for(j = 0; j < l; j++,k++){
            li[k] = s;
        }
    }
    for(i=k=0; i < m; i++){
        scanf("%d%d",&l,&s);
        for(j = 0; j < l; j++,k++){
            if(li[k]&&s-li[k]>mx) mx = s-li[k];
        }
    }
    printf("%d\n",mx);
    return 0;
}
