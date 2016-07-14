#include "tourist.h"
int max(int a, int b){
    return a>b?a:b;
}
int GreaterHappiness(int N, int K, int *H){
    int dyn[3][100001];
    int i,j,m;
    for(i = 0; i < 3; i++){
        for(j = 0; j < N; j++){
            dyn[i][j] = -1;
        }
    }
    dyn[0][0] = 0;
    for(i = 1; i <= K; i++){
        for(j = 0; j < N; j++){
            dyn[i%3][j] = dyn[(i+2)%3][j];
            if(i==1&&j==0) dyn[i%3][j] = H[0];
            if(j>0&&dyn[(i+2)%3][j-1]!=-1) dyn[i%3][j] = max(dyn[i%3][j], dyn[(i+2)%3][j-1]);
            if(j>0&&dyn[(i+1)%3][j-1]!=-1) dyn[i%3][j] = max(dyn[i%3][j], dyn[(i+1)%3][j-1]+H[j]);
            //printf("%3d ", dyn[i%3][j]);
        }
        //printf("\n");
    }
    for(i = m = 0; i < N; i++){
        if(dyn[K%3][i]>m){
            m = dyn[K%3][i];
        }
    }
    return m;
}
