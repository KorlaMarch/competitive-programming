#include "stdio.h"

int max(int a, int b){
    return a > b ? a : b;
}

int main(){
    int dyn[250][250];
    int in[250][250];
    int n,m;
    int i,j;

    scanf("%d%d", &n, &m);
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            scanf("%d", &in[i][j]);
        }
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            if(!i && !j){
                dyn[i][j] = 0;
            }else if(!i){
                dyn[i][j] = dyn[i][j-1];
            }else if(!j){
                dyn[i][j] = dyn[i-1][j];
            }else{
                dyn[i][j] = max(dyn[i-1][j],dyn[i][j-1]);
            }
            dyn[i][j] += in[i][j];
        }
    }
    printf("%d\n", dyn[n-1][m-1]);
}
