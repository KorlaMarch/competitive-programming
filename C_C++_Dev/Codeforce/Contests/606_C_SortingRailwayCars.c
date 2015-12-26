#include "stdio.h"

int n,i,p,mx;
int a[100005];

int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d",&p);
        a[p] = 1+a[p-1];
        if(a[p]>mx) mx = a[p];
    }
    printf("%d\n",n-mx);
}
