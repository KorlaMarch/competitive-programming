#include "stdio.h"
#include "algorithm"

#define INF 1000000000005LL

int n,b,e,i,j,k;
long long minC[1000005];

int main(){
    scanf("%d%d%d",&n,&b,&e);
    for(i = 2; i < n; i++){
        //k = 1
        minC[i] = e+minC[i-1];
        for(int x = 3,y = i-1; x<=y; ){
            int m = (x+y)/2;
            minC[i] = std::min(minC[i],e+std::max(b+minC[m-1],minC[i-m+1]));
            if(b+minC[m-1]<=minC[i-m+1]){
                x = m+1;
            }else{
                y = m-1;
            }
        }
    }
    printf("%lld\n",minC[n-1]);
}
