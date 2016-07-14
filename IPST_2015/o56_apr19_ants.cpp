#include "stdio.h"
#include "vector"
#include "algorithm"
#include "unordered_map"
#include "set"
#include "queue"

long long getLong(int x, int y){
    return (1000000LL*x)+y;
}

int m,l,i,j,x1,yi1,x2,y2,wi,co,u,v,maxFlow,t;
std::unordered_map<long long,int> mp;
std::set<int> ans;
std::vector<std::pair<int,int> > edge[200005];
std::queue<int> qu;
int isV[200005];
int main(){
    co=3;
    scanf("%d%d",&m,&l);
    for(i = 0; i < m; i++){
        scanf("%d%d%d%d%d",&x1,&yi1,&x2,&y2,&wi);
        if(x1==0) u = 1;
        else if(x1==l) u = 2;
        else u = mp[getLong(x1,yi1)];

        if(x2==0) v = 1;
        else if(x2==l) v = 2;
        else v = mp[getLong(x2,y2)];

        if(u==0){
            mp[getLong(x1,yi1)] = u = co++;
        }
        if(v==0){
            mp[getLong(x2,y2)] = v = co++;
        }
        edge[u].push_back({v,wi});
        edge[v].push_back({u,wi});
    }
    //BFS from 1 to 2
    for(i = 0; i < edge[1].size(); i++){
        if(!isV[edge[1][i].first]){
            isV[edge[1][i].first] = i+1;
            qu.push(edge[1][i].first);
        }
    }
    while(!qu.empty()){
        t = qu.front();
        qu.pop();
        //printf(":%d\n",t);
        for(i = 0; i < edge[t].size(); i++){
            if(edge[t][i].first==2){
                ans.insert(isV[t]);
            }else if(!isV[edge[t][i].first]){
                isV[edge[t][i].first] = isV[t];
                qu.push(edge[t][i].first);
            }
        }
    }
    printf("%d\n",ans.size());
}
