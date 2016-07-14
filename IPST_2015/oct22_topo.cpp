#include "stdio.h"
#include "vector"
#include "stack"
using namespace std;

int n,m,i,u,v;
char isV[100005];
bool isC;
vector<int> edge[100005];
stack<int> topo;
void dfs(int x){
    isV[x] = 1;
    for(vector<int>::iterator it = edge[x].begin(); it != edge[x].end() && !isC; ++it){
        if(isV[*it]==1){
            isC = true;
            return;
        }else if(isV[*it]==0){
            dfs(*it);
        }
    }
    isV[x] = 2;
    topo.push(x);
}
int main(){
    scanf("%d%d",&n,&m);
    for(i = 0; i < m; i++){
        scanf("%d%d",&u,&v);
        edge[u].push_back(v);
    }
    for(i = 1; i <= n; i++){
        if(!isV[i]){
            dfs(i);
        }
    }
    if(isC) printf("no\n");
    else{
        while(!topo.empty()){
            printf("%d ",topo.top());
            topo.pop();
        }
    }
    return 0;
}
