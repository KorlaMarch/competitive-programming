#include "stdio.h"
int n,m,i,j,x,y,r,k,c;
char map[1051][1051];
int main(){
    scanf("%d%d",&n,&m);
    for(i = 0; i < n; i++){
        scanf("%d%d", &x, &y);
        map[x][y] = 1;
    }
    for(k = 0; k < m; k++){
        scanf("%d%d%d",&x,&y,&r);
        for(i = x-r>0?x-r:0,c=0; i <= x+r; i++){
            for(j = y-r>0?y-r:0; j <= y+r; j++){
                if(map[i][j]){
                    map[i][j] = 0;
                    c++;
                }
            }
        }
        printf("%d\n", c);
    }
}
