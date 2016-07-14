#include "stdio.h"
#include "queue"
#include "vector"
#include "algorithm"
using namespace std;
struct line{
    int u,v,d;
    bool operator()(line a, line b){
        return a.d>b.d;
    }
};
line getLine(int u, int v, int d){
    line tmp;
    tmp.u = u;
    tmp.v = v;
    tmp.d = d;
    return tmp;
}
int n,t,i,j,rt;
int lag[301][301];
int p[301];
vector<pair<int,int>> edge[301];
priority_queue<line,vector<line>,line> qu;
line tmp;
int union_find(int x){
    if(p[x]==x) return x;
    else return p[x]=union_find(p[x]);
}
int main(){
    scanf("%d%d",&n,&t);
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            scanf("%d",&lag[i][j]);
            if(i!=j){
                qu.push(getLine(i,j,lag[i][j]));
            }
        }
    }
    for(i = 0; i <= n; i++){
        p[i] = i;
    }
    for(i = 1; i < n; i++){
        do{
            tmp = qu.top();
            qu.pop();
        }while(union_find(tmp.u)==union_find(tmp.v));
        p[union_find(tmp.v)] = p[tmp.u];
        edge[tmp.u].push_back(make_pair(tmp.v,tmp.d));
        edge[tmp.v].push_back(make_pair(tmp.u,tmp.d));
    }
    for(i = 1; i <= n; i++){
        if(edge[i].size()>=3){
            rt = i;
            break;
        }
    }
    printf("%d\n",rt);
    if(t==2){
        printf("%d\n",edge[rt].size());
    }
}
