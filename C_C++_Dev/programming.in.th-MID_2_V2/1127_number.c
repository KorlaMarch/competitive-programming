#include "stdio.h"

int main(){
    int n,i,j,l,m,lim;
    int cost[9];
    scanf("%d",&n);
    for(i=m=0; i < 9; i++){
        scanf("%d", &cost[i]);
        if(cost[i]<=cost[m]) m = i;
    }

    l = n-n/cost[m]*cost[m];
    i = 0;
    lim = n/cost[m];
    while(i<lim){
        for(j = 8; j > m; j--){
            if(cost[j]-cost[m]<=l){
                putchar('1'+j);
                l -= cost[j]-cost[m];
                break;
            }
        }
        if(j==m) break;
        i++;
    }

    for(;i<lim;i++){
        putchar('1'+m);
    }
}
