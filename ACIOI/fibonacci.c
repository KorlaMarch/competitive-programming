#include "stdio.h"
int t,n,i,j;
int fi[5000001];
int main(){
    scanf("%d",&t);
    for(j=fi[0]=0,fi[1]=1,i=2;j<t;j++){
        scanf("%d",&n);
        for(;i<=n;i++) fi[i] = (fi[i-1]+fi[i-2])%1000000007;
        printf("%d\n",fi[n]);
    }
}
