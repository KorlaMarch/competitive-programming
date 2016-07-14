#include "stdio.h"

int m[501][501];
int minA[505];
int n,i,j;

int main(){
    scanf("%d",&n);
    for(i = 1; i <= n; i++){
        for(j = i+1; j <= n; j++){
            scanf("%d",&m[i][j]);
        }
    }
    minA[1] = 0;
    for(i = 2; i <= n; i++){
        minA[i] = 2000000000;
        for(j = 1; j < i; j++){
            if(minA[j])
        }
    }
}
