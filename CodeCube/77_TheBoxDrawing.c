#include "stdio.h"
int abs(int a){
    return a<0?a*-1:a;
}
char pic[50][50];
int i,j,k,x,y,n,mid;
int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        for(j = 0; j < n*2+1; j++){
            if(i&&abs(j-n)<=i) pic[i][j] = '#';
            else pic[i][j] = '-';
        }
    }
    for(;i < n*2-2; i++){
        pic[i][0] = '-';
        for(j = 1; j < n*2; j++){
            pic[i][j] = '#';
        }
        pic[i][n*2] = '-';
    }
    for(i = n*2-2,k=n-1; k>=0; i++,k--){
        for(j = 0; j < n*2+1; j++){
            if(k>1&&abs(j-n)<=k) pic[i][j] = '#';
            else pic[i][j] = '-';
        }
    }
    for(x = 2,y = n*2-2,i = n-1; x <= y; x++,y--,i++){
        pic[i][x] = pic[i][y] = '-';
    }
    for(i = n*2-3; i < n*3-3; i++){
        pic[i][n] = '-';
    }
    for(i = 0; i < n*3-3; i++){
        for(j = 0; j < n*2+1; j++){
            printf("%c ", pic[i][j]);
        }
        printf("\n");
    }
}
