#include "stdio.h"
#include "algorithm"

int n,m,i,j,x,mx,a;
int fc[101][101];
int sc[101][101];
int dp[101][101][1510];

int getDP(int i, int j, int x){
    if(i==0&&j==0) return 0;
    else if(i<1||j<1) return x<=0?0:-1;
    else if(x<0) return dp[i][j][0];
    else return dp[i][j][x];
}

int main(){
    scanf("%d%d",&n,&m);
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            scanf("%d",&x);
            while(x%2==0){
                fc[i][j]++;
                x /= 2;
            }
            while(x%3==0){
                sc[i][j]++;
                x /= 3;
            }
        }
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            mx = -1;
            for(x = 1500; x >= 0; x--){
                mx = std::max(mx,std::max(getDP(i-1,j,x-sc[i][j]),getDP(i,j-1,x-sc[i][j])));
                if(mx!=-1) dp[i][j][x] = mx+fc[i][j];
                else dp[i][j][x] = -1;
            }
        }
    }
    for(x = 1500,mx = 0; x >= 0; x--){
        mx = std::max(mx,std::min(dp[n][m][x],x));
    }
    printf("%d\n",mx);
}
