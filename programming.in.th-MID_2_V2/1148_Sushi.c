#include "stdio.h"
int n,m,k,i,j,l;
int r[20005],p[20005],maxHap[2][20000];
int max(int a, int b){
    return a>b?a:b;
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(i = 1; i <= m; i++){
        scanf("%d",r+i);
    }
    r[++m] = n;
    for(i = 1; i <= k; i++){
        scanf("%d",p+i);
    }
    for(i = 1; i <= m; i++) maxHap[0][i] = -2000000000;
    for(i = 1; i <= m; i++){
        l = r[i]-r[i-1];
        for(j = 1; j <= k; j++){
            maxHap[i&1][j] = max(maxHap[!(i&1)][j],maxHap[!(i&1)][j-1])+l*p[j];
        }
    }
    printf("%d\n",maxHap[m&1][k]);
}
