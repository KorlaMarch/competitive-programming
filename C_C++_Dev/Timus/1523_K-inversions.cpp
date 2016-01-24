#include "stdio.h"

int n,k,i,j;
long long fen[11][20005];
int v[20005];
long long co;
void addfen(int in, int i, int v){
    for(;i<=n;i+=(i&-i)) fen[in][i] += v;
}
int getFen(int in, int i){
    long long x;
    for(x=0;i>0;i-=(i&-i)) x = (x+fen[in][i])%1000000000;
    return x;
}
int main(){
    scanf("%d%d",&n,&k);
    for(i = 0; i < n; i++){
        scanf("%d",&v[i]);
    }
    addfen(0,1,1);
    for(i = n-1; i >= 0; i--){
        addfen(1,v[i],1);
        for(j = 2; j <= k; j++){
            addfen(j,v[i],getFen(j-1,v[i]-1));
        }
    }
    printf("%d\n",getFen(k,n));
}
