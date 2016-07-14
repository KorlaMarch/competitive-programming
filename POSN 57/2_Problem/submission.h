#include "stdio.h"

int max(int a, int b){
    return a>b?a:b;
}
int steelcutting(int s, int n, int* q, int *p){
    int v[100][1001] = {};
    int i,j;
    for(i = 0; i < n; i++){
        for(j = 1; j <= s; j++){
            v[i][j] = v[i][j-1];
            if(i > 0) v[i][j] = max(v[i][j],v[i-1][j]);
            if(j-q[i] >= 0) v[i][j] = max(v[i][j],v[i][j-q[i]]+p[i]);
        }
    }
    return v[n-1][s];
}
