#include "stdio.h"

int l,n,i,j,x,p,rl;
long long k,del;
long long dp[105][105];
int a[105];
int pos[105];

int main(){
    scanf("%d%d %lld",&n,&l,&k);
    for(i = 0; i < n; i++){
        scanf("%d",&a[i]);
        pos[a[i]] = i;
    }
    for(i = n-1; i >= 0; i--){
        for(j = 0; j <= l; j++){
            dp[i][j] = 1;
            for(x = i+1; x < n; x++){
                if(a[i]<a[x]){
                    if(dp[x][j]!=-1&&dp[i][j]+dp[x][j]<=k) dp[i][j] += dp[x][j];
                    else{
                        dp[i][j] = -1;
                        break;
                    }
                }else{
                    if(j>0){
                        if(dp[x][j-1]!=-1&&dp[i][j]+dp[x][j-1]<=k) dp[i][j] += dp[x][j-1];
                        else{
                            dp[i][j] = -1;
                            break;
                        }
                    }
                }
            }
        }
    }
    for(p = -1,rl = l; k >= 0; k--){
        for(j = 0; j < n; j++){
            if(pos[j]>p){
                del = (p==-1||a[p]<j)?dp[pos[j]][rl]:(rl>0?dp[pos[j]][rl-1]:0);
                if(k>=del&&del!=-1){
                    k -= del;
                }else{
                    if(p!=-1&&a[p]>j) rl--;
                    //printf("%d : %d %lld\n",j,rl,k);
                    printf("%d ",j);
                    p = pos[j];
                    break;
                }
            }
        }
        if(j==n){
            printf("-1\n");
            break;
        }
    }
}
