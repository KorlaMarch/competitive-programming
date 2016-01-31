#include "stdio.h"
#include "vector"

int n,m,i,rc,a,b;
std::vector<int> edges[100005];
int cat[100005];

void dfs(int x, int p, int c){
    int i;
    if(cat[x]){
        c++;
        if(c>m) return;
    }else{
        c = 0;
    }
    if(edges[x].size()<=1&&edges[x][0]==p){
        rc++;
        return;
    }
    for(i = 0; i < edges[x].size(); i++){
        if(edges[x][i]!=p) dfs(edges[x][i],x,c);
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(i = 1; i <= n; i++){
        scanf("%d",&cat[i]);
    }
    for(i = 1; i < n; i++){
        scanf("%d%d",&a,&b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(1,0,0);
    printf("%d\n",rc);
}
