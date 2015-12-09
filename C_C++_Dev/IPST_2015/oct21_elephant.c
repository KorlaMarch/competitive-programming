#include "stdio.h"
int max(int a, int b){
    return a>b?a:b;
}
int n,i;
int ban[100001],mxb[100001];
int main(){
    scanf("%d",&n);
    for(i = 1; i <= n; i++){
        scanf("%d",&ban[i]);
    }
    for(i = 3; i <= n; i++){
        mxb[i] = max(mxb[i-3]+ban[i],mxb[i-1]);
    }
    printf("%d\n",mxb[n]);
}
