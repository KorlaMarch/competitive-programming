#include "stdio.h"
#include "vector"
#include "algorithm"

struct event{
    int ci,ti,di;
    event(int _ci = 0, int _ti = 0, int _di = 0) : ci(_ci), ti(_ti), di(_di) {}
};

int n,m,i,j,u,v,t,c,d1,d2;
std::vector<int> edge[100005];
std::vector<event> ev[100005];
std::vector<int> ts[100005];
std::vector<int> cycle;
std::vector<int> sp[100005][19];
bool isV[100005];
int cyin[100005];
int fin[100005];
int p[100005],g[100005],d[100005];
bool isB[100005];
int ans;

bool findCy(int x, int o){
    isV[x] = true;
    for(int ed : edge[x]){
        if(ed!=o){
            if(isV[ed]){
                cyin[x] = x.size();
                cycle.push_back(x);
                isV[ed] = false;
                return true;
            }else{
                if(findCy(ed,x)){
                    cyin[x] = x.size();
                    cycle.push_back(x);
                    return isV[x];
                }
            }
        }
    }
    return false;
}

void initT(int x, int o, int fp, int dep){
    p[x] = o;
    g[x] = fp;
    d[x] = dep;
    fin[x] = ts[fp].size();
    ts[fp].push_back(dep);
    for(int y : edge[x]){
        if(y!=o){
            initT(y,x,fp,dep+1);
            ts[fp].push_back(dep);
        }
    }
}

void genSp(int gu){
    int i,j,si=ts[gu].size(),x;
    for(j = 0; j < si; j++){
        sp[gu][0].push_back(ts[gu][j]);
    }
    for(i = 1; (1<<i)<=si; i++){
        x = (1<<(i-1));
        for(j = 0; j+x < sp[gu][i-1].size(); j++){
            sp[gu][i].push_back(std::max(sp[gu][i-1][j],sp[gu][i-1][j+x]));
        }
    }
}

int rmq(int gu, int u, int v){
    int i;
    for(i = 0; (1<<i)<(v-u+1); i++);
    i--;
    return std::max(sp[gu][i][u],sp[gu][i][v-(1<<i)]);
}

int lca(int u, int v){
    u = fin[u];
    v = fin[v];
    if(u<v) return rmq(g[u],u,v);
    else return rmq(g[u],v,u);
}

void setB(int x, int cm){
    for(; d[x] != cm; x = p[x]){
        if(c==0){
            if(!isB[x]) sum++;
        }else{
            if(isB[x]) sum--;
        }
        isB[x] = !c;
    }
}

int main(){
    int cm;
    scanf("%d%d",&n,&m);
    for(i = 1; i <= n; i++){
        scanf("%d%d",&u,&v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    //detect a cycle
    findCy(1,-1);
    for(int x : cycle){
        //printf("%d ",x);
        p[x] = g[x] = x;
        d[x] = 0;
        fin[x] = 0;
        ts[x].push_back(0);
        for(int y : edge[x]){
            if(!isCy[y]){
                initT(y,x,x,1);
                ts[x].push_back(0);
            }
        }
        genSp(x);
    }
    for(t = 0; t < m; t++){
        scanf("%d%d%d",&u,&v,&c);
        if(g[u]==g[v]){
            cm = lca(u,v);
            /*ev[u].push_back(event(t,c,cm));
            ev[v].push_back(event(t,c,cm));*/
            setB(u,cm);
            setB(v,cm);
        }else{
            /*ev[u].push_back(event(t,c,0));
            ev[v].push_back(event(t,c,0));*/
            setB(u,0);
            setB(v,0);
            u = cyin[fin[u]];
            v = cyin[fin[v]];
            if(v<u) std::swap(u,v);
            d1 = (v-u);
            d2 = (u+cycle.size()-v);
            if(d1>=d2){
                for(i = 0; i < n; i++){

                }
            }
            if(d1<=d2){

            }
        }
        printf("%d\n",ans);
    }
}
