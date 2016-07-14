#include "stdio.h"

int main(){
    int n,b,i,x;
    long long unsigned int t = 0;
    scanf("%d%d",&n,&b);
    for(i = 0; i < n; i++){
        scanf("%d", &x);
        t += x;
    }
    if(n>=3) t += (n-2)*m;
    else if(n==1) t = b;
    printf("%llu\n",t);
}
