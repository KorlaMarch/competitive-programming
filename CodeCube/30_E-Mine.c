#include "stdio.h"
int max(int a, int b){
    return a>b?a:b;
}
int n,k,i,j,x,y;
int dyn[2][500][51];
int main(){
    scanf("%d%d",&n,&k);
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d",&x);
            if(i&&j) dyn[i&1][j][0] = max(dyn[!(i&1)][j][k],dyn[i&1][j-1][k]);
            else if(i) dyn[i&1][j][0] = dyn[!(i&1)][j][k];
            else if(j) dyn[i&1][j][0] = dyn[i&1][j-1][k];
            for(y = 1; y <= k; y++){
                if(i&&j) dyn[i&1][j][y] = max(dyn[i&1][j][y-1],x+max(dyn[!(i&1)][j][y-1],dyn[i&1][j-1][y-1]));
                else if(i) dyn[i&1][j][y] = max(dyn[i&1][j][y-1],x+dyn[!(i&1)][j][y-1]);
                else if(j) dyn[i&1][j][y] = max(dyn[i&1][j][y-1],x+dyn[i&1][j-1][y-1]);
                else dyn[i&1][j][y] = max(dyn[i&1][j][y-1],x);
            }
        }
    }
    printf("%d\n",dyn[(n+1)%2][n-1][k]);
}
