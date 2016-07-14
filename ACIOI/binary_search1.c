#include "stdio.h"
int n,q,i,j,m;
int a[100000];
int bi(int x){
    i=0,j=n-1;
    while(i<=j){
        m=(i+j)/2;
        if(a[m]==x) return m;
        else if(x>a[m]) i = m+1;
        else j = m-1;
    }
    return -1;
}
int main(){
    int k,i;
    scanf("%d",&n);
    for(i = 0; i < n; i++) scanf("%d", &a[i]);
    scanf("%d",&q);
    for(i = 0; i < q; i++){
        scanf("%d",&k);
        printf("%d\n",bi(k));
    }
}
