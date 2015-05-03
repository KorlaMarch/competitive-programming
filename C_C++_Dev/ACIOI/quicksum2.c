#include "stdio.h"
int m,n,q,i,j,x1,y1,x2,y2;
int sum[1001][1001];
int main(){
    scanf("%d%d%d",&m,&n,&q);
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&sum[i][j]);
            sum[i][j] += sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    }
    for(i=0;i<q;i++){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        printf("%d\n",sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1]);
    }
}
