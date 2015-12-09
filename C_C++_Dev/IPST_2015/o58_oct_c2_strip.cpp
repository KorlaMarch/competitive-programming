#include "stdio.h"
int n,m,w,k,i,j,x1,y1,x2,y2;
int fen[1006][1006];
void addFen(int x, int y, int v){
    for(int i = x;i<=w;i+=(i&-i)){
        for(int j = y;j<=w;j+=(j&-j)){
            fen[i][j] += v;
        }
    }
}
int getFen(int x,int y){
    int sum = 0;
    for(int i = x;i>0;i-=(i&-i)){
        for(int j = y;j>0;j-=(j&-j)){
            sum += fen[i][j];
        }
    }
    return sum;
}
int main(){
    w = 1005;
    scanf("%d%d%d",&n,&m,&k);
    for(i = 0; i < n; i++){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        addFen(x1+1,y1+1,1);
        addFen(x1+1,y2+2,-1);
        addFen(x2+2,y1+1,-1);
        addFen(x2+2,y2+2,1);
        //printf("ADD %d %d\n",getFen())
    }
    for(i = 0; i < m; i++){
        scanf("%d%d",&x1,&y1);
        printf("%d\n",getFen(x1+1,y1+1));
    }
}
