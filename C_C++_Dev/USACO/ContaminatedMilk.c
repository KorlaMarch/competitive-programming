#include "stdio.h"

int n,m,d,s,mx,sp,st,i,j;
int dp[1001],dm[1001],dt[1001],feq[60],isE[60][60],isG[60],isP[60];

int main(){
    freopen("badmilk.in","r",stdin);
    freopen("badmilk.out","w",stdout);
    scanf("%d%d%d%d",&n,&m,&d,&s);
    for(i = 0; i < d; i++){
        scanf("%d%d%d",&dp[i],&dm[i],&dt[i]);
        if(!isE[dp[i]][dm[i]]){
            isE[dp[i]][dm[i]] = 1;
            feq[dm[i]]++;
        }
    }
    for(i = 0; i < s; i++){
        scanf("%d%d",&sp,&st);
        for(j = 0; j < d; j++){
            if(dp[j]==sp&&dt[j]<st) isP[dm[j]] = 1;
        }
        for(j = 1; j <= m; j++){
            if(!isP[j]){
                isG[j] = 1;
            }else isP[j] = 0;
        }
    }
    for(j = 1; j <= m; j++){
        if(!isG[j]&&feq[j]>mx) mx = feq[j];
    }
    printf("%d\n",mx);
    return 0;
}
