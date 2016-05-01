#include "stdio.h"
#include "vector"

int n,q,i,j,pi,x,y,b;
std::vector<int> child[100005];
int a[100005];
long long sol[100005];
int dep[200005];
int nc[200005];
std::vector<std::pair<int,int> > qu[100005];
std::vector<int> tmp[100005];
void treeDFS(int x, int p, int d){
    long long sum = dep[d]+a[x];
    int i,j;
    nc[d]++;
    i = 0;
    for(auto v : qu[x]){
        dep[d+v.first] += v.second;
        tmp[x][i] = nc[d+v.first];
        i++;
    }
    for(int v : child[x]){
        treeDFS(v,x,d+1);
    }
    i = 0;
    for(auto v : qu[x]){
        dep[d+v.first] -= v.second;
        sum += (nc[d+v.first]-tmp[x][i])*(long long)(-v.second);
        i++;
    }
    sol[x] = sum;
}

int main(){
    scanf("%d%d",&n,&q);
    for(i = 0; i < n; i++){
        scanf("%d%d",&pi,&a[i]);
        if(pi!=-1) child[pi].push_back(i);
    }
    for(i = 0; i < q; i++){
        scanf("%d%d%d",&x,&y,&b);
        qu[x].push_back({y,b});
        tmp[x].push_back(0);
    }
    treeDFS(0,-1,0);
    for(i = 0; i < n; i++){
        printf("%lld\n",sol[i]);
    }
}
