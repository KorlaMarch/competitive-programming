#include "stdio.h"
#include "algorithm"
int n,i;
long long s,v[2000];
int main(){
    for(scanf("%d",&n),i=0; i < n; i++) scanf("%lld %lld",v+i*2,v+i*2+1);
    std::sort(v,v+n*2);
    for(i=s=0; i < n; i++) s += v[i]*v[n*2-i-1];
    printf("%lld\n",s);
}
