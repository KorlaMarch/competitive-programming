#include "stdio.h"

#define INF 1000000000005LL

int n,b,e,i,j,k;
long long minC[105][105];

int main(){
    scanf("%d%d%d",&n,&b,&e);
    for(i = n-1; i >= 0; i--){
        for(j = i+1; j < n; j++){
            minC[i][j] = INF;
            for(k = i+1; k < j; k++){
                minC[i][j] = std::min(minC[i][j],e+std::max(b+minC[i][k-1],minC[k][j]));
            }
        }
    }
    printf()
}
