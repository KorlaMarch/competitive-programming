#include "stdio.h"
int m,n,i,j,k,maxSum;
int qs[1001][1001];
int main(){
    scanf("%d%d %d",&m,&n,&k);
    for(i = 1; i <= m; i++){
        for(j = 1; j <= n; j++){
            scanf("%d",&qs[i][j]);
            qs[i][j] += qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];
        }
    }
    for(i = k; i <= m; i++){
        for(j = k; j <= n; j++){
            if(qs[i][j]-qs[i-k][j]-qs[i][j-k]+qs[i-k][j-k]>maxSum) maxSum = qs[i][j]-qs[i-k][j]-qs[i][j-k]+qs[i-k][j-k];
        }
    }
    printf("%d\n",maxSum);
}
