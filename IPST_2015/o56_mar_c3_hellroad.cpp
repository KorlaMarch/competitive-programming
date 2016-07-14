#include "stdio.h"
#include "algorithm"

struct edge{
    int u,v,w;
};

bool cmp(edge a, edge b){
    return a.w<b.w;
}

int n,m,i,j,x,y,mid;
edge e[1000000];
int p[1005];

int unionF(int x){
    return x==p[x]?x:(p[x]=unionF(p[x]));
}

bool canCreate(int mid){
    int i,j;
    long long c;
    for(i = 1; i <= n; i++) p[i] = i;
    for(c=0,i=mid,j=0; i < n*(n-1)/2; i++){
        if(unionF(e[i].u)!=unionF(e[i].v)){
            p[unionF(e[i].u)] = unionF(e[i].v);
            c += e[i].w;
            j++;
            if(j==n-1){
                return c<=m;
            }
        }
    }
    return false;
}

int main(){
    scanf("%d%d",&n,&m);
    for(i = 0; i < n*(n-1)/2; i++){
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    }
    std::sort(e,e+n*(n-1)/2,cmp);
    for(x = 0,y = n*(n-1)/2-1; x<=y;){
        mid = (x+y)/2;
        if(canCreate(mid)){
            x = mid+1;
        }else{
            y = mid-1;
        }
    }
    printf("%d\n",e[y].w);
}
