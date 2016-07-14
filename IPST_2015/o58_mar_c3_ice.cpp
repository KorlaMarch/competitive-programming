#include "stdio.h"
#include "queue"
#include "vector"

struct cmp{
    bool operator()(std::pair<int,int> a, std::pair<int,int> b){
        return a.first==b.first?a.second>b.second:a.first<b.first;
    }
};

int n,m,i,j,u,v,w;
int s[200005];
int p[200005];
bool isV[200005];
std::vector<std::pair<int,int> > edge[200005];
std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,cmp> qu;
std::pair<int,int> t;
int main(){
    scanf("%d%d",&n,&m);
    for(i = 1; i <= n; i++){
        scanf("%d",&s[i]);
        if(s[i]){
            qu.push({s[i],i});
            p[i] = i;
        }
    }
    for(i = 0; i < m; i++){
        scanf("%d%d%d",&u,&v,&w);
        edge[u].push_back({v,w});
        edge[v].push_back({u,w});
    }
    while(!qu.empty()){
        t = qu.top();
        qu.pop();
        //printf("GET %d : %d\n",t.second,t.first);
        //continue;
        if(!isV[t.second]){
            isV[t.second] = true;
            for(auto i : edge[t.second]){
                if(t.first-i.second>s[i.first]){
                    s[i.first] = t.first-i.second;
                    p[i.first] = p[t.second];
                    qu.push({s[i.first],i.first});
                }else if(t.first-i.second==s[i.first]&&p[i.first]>p[t.second]){
                    p[i.first] = p[t.second];
                }
            }
        }
    }
    for(i = 1; i <= n; i++){
        printf("%d %d\n", p[i], s[i]);
    }
}
