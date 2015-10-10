#include "stdio.h"
int t,n,r,c,k,i,j,x,y,p,isP;
int qs[1005][1005];
int fac[30000];
int main(){
    for(scanf("%d",&t); t > 0; t--){
        scanf("%d%d%d%d",&n,&r,&c,&k);
        for(p=0,i=1; i <= n; i++){
            if(n%i==0) fac[p++] = i;
        }
        for(i = 1; i <= r; i++){
            for(j = 1; j <= c; j++){
                qs[i][j] = 0;
            }
        }
        for(i = 0; i < k; i++){
            scanf("%d%d",&x,&y);
            qs[x][y] = 1;
        }

        for(i = 1; i <= r; i++){
            for(j = 1; j <= c; j++){
                qs[i][j] += qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];
            }
        }
        isP = 0;
        for(i = 1; i <= r && !isP; i++){
            for(j = 1; j <= c && !isP; j++){
                for(y = 0; y < p && !isP; y++){
                    x = fac[y];
                    if(i+x-1<=r&&j+n/x-1<=c&&qs[i+x-1][j+n/x-1]-qs[i+x-1][j-1]-qs[i-1][j+n/x-1]+qs[i-1][j-1]==0){
                        printf("%d %d\n",i,j);
                        isP = 1;
                    }
                }
            }
        }
        if(!isP) printf("-1 -1\n");
    }
}
