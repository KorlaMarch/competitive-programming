#include "stdio.h"
#include "algorithm"
#include "vector"
#include "queue"
#include "unordered_map"

int getIndex(int x, int y){
    return 31*x+y+2;
}

int getIndex2(int x, int y){
    return 1000*x+y;
}

int n,i,j,sc,t,maxF;
char mp[30][30];
int sli[100],eli[100];
int dis[1000];
// 0 = S 1 = T
std::vector<int> edge[1000];
std::vector<int> inv[1000];
std::unordered_map<int,int> flow;
std::queue<int> qu;

void pushNode(int u, int v){
    edge[u].push_back(v);
    flow[getIndex2(u,v)] = 1;
    edge[v].push_back(u);
    flow[getIndex2(v,u)] = 0;
    //printf("SET FLOW 2 : %d %d\n",getIndex2(u,v),getIndex2(v,u));
}

int getFlow(int u, int v){
    return flow[getIndex2(u,v)];
}

void dfs(int x){
    int i;
    if(x==0) return;
    //printf("DFS %d\n",x);
    for(i = 0; i < edge[x].size(); i++){
        if(dis[x]-1==dis[edge[x][i]]&&getFlow(edge[x][i],x)>0){
            flow[getIndex2(x,edge[x][i])] = 1;
            //printf("SET FLOW %d %d\n",getIndex2(x,edge[x][i]),getIndex2(edge[x][i],x));
            flow[getIndex2(edge[x][i],x)] = 0;
            dfs(edge[x][i]);
            return;
        }
    }
}

int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf(" %s",mp[i]);
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(mp[i][j]=='#'){
                sc++;
                if((i+j)%2){
                    pushNode(getIndex(i,j),1);
                }else{
                    pushNode(0,getIndex(i,j));
                    if(i>0&&mp[i-1][j]=='#'){
                        pushNode(getIndex(i,j),getIndex(i-1,j));
                    }
                    if(j>0&&mp[i][j-1]=='#'){
                        pushNode(getIndex(i,j),getIndex(i,j-1));
                    }
                    if(i+1<n&&mp[i+1][j]=='#'){
                        pushNode(getIndex(i,j),getIndex(i+1,j));
                    }
                    if(j+1<n&&mp[i][j+1]=='#'){
                        pushNode(getIndex(i,j),getIndex(i,j+1));
                    }
                }
            }
        }
    }
    //Maxflow
    while(1){
        //BFS from S
        while(!qu.empty()) qu.pop();
        for(i = 1; i < 1000; i++) dis[i] = 0;
        qu.push(0);
        dis[0] = 1;
        while(!qu.empty()){
            t = qu.front();
            //printf("GET %d\n",t);
            if(t==1){
                break;
            }
            qu.pop();
            for(i = 0; i < edge[t].size(); i++){
                if(!dis[edge[t][i]]&&getFlow(t,edge[t][i])>0){
                    qu.push(edge[t][i]);
                    dis[edge[t][i]] = dis[t]+1;
                    //printf("SET DIS %d %d :%d %d : %d\n",t,edge[t][i],dis[edge[t][i]],dis[t],getIndex2(t,edge[t][i]));
                }
            }
        }
        if(qu.empty()) break;
        dfs(1);
        maxF++;
    }
    if(maxF*2!=sc){
        printf("no solution\n");
    }else{
        //track maxflow and print
        for(i = 0; i < edge[0].size(); i++){
            if(flow[getIndex2(edge[0][i],0)]>0){
                t = edge[0][i];
                for(j = 0; j < edge[t].size(); j++){
                    if(flow[getIndex2(edge[t][j],t)]>0){
                        printf("%d %d %d %d\n",(t-2)/31+1,(t-2)%31+1,(edge[t][j]-2)/31+1,(edge[t][j]-2)%31+1);
                        break;
                    }
                }
            }
        }
    }
}
