#include "stdio.h"

int n,i,j,mx;
int num[300000];
int canSp[300000][60];

int main(){
    scanf("%d",&n);
    for(i = 1; i <= n; i++){
        scanf("%d",&num[i]);
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j < 60; j++){
            if(j==num[i]) canSp[i][j] = i;
            else if(canSp[i][j-1]&&canSp[canSp[i][j-1]-1][j-1]){
                canSp[i][j] = canSp[canSp[i][j-1]-1][j-1];
            }
            if(canSp[i][j]&&j>mx) mx = j;
        }
    }
    printf("%d\n",mx);
}
