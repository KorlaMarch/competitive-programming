#include "stdio.h"
int n,k,i,j,x,y;
int hap[1000];
int maxHap[300][1000];

int max(int a, int b){
    return a>b?a:b;
}

int main(){
    scanf("%d %d", &n, &k);
    for(i = 0; i < n; i++){
        scanf("%d", &hap[i]);
        if(i) hap[i] += hap[i-1];
        maxHap[0][i] = hap[i];
    }
    for(i = 1; i < k; i++){
        for(j = i; j < n; j++){
            maxHap[i][j] = hap[n-1];
            for(x = i; x <= j; x++){
                y = max(maxHap[i-1][x-1],hap[j]-hap[x-1]);
                if(y < maxHap[i][j]) maxHap[i][j] = y;
            }
        }
    }
    printf("%d\n",maxHap[k-1][n-1]);
}
