#include "stdio.h"
int n,m,i,j,x,mx;
int qs[2][100];
int qi[2][100];
int main(){
    scanf("%d%d", &n, &m);
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            scanf("%d",&x);
            qs[0][i] += x;
            qs[1][j] += x;
        }
        if(i){
            qs[0][i] += qs[0][i-1];
        }
    }
    for(j = 1; j < m; j++) qs[1][j] += qs[1][j-1];
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            scanf("%d",&x);
            qi[0][i] += x;
            qi[1][j] += x;
        }
    }
    for(i = 0; i < n; i++){
        x = 0;
        if(i > 0) x += qs[0][i-1]+qi[0][i-1];
        if(i+1<n) x += qs[0][n-1]-qs[0][i]+qi[0][i+1];
        if(x > mx) mx = x;
    }
    for(i = 0; i < m; i++){
        x = 0;
        if(i > 0) x += qs[1][i-1]+qi[1][i-1];
        if(i+1<m) x += qs[1][m-1]-qs[1][i]+qi[1][i+1];
        if(x > mx) mx = x;
    }
    printf("%d\n", mx);
}
