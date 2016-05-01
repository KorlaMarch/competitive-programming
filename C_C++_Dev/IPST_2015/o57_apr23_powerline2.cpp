#include "stdio.h"
#include "vector"
#include "queue"
#include "algorithm"

int n,i,j,a,b,v1,v2,mx,t;
int tmp[3];
int p[3][200005];
int deg[200005];
std::vector<int> ed[200005];
std::queue<int> qu;
std::priority_queue<int> pqu[2];
int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d",&p[0][i]);
        if(p[0][i]>mx) mx = p[0][i];
    }
    for(i = 1; i < n; i++){
        scanf("%d%d",&a,&b);
        ed[a].push_back(b);
        ed[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    for(i = 0; i < n; i++){
        if(deg[i]==1) qu.push(i);
    }
    while(!qu.empty()){
        t = qu.front();
        qu.pop();
        deg[t] = 0;
        while(!pqu[0].empty()) pqu[0].pop();
        pqu[0].push(0); pqu[0].push(0); pqu[0].push(0);
        while(!pqu[1].empty()) pqu[1].pop();
        pqu[1].push(0); pqu[1].push(0);
        for(int i : ed[t]){
            if(deg[i]>1){
                deg[i]--;
                if(deg[i]==1){
                    qu.push(i);
                }
            }else if(deg[i]==0){
                pqu[0].push(p[1][i]);
                pqu[1].push(p[2][i]);
                //printf("PU %d %d %d\n",i,p[1][i],p[2][i]);
            }
        }
        v1 = p[0][t];
        for(i = 0; i < 3; i++){
            tmp[i] = pqu[0].top();
            v1 += tmp[i];
            pqu[0].pop();
        }
        p[2][t] = p[0][t]+tmp[0]+tmp[1];

        tmp[0] = pqu[1].top();
        pqu[1].pop();
        tmp[1] = pqu[1].top();
        v2 = p[0][t]+tmp[0]+tmp[1];
        p[1][t] = p[0][t]+tmp[0];
        if(v1>mx) mx = v1;
        if(v2>mx) mx = v2;
        p[2][t] = std::max(p[1][t],p[2][t]);
        //printf("%d:%d %d\n",t,v1,v2);
    }
    printf("%d\n",mx);
}
