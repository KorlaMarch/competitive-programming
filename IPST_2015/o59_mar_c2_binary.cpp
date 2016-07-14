#include "stdio.h"
#include "vector"
#include "queue"
#include "algorithm"

int n,i,j,u,v;
std::vector<int> child[100005];

int dfs(int x, int p){
    int i,a,b;
    std::priority_queue<int,std::vector<int>,std::greater<int> > qu;
    if(child[x].size()==0) return 1;
    else if(child[x].size()==1) return dfs(child[x][0],x)+1;
    for(i = 0; i < child[x].size(); i++){
        qu.push(dfs(child[x][i],x));
    }
    while(qu.size()>1){
        a = qu.top();
        qu.pop();
        b = qu.top();
        qu.pop();
        //printf("%d GET %d %d\n",x,a,b);
        qu.push(std::max(a,b)+1);
    }
    return qu.top();
}

int main(){
    scanf("%d",&n);
    for(i = 1; i < n; i++){
        scanf("%d",&u);
        child[u].push_back(i+1);
    }
    printf("%d\n",dfs(1,-1)-1);
}
