#include "stdio.h"
int dtb[1001][1001];
int n,m,x,y,k,i,j;
int qs(int x1, int y1, int x2, int y2){
    int n;
    if(x2>1000) x2 = 1000;
    if(y2>1000) y2 = 1000;
    n = dtb[x2][y2];
    if(x1>=0&&y1>=0){
        n -= dtb[x1][y2]+dtb[x2][y1]-dtb[x1][y1];
    }else if(x1>=0){
        n -= dtb[x1][y2];
    }else if(y1>=0){
        n -= dtb[x2][y1];
    }
    return n;
}
int main(){
    scanf("%d%d",&n,&m);
    for(i = 0; i < n; i++){
        scanf("%d%d",&x,&y);
        dtb[x][y]++;
    }
    for(i = 1; i <= 1000; i++) dtb[0][i] += dtb[0][i-1];
    for(i = 1; i <= 1000; i++){
        dtb[i][0] += dtb[i-1][0];
        for(j = 1; j <= 1000; j++){
            dtb[i][j] += dtb[i-1][j]+dtb[i][j-1]-dtb[i-1][j-1];
        }
    }
    for(i = 0; i < m; i++){
        scanf("%d%d%d",&x,&y,&k);
        printf("%d\n", qs(x-k-1,y-k-1,x+k,y+k));
    }
}
