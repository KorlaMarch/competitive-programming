#include "stdio.h"
int n,m,o,i,j,x,y;
long long int way[50][50];
int main(){
    scanf("%d%d%d", &m,&n,&o);
    for(i = 0; i < o; i++){
        scanf("%d%d", &x, &y);
        way[x-1][y-1] = -1;
    }
    way[0][0] = 1;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            if(way[i][j] != -1){
                if(i>0&&way[i-1][j]!=-1) way[i][j] += way[i-1][j];
                if(j>0&&way[i][j-1]!=-1) way[i][j] += way[i][j-1];
            }
        }
    }
    printf("%lld\n", way[m-1][n-1]);
}
