#include "stdio.h"
int x,y,m,i,j,mx=-16;
int mu[20][20];
void findMax(int x, int y,int t_in){
    if(x<0||y<0||x>=m||y>=m||mu[x][y]==100||mu[x][y]<=t_in) return;
    if(mu[x][y]>mx) mx = mu[x][y];
    t_in = mu[x][y];
    mu[x][y] = 100;
    findMax(x-1,y,t_in);
    findMax(x+1,y,t_in);
    findMax(x,y-1,t_in);
    findMax(x,y+1,t_in);
}
int main(){
    scanf("%d %d%d",&m,&x,&y);
    for(i = 0; i < m; i++){
        for(j = 0; j < m; j++){
            scanf("%d", &mu[i][j]);
        }
    }
    findMax(y-1, x-1,-50);
    printf("%d\n", mx);
}
