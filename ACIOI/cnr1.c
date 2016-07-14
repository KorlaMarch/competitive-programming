#include "stdio.h"
int t,n,r,i,nc,rc,j;
int c[1001][1001];
int main(){
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d%d",&n,&r);
        for(;nc<=n;nc++){
            for(rc=0;rc<=nc;rc++){
                if(!nc||!rc||nc==rc) c[nc][rc] = 1;
                else c[nc][rc] = (c[nc-1][rc]+c[nc-1][rc-1])%1000000007;
            }
        }
        printf("%d\n",c[n][r]);
    }
}
