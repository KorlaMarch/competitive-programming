#include "stdio.h"
int n,i,j,s;
int sq[10][10];
int num[101] = {};
int getSum(int x, int y, int cx, int cy){
    if(x>=n||y>=n||x<0||y<0) return 0;
    else{
        return sq[x][y]+getSum(x+cx,y+cy,cx,cy);
    }
}

int main(){
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &sq[i][j]);
            if(num[sq[i][j]]){
                printf("No\n");
                return 0;
            }
            num[sq[i][j]] = 1;
        }
    }
    s = getSum(0,0,1,1);
    if(s == getSum(0,n-1,1,-1)){
        for(i = 0; i < n; i++){
            if(getSum(0,i,1,0)!=s||getSum(i,0,0,1)!=s){
                printf("No\n");
                return 0;
            }
        }
    }else{
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
}
