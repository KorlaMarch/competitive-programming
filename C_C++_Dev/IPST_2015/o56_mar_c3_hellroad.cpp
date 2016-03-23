#include "stdio.h"
#include "algorithm"

struct edge{
    int u,v,w;
    edge(int _u, int _v, int _w){
        u = _u;
        v = _v;
        w = _w;
    }
};

int n,m,i,j,l,x,y,m;
edge c[1000050];
edge t;
int p[1005];
bool cmp(edge a, edge b){
    return a.w<b.w;
}

bool canCreate(int s){
    int i;
    for(i = 0; i <= n; i++){

    }
}

int main(){
    scanf("%d%d",&n,&m);
    l = n*(n-1)/2;
    for(i = 0; i < l; i++){
        scanf("%d%d%d",&c[i].u,&c[i].v,&c[i].w);
    }
    std::sort(c,c+l,cmp);
    x = 0; y = l-1;
    while(x<=y){
        m = (x+y)/2;
        if(canCreate(m)){
            x = m+1;
        }else{
            y = m-1;
        }
    }
    printf("%d\n"c[y].w);
}
