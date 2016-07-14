#include "stdio.h"
int r,c,k,i,j,x,y,m;
short v[300][300];
int qsH[300][300];
int qsV[300][300];
int min(int a, int b){
    return a<b?a:b;
}
int max(int a, int b){
    return a>b?a:b;
}
int main(){
    scanf("%d%d%d", &r, &c, &k);
    for(i = 0; i < r; i++){
        for(j = 0; j < c; j++){
            scanf("%d", &v[i][j]);
            x=v[i][j];
            if((i+j)&1) x *= -1;
            if(i) qsV[i][j] = x+qsV[i-1][j];
            else qsV[i][j] = x;
            if(j) qsH[i][j] = x+qsH[i][j-1];
            else qsH[i][j] = x;
        }
    }
    m = -10000000;
    for(i = 0; i < r; i++){
        for(j = 0; j < c; j++){
            if((i+j)&1) m = max(m,((i-k)<=0?0:qsV[i-k-1][j])-qsV[min(r-1,i+k)][j]-qsH[i][min(c-1,j+k)]+((j-k)<=0?0:qsH[i][j-k-1])-v[i][j]);
            else m = max(m,qsV[min(r-1,i+k)][j]-((i-k)<=0?0:qsV[i-k-1][j])+qsH[i][min(c-1,j+k)]-((j-k)<=0?0:qsH[i][j-k-1])-v[i][j]);
        }
    }
    printf("%d\n",m);
}
