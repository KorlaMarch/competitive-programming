#include "stdio.h"
int min(int a, int b){
    return a<b?a:b;
}
int n,k,i,j,a,b,mn,s;
int minPow[100005][300];
int main(){
    scanf("%d%d %d%d",&n,&k,&a,&b);
    minPow[1][151] = a;
    minPow[1][149] = b;
    for(i = 2; i <= n; i++){
        scanf("%d%d",&a,&b);
        s = min(i,k);
        for(j = 150-s; j <= 150+s; j++){
            if(!minPow[i-1][j-1]&&!minPow[i-1][j+1]){
                minPow[i][j] = 0;
            }else if(!minPow[i-1][j-1]){
                minPow[i][j] = minPow[i-1][j+1]+b;
            }else if(!minPow[i-1][j+1]){
                minPow[i][j] = minPow[i-1][j-1]+a;
            }else{
                minPow[i][j] = min(minPow[i-1][j-1]+a,minPow[i-1][j+1]+b);
            }
        }
    }
    mn = 2000000000;
    s = min(n,k);
    for(i = 150-s; i <= 150+s; i++){
        if(minPow[n][i]&&minPow[n][i]<mn) mn = minPow[n][i];
    }
    printf("%d\n",mn);
}
