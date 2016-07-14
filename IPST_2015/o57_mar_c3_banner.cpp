#include "stdio.h"

int n,m,i,j,k,s,t,mx,sum;
int ban[305][305];
int dp[305][305];
int max(int a, int b){
    return a>b?a:b;
}

int main(){
    scanf("%d%d",&n,&m);
    for(i = 0; i < m; i++){
        scanf("%d%d",&s,&t);
        if(s==t) sum++;
        else ban[s][t]++;
    }
    for(i = n; i > 0; i--){
        for(j = i; j <= n; j++){
            mx = 0;
            for(k = i; k <= j; k++){
                mx = max(mx,dp[i][k]+dp[k+1][j]);
            }
            dp[i][j] = mx+ban[i][j];
            //printf("DP %d %d = %d\n",i,j,dp[i][j]);
        }
    }
    printf("%d\n",m-dp[1][n]-sum);
}
