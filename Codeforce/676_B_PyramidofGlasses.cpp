#include "stdio.h"
#include "algorithm"
int n,t,i,j,k,c;
double wa[11][12];

int main(){
    scanf("%d%d",&n,&t);
    for(i = 0; i < t; i++){
        wa[1][1] += 1.0;
        for(j = 2; j <= n; j++){
            for(k = 1; k <= j; k++){
                if(wa[j-1][k-1]>1.0){
                    wa[j][k] += (wa[j-1][k-1]-1.0)/2.0;
                }
                if(wa[j-1][k]>1.0){
                    wa[j][k] += (wa[j-1][k]-1.0)/2.0;
                }
            }
            for(k = 1; k <= j; k++){
                if(wa[j-1][k-1]>1.0){
                    wa[j-1][k-1] = 1.0;
                }
                if(wa[j-1][k]>1.0){
                    wa[j-1][k] = 1.0;
                }
            }
        }
    }
    for(j = 1; j <= n; j++){
        for(k = 1; k <= j; k++){
            if(wa[j][k]>=1.0){
                c++;
            }
        }
    }
    printf("%d\n",c);
}
