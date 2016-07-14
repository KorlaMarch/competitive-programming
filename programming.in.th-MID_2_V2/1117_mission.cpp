#include "stdio.h"
#include "algorithm"

int n,j,a,b;
long long int sum,i;
int v[100000];
int main(){
    scanf("%d",&n);
    for(j = 0; j < n; j++){
        scanf("%d%d",&a,&b);
        v[j] = b-a*2;
    }
    std::sort(v,v+n);
    for(i = n-1; i >= 0 && i*i-v[i]<(i+1)*(i+1); i--){
        sum += v[i];
    }
    printf("%lld\n",sum-(i+1)*(i+1));
}
