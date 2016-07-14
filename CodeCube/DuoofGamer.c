#include "stdio.h"
int max(int a, int b){
    return a>b?a:b;
}
int q,n,a,b,k,i,j,x,y;
short dyn[101][101][31][21];
short xi[31],yi[31],vi[31];
int main(){
    scanf("%d",&q);
    for(;q>0;q--){
        scanf("%d%d%d%d",&n,&a,&b,&k);
        for(i = 0; i < n; i++){
            scanf("%d%d%d",xi+i,yi+i,vi+i);
        }
        for(i = 0; i <= a; i++)
            for(j = 0; j <= b; j++)
                for(x = 0; x < n; x++)
                    for(y = k*-1; y <= k; y++)
                        dyn[i][j][x][y+10] = 0;
        for(i = 1; i <= a; i++){
            for(j = 1; j <= b; j++){
                for(x = 0; x < n; x++){
                    for(y = k*-1; y <= k; y++){
                        dyn[i][j][x][y+10] = max(max(dyn[i-1][j][x][y+10],dyn[i][j-1][x][y+10]),dyn[i][j][x][y+10]);
                        if(x) dyn[i][j][x][y+10] = max(dyn[i][j][x][y+10],dyn[i][j][x-1][y+10]);
                        if(y<0) dyn[i][j][x][y+10] = max(dyn[i][j][x][y+10],dyn[i][j][x][y+11]);
                        else if(y>0) dyn[i][j][x][y+10] = max(dyn[i][j][x][y+10],dyn[i][j][x][y+9]);
                        if(i+xi[x]<=a) dyn[i+xi[x]][j][x][y+11] = max(dyn[i+xi[x]][j][x][y+11],dyn[i][j][x][y+10]+vi[x]);
                        if(j+yi[x]<=b) dyn[i][j+yi[x]][x][y+9] = max(dyn[i][j+yi[x]][x][y+9],dyn[i][j][x][y+10]+vi[x]);
                        //printf("%d %d %d %d %d\n",i,j,x,y,dyn[i][j][x][y+10]);
                    }
                }
            }
        }
        printf("%d\n", max(dyn[a][b][n-1][k*-1+10],dyn[a][b][n-1][k+10]));
    }
}
