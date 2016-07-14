#include "stdio.h"
int n,m,i,j,vi;
int w[2][50200];
int main(){
    scanf("%d%d",&n,&m);
    w[0][0] = 1;
    for(i = 0; i < n; i++){
        scanf("%d",&vi);
        for(j = 0; j <= m; j++){
            if(j-vi>=0&&w[i%2][j-vi]) w[(i+1)%2][j] = (w[i%2][j-vi]+w[i%2][j])%1000007;
            else w[(i+1)%2][j] = w[i%2][j];
        }
    }
    printf("%d\n",w[i%2][m]);
}
