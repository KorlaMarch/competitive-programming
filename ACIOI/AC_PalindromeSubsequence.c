#include "stdio.h"

int max(int a, int b){
    return a > b ? a : b;
}

int main(){
    int n,i,j;
    int num[5000];
    int dynTable[5000][2] = {};
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &num[i]);
    }
    //find lcs
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(num[i] == num[n-j-1]){
                if(j <= 0){
                    dynTable[j][i%2] = 1;
                }else{
                    dynTable[j][i%2] = 1+dynTable[j-1][(i+1)%2];
                }
            }else{
                if(j <= 0){
                    dynTable[j][i%2] = dynTable[j][(i+1)%2];
                }else{
                    dynTable[j][i%2] = max(dynTable[j][(i+1)%2], dynTable[j-1][i%2]);
                }
            }
        }
    }
    printf("%d\n", dynTable[j-1][(i+1)%2]);
}
