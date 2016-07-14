#include "stdio.h"
#include "algorithm"

int n,m,k,i,j,lp;
int si[35];
long long ans;
long long way[410],way2[410];

int main(){
    scanf("%d%d%d",&k,&m,&n);
    for(i = 0; i < k; i++){
        scanf("%d",&si[i]);
    }
    std::sort(si,si+k);
    way[0] = way2[0] = 1;
    lp = 1;
    for(i = 1; i <= 2*n+2*m-4; i++){
        for(j = 0; j < k && i-si[j] >= lp-1; j++){
            way[i] = (way[i]+way[i-si[j]])%9661;
        }
        if(i==n||i==n+m-1||i==2*n+m-2||i==2*n+2*m-3){
            lp = i;
        }
        //printf(":%d : %lld\n",i,way[i]);
    }
    lp = 1;
    for(i = 1; i <= 2*n+2*m-4; i++){
        for(j = 0; j < k && i-si[j] >= lp-1; j++){
            way2[i] = (way2[i]+way2[i-si[j]])%9661;
        }
        if(i==n-1||i==n+m-2||i==2*n+m-3||i==2*n+2*m-4){
            lp = i;
        }
        //printf("2:%d : %lld\n",i,way2[i]);
    }
    printf("%lld\n",(way[2*n+2*m-4]+way2[2*n+2*m-4]-way2[2*n+2*m-5]+9661)%9661);
}
