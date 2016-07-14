#include "stdio.h"

typedef struct{
    int w,h;
}rec;

int main(){
    char in[26][26];
    int rowSum[26][26][2];
    rec room[26][26] = {};
    int m,n,i,j,k;
    int maxP = 0;
    scanf("%d%d", &n , &m);
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            scanf(" %c", &in[i][j]);
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            k = findMaxSize(i,j);
            if(k > maxP){
                maxP = k;
            }
        }
    }
    printf("%d\n", maxP*2);
}
