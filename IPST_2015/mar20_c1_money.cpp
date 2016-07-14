#include "stdio.h"

#define INF 1e10

int t,n,i,j,k;
double exR[501][501];

double max(double a, double b){
    return a>b?a:b;
}
bool isOver(){
    int k,i,j;
    for(k = 0; k < n; k++){
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                exR[i][j] = max(exR[i][j],exR[i][k]*exR[k][j]);
            }
            if(exR[i][i]>1.0) return true;
        }
    }
    return false;
}

int main(){
    for(scanf("%d",&t); t > 0; t--){
        scanf("%d",&n);
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                scanf("%lf",&exR[i][j]);
                //printf("%f",exR[i][j]);
            }
        }
        if(isOver()) printf("YES\n");
        else printf("NO\n");
    }
}
