#include "stdio.h"
#include "algorithm"
typedef struct{
    int u,v,d;
}edge;
bool cmp(edge a, edge b){
    return a.d<=b.d?true:false;
}
int n,m,i,u,v,d,mx;
int parent[100001];
unsigned char h[100001];
edge ed[1000000],t;
int getParent(int a){
    while(parent[a]) a = parent[a];
    return a;
}
int unionS(int x, int y){
    x = getParent(x);
    y = getParent(y);

    if(x!=y){
        if(h[x]>h[y]) parent[y] = x;
        else if(h[x]<h[y]) parent[x] = y;
        else{
            parent[y] = x;
            h[x]++;
        }
        return 1;
    }else return 0;
}
int main(){
    scanf("%d %d",&n,&m);
    for(i = 0; i < m; i++){
        scanf("%d %d %d", &ed[i].u, &ed[i].v, &ed[i].d);
    }
    std::sort(ed,ed+m,cmp);
    for(i = 0; i < m; i++){
        t = ed[i];
        if(unionS(t.u,t.v)){
            printf("%d %d\n",t.u,t.v);
        }
    }
}
