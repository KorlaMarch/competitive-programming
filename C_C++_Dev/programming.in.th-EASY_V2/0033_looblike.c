#include "stdio.h"

int main(){
    int n,i,m,x,ma;
    int a[10000] = {};
    scanf("%d",&n);
    for(i=m=0;i<n;i++){
        scanf("%d",&x);
        if(x>m) m = x;
        a[x-1]++;
    }
    for(i=ma=0;i<m;i++){
        if(a[i]>ma) ma = a[i];
    }
    for(i=0;i<m;i++){
        if(a[i]==ma) printf("%d ",i+1);
    }
}
