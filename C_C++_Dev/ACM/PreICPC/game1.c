#include "stdio.h"

int h,w,i,j;
long long int sum;
char isFob[601][601];
int way[3000];

int findWay(int x, int y){
    isFob[x][y] = 1;
    way[x+y]++;
    if(x+1<h&&!isFob[x+1][y]){
        findWay(x+1,y);
    }
    if(y+1<w&&!isFob[x][y+1]){
        findWay(x,y+1);
    }
}

int main(){
    scanf("%d%d",&h,&w);
    for(i = h-1; i >= 0; i--){
        for(j = 0; j < w; j++){
            scanf("%d", &isFob[i][j]);
        }
    }
    findWay(0,0);
    for(i = 0; i <= h+w; i++){
        sum += way[i]*(long long int)way[i];
    }
    printf("%lld",sum);
}
