#include "stdio.h"
#include "vector"
#include "queue"
using namespace std;

int n,m,i,u,v,k;
vector<int> edge[100005];
int g[100005];

bool checkBPT(int x){
    int i,inv;
    queue<int> qu;
    qu.push(x);
    g[x] = 1;
    while(!qu.empty()){
        i = qu.front();
        inv = !(g[i]-1)+1;
        qu.pop();
        for(vector<int>::iterator it = edge[i].begin(); it!=edge[i].end(); ++it){
            if(g[*it]==0){
                g[*it] = inv;
                qu.push(*it);
            }else if(g[i]==g[*it]){
                return false;
            }
        }
    }
    return true;
}
int main(){
    for(scanf("%d",&k);k>0;k--){
        scanf("%d%d",&n,&m);
        for(i = 0; i <= n; i++){
            edge[i].clear();
            g[i] = 0;
        }
        for(i = 0; i < m; i++){
            scanf("%d%d",&u,&v);
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        for(i = 1; i <= n; i++){
            if(!g[i]){
                if(!checkBPT(i)){
                    break;
                }
            }
        }
        if(i==n+1) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
