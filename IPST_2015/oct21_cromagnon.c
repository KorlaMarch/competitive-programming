#include "stdio.h"
int n,k,i,j,p,q,u;
int dyn[101][101][20];
int oper[20][20],num[101];
int main(){
    scanf("%d",&k);
    for(i = 0; i < k; i++){
        for(j = 0; j < k; j++){
            scanf("%d",&oper[i][j]);
        }
    }
    scanf("%d",&n);
    for(i = 1; i <= n; i++){
        scanf("%d",&num[i]);
    }
    for(i = n; i >= 1; i--){
        dyn[i][i][num[i]] = 1;
        for(j = i+1; j <= n; j++){
            for(p = i; p < j; p++){
                for(q = 0; q < k; q++){
                    for(u = 0; u < k; u++){
                        dyn[i][j][oper[q][u]] = (dyn[i][j][oper[q][u]]+dyn[i][p][q]*dyn[p+1][j][u])%2009;
                    }
                }
            }
        }
    }
    for(i = 0; i < k; i++){
        printf("%d\n",dyn[1][n][i]%2009);
    }
}
