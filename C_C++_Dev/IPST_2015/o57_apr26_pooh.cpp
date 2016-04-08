#include "stdio.h"
#include "algorithm"

int r,c,e,i,j,x,y;
int en[3005][3005];
int main(){
    scanf("%d%d%d",&r,&c,&e);
    for(i = 0; i < e; i++){
        scanf("%d%d",&x,&y);
        en[x+1][y+1] = 1;
    }
    for(i = 1; i <= r; i++){
        for(j = 1; j <= c; j++){
            en[i][j] += std::max(en[i-1][j],en[i][j-1]);
        }
    }
    printf("%d\n",en[r][c]);
}
