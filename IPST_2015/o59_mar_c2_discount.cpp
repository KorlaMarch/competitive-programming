#include "stdio.h"
#include "vector"
#include "queue"
#include "algorithm"
#include "set"
#include "map"

struct pos{
    int s,t,c;
    pos(int _s = 0, int _t = 0, int _c = 0) : s(_s), t(_t), c(_c) {}
    bool operator()(pos a, pos b){
        return a.c>b.c;
    }
};
bool cmp(pos a, pos b){
    return a.s<b.s;
}

std::vector<pos> unused;
std::vector<std::pair<int,int> > edge[20005];
std::vector<std::pair<int,int> > mst[20005];
std::priority_queue<pos,std::vector<pos>,pos> prim;
std::vector<std::pair<int,int> >::iterator oit;
std::multiset<int> setC[20005];
std::multimap<int,int> ver[20005];
std::queue<int> zq;
int deg[20005];
pos t;
int n,m,i,j,a,b,c,ans,st;
bool isV[20005];
int path[20005];

int minZ(int a, int b){
    if(a==0) return b;
    else if(b==0) return a;
    else return a<b?a:b;
}

void dfs(int x, int o, int mxc, int so){
    path[x] = mxc;
    for(auto it = mst[x].begin(); it != mst[x].end(); ++it){
        if(it->first != o){
            dfs(it->first,x,std::max(mxc,it->second),so);
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(i = 0; i < m; i++){
        scanf("%d%d%d",&a,&b,&c);
        edge[a].push_back({b,c});
        edge[b].push_back({a,c});
    }
    //find mst
    isV[0] = true;
    for(i = 0; i < edge[0].size(); i++){
        prim.push(pos(0,edge[0][i].first,edge[0][i].second));
    }
    while(!prim.empty()){
        t = prim.top();
        prim.pop();
        if(!isV[t.t]){
            isV[t.t] = true;
            mst[t.t].push_back({t.s,t.c});
            mst[t.s].push_back({t.t,t.c});
            for(i = 0; i < edge[t.t].size(); i++){
                if(!isV[edge[t.t][i].first]){
                    prim.push(pos(t.t,edge[t.t][i].first,edge[t.t][i].second));
                }
            }
        }else{
            /*if(t.t<t.s) unused.push_back(pos(t.t,t.s,t.c));
            else unused.push_back(pos(t.s,t.t,t.c));*/
            unused.push_back(pos(t.t,t.s,t.c));
            unused.push_back(pos(t.s,t.t,t.c));
        }
    }
    std::sort(unused.begin(),unused.end(),cmp);
    //start bfs
    ans = 10000000;
    /*for(i=st=0; i < n; i++){
        if(unused[st].s==i){
            dfs(i,-1,0,i);
            while(unused[st].s==i){
                ans = std::min(ans,unused[st].c-path[unused[st].t]+1);
                st++;
            }
        }
    }*/
    for(i = 0; i < n; i++){
        deg[i] = mst[i].size();
        isV[i] = false;
        if(deg[i]<=1){
            zq.push(i);
        }
    }
    while(!zq.empty()){
        i = zq.front();
        zq.pop();
        isV[i] = true;
        for(auto it = std::lower_bound(unused.begin(),unused.end(),pos(i,0,0),cmp); it != unused.end() && it->s == i; ++it){
            setC[i].insert(it->c);
            ver[i].insert({it->t,it->c});
        }
        for(auto it = ver[i].lower_bound(i); it != ver[i].end() && it->first == i; it++){
            setC[i].erase(setC[i].lower_bound(it->second));
        }
        ver[i].erase(i);
        for(auto it = mst[i].begin(); it != mst[i].end(); ++it){
            if(!isV[it->first]){
                ans = std::min(ans,(*setC[i].begin())-it->second+1);
                for(auto it2 = ver[i].begin(); it2 != ver[i].end(); ++it2){
                    setC[it->first].insert(it2->second);
                    ver[it->first].insert(*it2);
                }
                deg[it->first]--;
                if(deg[it->first]<=1) zq.push(it->first);
                break;
            }
        }
    }
    printf("%d\n",ans);
}
