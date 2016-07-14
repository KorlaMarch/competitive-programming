#include "stdio.h"

int n,m,q,i,j,tmp;
int mat[105][105];
int t[10005],r[10005],c[10005],x[10005];
int main(){
    scanf("%d%d%d",&n,&m,&q);
    for(i = 0; i < q; i++){
        scanf("%d",&t[i]);
        if(t[i]==1){
            scanf("%d",&r[i]);
        }else if(t[i]==2){
            scanf("%d",&c[i]);
        }else{
            scanf("%d%d%d",&r[i],&c[i],&x[i]);
        }
    }
    for(i = q-1; i >= 0; i--){
        if(t[i]==1){
            tmp = mat[r[i]][m];
            for(j = m; j > 1; j--){
                mat[r[i]][j] = mat[r[i]][j-1];
            }
            mat[r[i]][1] = tmp;
        }else if(t[i]==2){
            tmp = mat[n][c[i]];
            for(j = n; j > 1; j--){
                mat[j][c[i]] = mat[j-1][c[i]];
            }
            mat[1][c[i]] = tmp;
        }else{
            mat[r[i]][c[i]] = x[i];
        }
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}
