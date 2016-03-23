#include "stdio.h"

int n,k,p,i;
int cost[40][40];
long long minC[40][40][40];


void findMin(int d, int n){
    int i,j;
    if(n==1){
        for(i = 0; i < k; i++){
            minC[d][i][i] = 0;
            for(j = i+1; j%k != i; j++){
                minC[d][i][j%k] = minC[d][i][(j-1+k)%k]+cost[(j-1+k)%k][1];
            }
            for(j = i-1+k; minC[d][i][(j+1)%k]+cost[(j+1)%k][0]<minC[d][i][j%k]; j--){
                minC[d][i][j%k] = minC[d][i][(j+1)%k]+cost[(j+1)%k][0];
            }
        }
    }else{
        findMin(d+1,n/2);
        //combine
        for(i = 0; i < k; i++){

        }
        if()
    }
}

int main(){
    scanf("%d%d%d",&n,&k,&p);
    for(i = 0; i < k; i++){
        scanf("%d%d%d%d%d",&cost[i][0],&cost[i][1],&cost[i][2],&cost[i][3],&cost[i][4]);
    }
    findMin(0,d);
}
