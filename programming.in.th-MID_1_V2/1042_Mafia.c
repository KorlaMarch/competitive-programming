#include "stdio.h"

int main(){
    int its[2][5000] = {};
    int n,m,k,x,y,r,i,j,max;
    scanf("%d%d%d", &n,&m,&k);
    for(i = 0; i < k; i++){
        scanf("%d%d%d", &x,&y,&r);
        for(j = x-r-1>=0?x-r-1:0; j<n && j<x+r; j++) its[0][j]++;
        for(j = y-r-1>=0?y-r-1:0; j<m && j<y+r; j++) its[1][j]++;
    }
    max = 0;
    for(i = 0; i < n; i++){
        if(its[0][i] > max) max = its[0][i];
    }
    for(i = 0; i < m; i++){
        if(its[1][i] > max) max = its[1][i];
    }
    printf("%d\n", max);
}
