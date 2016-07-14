#include "stdio.h"

int main(){
    int n,i,j,k,p;
    int num[10000];
    int queue[10][10000];
    int qf[10];

    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &num[i]);
    }
    for(i=1;num[0]/i > 0;i*=10){
        for(j = 0; j < 10; j++) qf[j] = 0;
        for(j = 0; j < n; j++){
            p = num[j]/i%10;
            queue[p][qf[p]++] = num[j];
        }
        for(j = p = 0; j < 10; j++){
            for(k = 0; k < qf[j]; k++){
                num[p++] = queue[j][k];
            }
        }
    }
    for(i = 0; i < n; i++){
        printf("%d\n", num[i]);
    }
}
