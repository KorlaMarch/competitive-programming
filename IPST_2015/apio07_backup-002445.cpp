#include "stdio.h"
#include "algorithm"

using namespace std;
int n,k,i,j;
int s[100005];
int dyn[4][100005];
int main(){
    scanf("%d%d",&n,&k);
    for(i = 1; i <= n; i++){
        scanf("%d",&s[i]);
    }
    for(j = 1; j <= k; j++){
        dyn[0][j] = dyn[1][j] = 1000000000;
    }
    for(i = 2; i <= n; i++){
        for(j = 1; j <= k; j++){
            dyn[i%4][j] = min(dyn[(i+3)%4][j],dyn[(i+2)%4][j-1]+s[i]-s[i-1]);
        }
    }
    printf("%d\n",dyn[n%4][k]);
}
