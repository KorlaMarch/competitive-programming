#include "stdio.h"
#include "vector"

#define MOD 1000000007

int n,i,j,k;
long long a[505],b[505];
long long way[505];
long long sum;
std::vector<int> way2[505];
int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%lld%lld",&a[i],&b[i]);
    }

    for(i = 0; i < n; i++){
        way[i] = 1;
        for(j = 0; j < i; j++){
            if(a[i]>a[j]) way[i] = (way[i]+way[j])%MOD;
        }
        sum = (sum+way[i])%MOD;
    }
    printf("%lld\n",sum);
}
