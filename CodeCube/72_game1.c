#include "stdio.h"

int w,h,i,j;
char fob[600][600];
int pos[1200];
long long int sum;

void genPos(int x, int y){
    fob[x][y] = 1;
    pos[x+y]++;
    if(x+1<w&&!fob[x+1][y]) genPos(x+1,y);
    if(y+1<h&&!fob[x][y+1]) genPos(x,y+1);
}

int main(){
    scanf("%d%d",&w,&h);
    for(i = w-1; i >= 0; i--){
        for(j = 0; j < h; j++){
            scanf(" %d",&fob[i][j]);
        }
    }
    genPos(0,0);
    for(i = 0; i <= w+h-2; i++){
        sum += pos[i]*pos[i];
    }
    printf("%lld",sum);
}
