#include "stdio.h"

int max(int a, int b){
    return a>b?a:b;
}

int m,k,i,j,x,mx;
int a[101],b[101],t[101];
int dyn[101][101][101];
int main(){
    scanf("%d%d",&m,&k);
    for(i = 1; i <= k; i++){
        scanf("%d%d%d",&a[i],&b[i],&t[i]);
    }
    for(i = 1; i <= m; i++){
        for(j = 1; j <= k; j++){
            for(x = 50-(j/3+j%3); x <= 50+(j/3+j%3); x++){
                if(a[j]<=i){
                    dyn[i][j][x] = max(dyn[i-1][j][x],dyn[i][j-1][x]);
                    if(t[x]) dyn[i][j][x] = max(dyn[i][j][x],dyn[i-a[j]][j-1][x-1]+b[j]);
                    else dyn[i][j][x] = max(dyn[i][j][x],dyn[i-a[j]][j-1][x+1]);
                    if(dyn[i][j][x]>mx) mx = dyn[i][j][x];
                    printf("%d %d %d : %d\n",i,j,x,dyn[i][j][x]);
                }
            }
        }
        //printf("L");
    }
    printf("%d\n",mx);
}
