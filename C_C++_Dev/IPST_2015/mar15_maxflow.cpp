#include "stdio.h"
#include "vector"
#include "queue"
#include "algorithm"
//#include "maxflow.h"

struct Edge{
    int v,w,u;
};

Edge getEdge(int v, int w, int u){
    Edge t;
    t.v = v;
    t.w = w;
    t.u = u;
    return t;
}

int flow[1005][1005];
std::vector<Edge> adj[1005],inv[1005];
bool isV[1005];

int dfs(int x, int t, int minC, int *f){
    int i,r;
    if(x==t){
        return minC;
    }else{
        isV[x] = true;
        for(i = 0; i < adj[x].size(); i++){
            if(!isV[adj[x][i].w]&&adj[x][i].u-flow[x][adj[x][i].w]>0){
                if(r = dfs(adj[x][i].w,t,std::min(adj[x][i].u-flow[x][adj[x][i].w],minC),f)){
                    flow[x][adj[x][i].w] += r;
                    flow[adj[x][i].w][x] += -r;
                    f[adj[x][i].v] = r;
                    isV[x] = false;
                    return r;
                }
            }
        }
        for(i = 0; i < inv[x].size(); i++){
            if(!isV[inv[x][i].w]&&-flow[x][inv[x][i].w]>0){
                if(r = dfs(inv[x][i].w,t,std::min(inv[x][i].u-flow[x][inv[x][i].w],minC),f)){
                    flow[x][inv[x][i].w] += r;
                    flow[inv[x][i].w][x] += -r;
                    isV[x] = false;
                    return r;
                }
            }
        }
    }
    isV[x] = false;
    return 0;
}

int maxflow(int n, int m, int s, int t, Edge *edges, int *f){
    int i,j,k,sum;
    for(i = 0; i < m; i++){
        adj[edges[i].v].push_back(getEdge(i,edges[i].w,edges[i].u));
        inv[edges[i].w].push_back(getEdge(i,edges[i].v,edges[i].u));
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            flow[i][j] = 0;
        }
    }
    while(1){
        if(!dfs(s,t,10000,f)) break;
    }
    for(i=sum=0; i < n; i++){
        sum += flow[i][t];
    }
    return sum;
}

/*int main(){
    int n,m,s,t,i;
    Edge e[1000];
    int fl[1000];
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(i = 0; i < m; i++){
        scanf("%d%d%d",&e[i].v,&e[i].w,&e[i].u);
    }
    printf("FLOW : %d\n",maxflow(n,m,s,t,e,fl));
    for(i = 0; i < n; i++){
        printf("%d : %d\n",i,fl[i]);
    }
}*/
