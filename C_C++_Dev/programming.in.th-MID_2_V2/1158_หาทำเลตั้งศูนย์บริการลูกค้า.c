#include "stdio.h"
int m,n,k,i,j,max,x;
int p[1001][1001];

int main(){
    scanf("%d %d %d",&m,&n,&k);
    for(i = 1; i <= m; i++){
        for(j = 1; j <= n; j++){
            scanf("%d",&p[i][j]);
            p[i][j] += p[i-1][j]+p[i][j-1]-p[i-1][j-1];
        }
    }
    for(i = k,max = 0; i <= m; i++){
        for(j = k; j <= n; j++){
            x = p[i][j]-p[i-k][j]-p[i][j-k]+p[i-k][j-k];
            if(x>max) max = x;
        }
    }
    printf("%d\n",max);
}
