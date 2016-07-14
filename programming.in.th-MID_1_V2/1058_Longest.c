#include "stdio.h"
int k,m,n,i,j,mx;
short a[5][1000][1000];
int main(){
    scanf("%d", &k);
    for(;k>0;k--){
        scanf("%d%d",&m,&n);
        for(i = 0; i < m; i++){
            getchar();
            for(j = 0; j < n; j++){
                a[0][i][j] = getchar()-'0';
            }
        }

        //pregen table
        for(i = 0; i < m; i++){
            a[1][i][0] = a[0][i][0];
            for(j = 1; j < n; j++){
                if(a[0][i][j]) a[1][i][j] = a[1][i][j-1]+1;
                else a[1][i][j] = 0;
            }
        }
        for(i = 0; i < m; i++){
            a[2][i][n-1] = a[0][i][n-1];
            for(j = n-2; j>=0; j--){
                if(a[0][i][j]) a[2][i][j] = a[2][i][j+1]+1;
                else a[2][i][j] = 0;
            }
        }
        for(i = 0; i < n; i++){
            a[3][0][i] = a[0][0][i];
            for(j = 1; j < m; j++){
                if(a[0][j][i]) a[3][j][i] = a[3][j-1][i]+1;
                else a[3][j][i] = 0;
            }
        }
        for(i = 0; i < n; i++){
            a[4][m-1][i] = a[0][m-1][i];
            for(j = m-2; j>=0; j--){
                if(a[0][j][i]) a[4][j][i] = a[4][j+1][i]+1;
                else a[4][j][i] = 0;
            }
        }
        //Start BF
        mx = 0;
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                if(a[1][i][j]+a[2][i][j]-1>mx) mx = a[1][i][j]+a[2][i][j]-1;
                if(a[1][i][j]+a[3][i][j]-1>mx) mx = a[1][i][j]+a[3][i][j]-1;
                if(a[1][i][j]+a[4][i][j]-1>mx) mx = a[1][i][j]+a[4][i][j]-1;
                if(a[2][i][j]+a[3][i][j]-1>mx) mx = a[2][i][j]+a[3][i][j]-1;
                if(a[2][i][j]+a[4][i][j]-1>mx) mx = a[2][i][j]+a[4][i][j]-1;
                if(a[3][i][j]+a[4][i][j]-1>mx) mx = a[3][i][j]+a[4][i][j]-1;
            }
        }
        printf("%d\n",mx);
    }
}
