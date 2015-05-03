#include "stdio.h"

int sum[1000][1000];

int main(){
    int n,m,k;
    int i,j,t;
    int maxP = 0;

    scanf("%d%d%d",&m,&n,&k);
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            scanf("%d",&sum[i][j]);
            if(i > 0){
                sum[i][j] += sum[i-1][j];
            }
            if(j > 0){
                sum[i][j] += sum[i][j-1];
            }
            if(i > 0 && j > 0){
                sum[i][j] -= sum[i-1][j-1];
            }

            if(i+1 >= k && j+1 >= k){
                t = sum[i][j];
                if(i >= k){
                    t -= sum[i-k][j];
                }
                if(j >= k){
                    t -= sum[i][j-k];
                }
                if(i >= k && j >= k){
                    t += sum[i-k][j-k];
                }

                if(t > maxP){
                    maxP = t;
                }
            }
        }
    }
    printf("%d\n", maxP);
}
