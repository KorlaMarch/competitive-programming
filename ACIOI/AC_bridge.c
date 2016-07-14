#include "stdio.h"

int max(int a, int b){
    return a > b ? a : b;
}

int main(){
    int n,i,j;
    short north[3000];
    short sorth[3000];
    short bridge[2][3000] = {};
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &north[i]);
    }
    for(i = 0; i < n; i++){
        scanf("%d", &sorth[i]);
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(north[i] == sorth[j]){
                if(j == 0){
                    bridge[i%2][j] = 1;
                }else{
                    bridge[i%2][j] = 1+bridge[(i+1)%2][j-1];
                }
            }else{
                if(j == 0){
                    bridge[i%2][j] = bridge[(i+1)%2][j];
                }else{
                    bridge[i%2][j] = max(bridge[i%2][j-1], bridge[(i+1)%2][j]);
                }
            }
        }
    }
    printf("%d\n", bridge[(n+1)%2][n-1]);
}
