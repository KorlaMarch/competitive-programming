#include "stdio.h"

int max(int a, int b){
    return a>b?a:b;
}

int n,i,j;
int books[2000];
int sum[2000][2000];
int bookV(int x){
    return books[x-2] + books[x-1] - books[x];
}
int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d",books+i);
    }
    for(i = 2; i < n; i++){
        sum[i-2][i] = bookV(i);
    }
    for(i = 0; i < n; i++){
        for(j = i+3; j < n; j++){
            sum[i][j] = max(bookV(i+2)+sum[i+3][j],max(bookV(j)+sum[i][j-3],max(sum[i+1][j],sum[i][j-1])));
        }
    }
    printf("%d\n", sum[0][n-1]);
}
