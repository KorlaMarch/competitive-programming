#include "stdio.h"
#include "algorithm"
long long int sum,j;
int x[500000],y[500000];
int n,i;
int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d%d",x+i,y+i);
    }
    std::sort(x,x+n);
    std::sort(y,y+n);
    for(i = 1,j = 0; i < n; i++){
        j += (x[i]-x[i-1])*(long long int)i;
        sum += j;
    }
    for(i = 1,j = 0; i < n; i++){
        j += (y[i]-y[i-1])*(long long int)i;
        sum += j;
    }
    printf("%lld\n",sum);
}
