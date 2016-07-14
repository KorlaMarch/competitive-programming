#include "stdio.h"
#include "vector"
#include "stack"

int n,m,i,j,a,b,x;
std::vector<int> edge[200005];
std::stack<int> order;
std::stack<bool> canO;
int p[200005],co[200005];
bool isV[200005];

int unionF(int x){
    return p[x]==x?x:(p[x]=unionF(p[x]));
}

int main(){
    scanf("%d%d",&n,&m);
    for(i = 0; i < m; i++){
        scanf("%d%d",&a,&b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for(i = 1; i <= n; i++){
        scanf("%d",&a);
        order.push(a);
        p[i] = i;
    }
    for(i = 1; !order.empty(); i++){
        x = order.top();
        order.pop();
        isV[x] = true;
        co[unionF(x)]++;
        for(int e : edge[x]){
            if(isV[e]&&unionF(e)!=unionF(x)){
                co[unionF(x)] += co[unionF(e)];
                p[unionF(e)] = unionF(x);
            }
        }
        if(co[unionF(x)]==i) canO.push(true);
        else canO.push(false);
    }
    while(!canO.empty()){
        if(canO.top()) printf("YES\n");
        else printf("NO\n");
        canO.pop();
    }
}
