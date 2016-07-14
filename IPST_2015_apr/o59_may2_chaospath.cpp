#include "stdio.h"
#include "vector"
#include "queue"

int n,i,j,a,b,x;
long long smx,mx,mx2;
std::vector<int> edge[100005];
int deg[100005];
int nc[100005];
long long ns[100005];
std::queue<int> zq;

int main(){
    scanf("%d",&n);
    for(i = 1; i < n; i++){
        scanf("%d%d",&a,&b);
        edge[a].push_back(b);
        edge[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    for(i = 1; i <= n; i++){
        if(deg[i]==1){
            zq.push(i);
        }
    }
    while(!zq.empty()){
        x = zq.front();
        zq.pop();
        deg[x] = 0;
        nc[x]++;
        mx = mx2 = 0;
        for(int y : edge[x]){
            if(!deg[y]){
                if(ns[y]>=mx){
                    mx2 = mx;
                    mx = ns[y];
                }else if(ns[y]>mx2){
                    mx2 = ns[y];
                }
            }
        }
        if(mx+mx2>smx){
            smx = mx+mx2;
        }
        ns[x] = mx+nc[x]*(long long)(n-nc[x]);
        for(int y : edge[x]){
            if(deg[y]>1){
                nc[y] += nc[x];
                deg[y]--;
                if(deg[y]==1){
                    zq.push(y);
                }
            }
        }
    }
    printf("%lld\n",smx);
}
