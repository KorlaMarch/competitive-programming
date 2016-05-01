#include "stdio.h"
#include "algorithm"

int n,k,i,j,v;
int dp[1002][1001];

int main(){
    scanf("%d%d",&n,&k);
    n++;
    for(i = 2; i <= n; i++){
        scanf("%d",&v);
        dp[i][0] = std::max(dp[i-2][0]+v,dp[i-1][0]);
        for(j = 1; j <= k; j++){
            dp[i][j] = std::max(std::max(dp[i-2][j]+v,dp[i-1][j]),std::max(dp[i-1][j-1]+v,dp[i][j-1]));
        }
    }
    printf("%d\n",dp[n][k]);
}
