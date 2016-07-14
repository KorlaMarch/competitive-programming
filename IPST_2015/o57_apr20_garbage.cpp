#include "stdio.h"
#include "algorithm"
#include "vector"

struct edge{
    int u,v,w;
};

bool cmp(edge a, edge b){
    return a.w<b.w;
}

int n,m,q,i,j,s,u,v;
edge ed[100005];
int dep[10005];
int p[10005];
int spW[10005][16];
int spP[10005][16];
int rmq[16][30000];
int fp[10005];
std::vector<std::pair<int,int>> mst[10005];

int unionF(int x){
    return p[x]==x?x:(p[x]=unionF(p[x]));
}

void treeDFS(int x, int o, int d, int w){
    int i;
    p[x] = o;
    dep[x] = d;
    //init spW&spP
    spW[x][0] = w;
    spP[x][0] = o;
    for(i = 1; (1<<i) <= d; i++){
        spW[x][i] = std::max(spW[x][i-1],spW[spP[x][i-1]][i-1]);
        spP[x][i] = spP[spP[x][i-1]][i-1];
    }
    fp[x] = s;
    rmq[0][s++] = d;
    for(auto y : mst[x]){
        if(y.first!=o){
            treeDFS(y.first,x,d+1,y.second);
            rmq[0][s++] = d;
        }
    }
}

void genSPT(){
    int i,j,k;
    for(i = 1,k = 1; 2*k<=s; i++,k*=2){
        for(j = 0; j+2*k <= s; j++){
            rmq[i][j] = std::min(rmq[i-1][j],rmq[i-1][j+k]);
        }
    }
}

int lca(int u, int v){
    int k,i;
    u = fp[u];
    v = fp[v];
    if(u>v){
        k = u;
        u = v;
        v = k;
    }
    for(i = 0, k = 1; 2*k < (v-u+1); i++,k*=2);
    return std::min(rmq[i][u],rmq[i][v-k+1]);
}

int maxW(int x, int pd){
    int d,i,mx=0;
    for(d = dep[x],i = 0; (1<<i)<=d; i++);
    if(i){
        for(i--;d>pd;i--){
            if((1<<i)<d-pd+1){
                mx = std::max(mx,spW[x][i]);
                x = spP[x][i];
                d -= (1<<i);
            }
        }

    }
    return mx;
}

int main(){
    int lc;
    scanf("%d%d",&n,&m);
    for(i = 0; i < m; i++){
        scanf("%d%d%d",&ed[i].u,&ed[i].v,&ed[i].w);
    }
    std::sort(ed,ed+m,cmp);
    for(i = 1; i <= n; i++){
        p[i] = i;
    }
    for(i = 0;  i < m; i++){
        if(unionF(ed[i].u)!=unionF(ed[i].v)){
            p[unionF(ed[i].u)] = unionF(ed[i].v);
            mst[ed[i].u].push_back({ed[i].v,ed[i].w});
            mst[ed[i].v].push_back({ed[i].u,ed[i].w});
        }
    }
    treeDFS(1,0,0,0);
    genSPT();
    scanf("%d",&q);
    for(i = 0; i < q; i++){
        scanf("%d%d",&u,&v);
        lc = lca(u,v);
        printf("%d\n",std::max(maxW(u,lc),maxW(v,lc)));
    }
}
