#include "stdio.h"
#include "map"
#include "list"
#include "queue"

int maxV(int a, int b){
    return a>b?a:b;
}

int n,m,k,i,u,v,gv;
int vi[100001];
char isV[100001];
std::map<int,int> mv;
std::list<int> adjL[100001];
std::queue<int> q[2];
int main(){
    scanf("%d %d %d",&n,&m,&k);
    for(i = 0; i < n; i++){
        scanf("%d",vi+i);
        if(mv.count(vi[i])) mv[vi[i]]++;
        else mv.insert(std::pair<int,int>(vi[i],1));
    }
    for(i = 0; i < m; i++){
        scanf("%d %d",&u,&v);
        adjL[u-1].push_back(v-1);
        adjL[v-1].push_back(u-1);
    }
    q[0].push(k-1);
    isV[k-1] = 1;
    for(i = 0; !q[i].empty(); i=!i){
        while(!q[i].empty()){
            u = q[i].front();
            mv[vi[u]]--;
            //printf("ea %d %d = %d\n",u+1,vi[u],mv[vi[u]]);
            if(!mv[vi[u]]) mv.erase(vi[u]);
            q[i].pop();
            for(auto it = adjL[u].begin(); it != adjL[u].end(); it++){
                if(!isV[*it]){
                    //printf("ins %d\n",*it+1);
                    q[!i].push(*it);
                    isV[*it] = 1;
                }
            }
        }
        if(!mv.empty()) gv += maxV((*(--mv.end())).first,0);
        //printf("GV = %d\n",gv);
    }
    printf("%d\n",gv);
}
