#include "stdio.h"
#include "vector"
#include "algorithm"

int n,k,q,x,d,a,b,i,j;
int uni[200005],p[200005],fen[200005],dis[200005];
std::vector<int> u[200005];
int unionfind(int x){
    if(uni[x]==x) return x;
    else return uni[x] = unionfind(uni[x]);
}
void fenAdd(int i,int v){
    for(;i<=n;i+=(i&-i)){
        fen[i] += v;
    }
}
int fenGet(int i){
    int sum = 0;
    for(;i>=0;i-=(i&-i)){
        sum += fen[i];
    }
    return sum;
}
int main(){
    scanf("%d%d%d",&n,&k,&q);
    for(i = 1; i <= k; i++){
        scanf("%d",&x);
        fenAdd(i,x);
        uni[i] = i;
    }
    for(;i <= n; i++){
        scanf("%d%d",&x,&d);
        p[i] = x;
        dis[i] = d;
    }
}
