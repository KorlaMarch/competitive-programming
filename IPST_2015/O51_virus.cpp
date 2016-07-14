#include "stdio.h"
#include "algorithm"
int n,i;
int x[200005];
int main(){
    scanf("%d",&n);
    n *= 2;
    for(i = 0; i < n; i++){
        scanf("%d",x+i);
    }
    std::sort(x,x+n);
    printf("%d\n",x[n/2-1]);
}
