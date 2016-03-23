#include "stdio.h"

int n,k,i,j,sum,c;
int t[505][505];

int main(){
    scanf("%d%d",&n,&k);
    k--;
    c = n*n;
    for(i = 0; i < n; i++){
        for(j = n-1; j > k; j--){
            t[i][j] = c--;
        }
        sum += c;
        t[i][j] = c--;
    }
    for(i = 0; i < n; i++){
        for(j = k-1; j >= 0; j--){
            t[i][j] = c--;
        }
    }
    printf("%d\n",sum);
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%d ",t[i][j]);
        }
        printf("\n");
    }
}
