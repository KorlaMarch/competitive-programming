#include "stdio.h"

int map[30][30];

int max(int a, int b){
    return a > b ? a : b;
}

int abs(int n){
    return n < 0 ? n*-1 : n;
}

int findSum(int x1, int y1, int x2, int y2){
    if(abs(map[x1][y1]-map[x2][y2])<=10){
        return map[x1][y1]+map[x2][y2];
    }
    return -1;
}

int main(){
    int t,h,w;
    int i,j,k,t1,t2;
    int maxX,maxY,maxV;
    scanf("%d", &t);
    for(k = 0; k < t; k++){
        scanf("%d%d", &h, &w);
        for(i = 0; i < h; i++){
            for(j = 0; j < w; j++){
                scanf("%d", &map[i][j]);
            }
        }
        maxV = -1;
        for(i = 0; i < h; i++){
            for(j = 0; j < w; j++){
                t1 = t2 = -1;
                if(i+1<h){
                    t1 = findSum(i,j,i+1,j);
                }
                if(j+1<w){
                    t2 = findSum(i,j,i,j+1);
                }
                t1 = max(t1,t2);
                if(t1 > maxV){
                    maxV = t1;
                    maxX = i;
                    maxY = j;
                }
            }
        }
        printf("%d %d\n", maxX+1, maxY+1);
    }
}
