#include "stdio.h"
int factTo(int n, int r){
    if(n<=r) return 1;
    return n*factTo(n-1,r);
}
int p(int n, int r){
    return factTo(n,n-r);
}
int n,k,l,i,j,pnr;
char isUsed[12];
int main(){
    scanf("%d%d%d",&n,&k,&l);
    for(i = 0; i < k && j <= n; i++){
        pnr = p(n-i-1,k-i-1);
        for(j = 1;j<=n&&l>pnr;j++){
            if(!isUsed[j]){
                l -= pnr;
            }
        }
        for(;j<=n&&isUsed[j];j++);
        printf("%d ",j);
        isUsed[j] = 1;
    }
}
