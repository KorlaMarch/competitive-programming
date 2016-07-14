#include "stdio.h"
int factTo(int n, int r){
    if(n<=r) return 1;
    return n*factTo(n-1,r);
}
int c(int n, int r){
    return factTo(n,n-r)/factTo(r,1);
}
int main(){
    int n,k,l,i,j;
    scanf("%d%d%d",&n,&k,&l);
    for(i = 0, j = 1; i < k && j <= n; i++,j++){
        for(;j<n&&l>c(n-j,k-i-1);j++){
            l -= c(n-j,k-i-1);
        }
        printf("%d ",j);
    }
}
