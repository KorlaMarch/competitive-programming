#include "stdio.h"
int t,n,k,i,j,sum;
int dyn[2][102][102];
int main(){
    dyn[0][1][0] = 1;
    dyn[0][2][0] = 2;
    dyn[0][2][1] = 1;
    dyn[1][2][1] = 1;
    for(i = 3; i <= 100; i++){
        for(j = 0; j <= 100; j++){
            dyn[0][i][j] += dyn[0][i-1][j]+dyn[0][i-2][j];
            if(j){
                dyn[0][i][j] += dyn[0][i-2][j-1]+2*dyn[1][i-1][j-1];
                dyn[1][i][j] += dyn[0][i-2][j-1];
            }
            dyn[1][i][j] += dyn[1][i-1][j];
            dyn[0][i][j] %= 9241;
            dyn[1][i][j] %= 9241;
        }
    }
    for(scanf("%d",&t); t > 0; t--){
        scanf("%d%d",&n,&k);
        for(i=sum=0; i <= k; i++) sum += dyn[0][n][i];
        printf("%d\n",sum%9241);
    }
}
