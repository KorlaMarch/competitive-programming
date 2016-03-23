#include "stdio.h"
#include "vector"

int n,k,i,j,a,b,minD,s,e;
int co[6005];
int qx[7000],qkc[7000],qo[7000],qdis[7000];
std::vector<int> edge[6005];

void dfs(int x, int kc, int o, int dis){
    int i;
    kc += co[x];
    if(kc>=k){
        if(dis<minD){
            minD = dis;
        }
        return;
    }else if(dis>=minD){
        return;
    }
    for(i=0;i<edge[x].size();i++){
        if(edge[x][i]!=o){
            dfs(edge[x][i],kc,x,dis+1);
        }
    }
}

int main(){
    minD = 100000;
    scanf("%d%d",&n,&k);
    for(i = 0; i < n; i++){
        scanf("%d",&co[i]);
    }
    for(i = 1; i < n; i++){
        scanf("%d%d",&a,&b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for(i = 0; i < n; i++){
        dfs(i,0,-1,0);
    }
    if(minD==0) printf("1\n");
    else if(minD!=100000) printf("%d\n",minD);
    else printf("-1\n");
}
