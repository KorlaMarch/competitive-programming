#include "stdio.h"

int n,m,i,j;
long long v[305][305];
long long mx[4][305][305];
long long maxC,c;

long long max(long long a, long long b){
    return a>b?a:b;
}

int main(){
    scanf("%d%d",&n,&m);
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            scanf("%lld",&v[i][j]);
            v[i][j] += v[i-1][j]+v[i][j-1]-v[i-1][j-1];
        }
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            mx[0][i][j] = max(v[i][j],max(mx[0][i-1][j],mx[0][i][j-1]));
        }
    }
    for(i = 1; i <= n; i++){
        for(j = m; j > 0; j--){
            mx[1][i][j] = max(v[i][m]-v[i][j-1],max(mx[1][i-1][j],mx[1][i][j+1]));
        }
    }
    for(i = n; i > 0; i--){
        for(j = 1; j <= m; j++){
            mx[2][i][j] = max(v[n][j]-v[i-1][j],max(mx[2][i+1][j],mx[2][i][j-1]));
            printf("%d %d %lld\n",i,j,mx[2][i][j]);
        }
    }
    for(i = n; i > 0; i--){
        for(j = m; j > 0; j--){
            mx[3][i][j] = max(v[n][m]-v[i-1][m]-v[n][j-1]+v[i-1][j-1],max(mx[3][i+1][j],mx[3][i][j+1]));
        }
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            c = mx[0][i-1][j-1]+mx[1][i-1][j]+mx[2][i][j-1]+mx[3][i][j];
            if(c>maxC) maxC = c;
        }
    }
    printf("%lld\n",maxC);
}
