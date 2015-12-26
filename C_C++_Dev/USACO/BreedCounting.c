#include "stdio.h"

int max(int a, int b){
    return a>b?a:b;
}
int min(int a, int b){
    return a<b?a:b;
}
int n,q,i,x,a,b;
int qs[3][100005];

int main(){
    freopen("bcount.in","r",stdin);
    freopen("bcount.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(i = 1; i <= n; i++){
        scanf("%d",&x);
        qs[0][i] = qs[0][i-1];
        qs[1][i] = qs[1][i-1];
        qs[2][i] = qs[2][i-1];
        qs[x-1][i]++;
    }
    for(i = 0; i < q; i++){
        scanf("%d%d",&a,&b);
        a = max(a,1)-1;
        b = min(b,n);
        printf("%d %d %d\n",qs[0][b]-qs[0][a],qs[1][b]-qs[1][a],qs[2][b]-qs[2][a]);
    }
    return 0;
}
