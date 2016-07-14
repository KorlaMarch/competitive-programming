#include "stdio.h"
#include "vector"

struct tup{
    int u,v,t;
    tup(int _u, int _v, int _t){
        u = _u;
        v = _v;
        t = _t;
    }
};

std::vector<int> edge[20005];
std::vector<std::pair<int,int> > mar,con;
std::vector<tup> ans;
int p1[20005];
int p2[20005];
int n,m,k,i,j,u,v,c;

void dfs(int x, int a){
    p1[x] = a;
    for(auto it : edge[x]){
        if(!p1[it]) dfs(it,a);
    }
}

int unionF(int x){
    return x==p1[x]?x:(p1[x]=unionF(p1[x]));
}
int unionF2(int x){
    return x==p2[x]?x:(p2[x]=unionF2(p2[x]));
}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(i = 0; i < m; i++){
        scanf("%d%d%d",&u,&v,&c);
        if(c){
            edge[u].push_back(v);
            edge[v].push_back(u);
            con.push_back(std::make_pair(u,v));
        }else{
            mar.push_back(std::make_pair(u,v));
        }
    }
    for(i = 1; i <= n; i++){
        if(!p1[i]){
            dfs(i,i);
        }
        p2[i] = i;
    }
    for(auto it : mar){
        if(unionF(it.first)!=unionF(it.second)){
            p1[unionF(it.second)] = unionF(it.first);
            p2[unionF2(it.second)] = unionF2(it.first);
            ans.push_back(tup(it.first,it.second,0));
        }
    }
    for(auto it = mar.begin(); it != mar.end() && ans.size() < k; ++it){
        if(unionF2(it->first)!=unionF2(it->second)){
            p2[unionF2(it->second)] = unionF2(it->first);
            ans.push_back(tup(it->first,it->second,0));
        }
    }
    //printf("%d\n",ans);
    if(ans.size()!=k){
        printf("no solution\n");
    }else{
        for(auto it : con){
            if(unionF2(it.first)!=unionF2(it.second)){
                p2[unionF2(it.second)] = unionF2(it.first);
                ans.push_back(tup(it.first,it.second,1));
            }
        }
        if(ans.size()<n-1){
            printf("no solution\n");
        }else{
            for(auto it : ans){
                printf("%d %d %d\n",it.u,it.v,it.t);
            }
        }
    }
}
