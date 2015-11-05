#include "stdio.h"
#include "vector"
#include "algorithm"
int n,i,j,u,v,minD=2000000000;
int x[100005];
std::vector<int> ga,gb;
char isV[100005];
std::vector<int> edge[100005];
void dfs(int x){
    isV[x] = 1;
    for(std::vector<int>::iterator it = edge[x].begin(); it != edge[x].end(); ++it){
        if(!isV[*it]) dfs(*it);
    }
}
bool cmp(int a, int b){
    return x[a]<=x[b];
}
int abs(int n){
    return n<0?-n:n;
}
int main(){
    scanf("%d",&n);
    for(i = 1; i <= n; i++){
        scanf("%d",&x[i]);
    }
    for(i = 2; i < n; i++){
        scanf("%d%d",&u,&v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1);
    for(i = 1; i <= n; i++){
        if(isV[i]){
            ga.push_back(x[i]);
        }else{
            gb.push_back(x[i]);
        }
    }
    std::sort(ga.begin(),ga.end());
    std::sort(gb.begin(),gb.end());
    for(unsigned int i=j=0;i+1<ga.size()||j+1<gb.size();){
        if(abs(ga[i]-gb[j])<minD) minD = abs(ga[i]-gb[j]);
        if(j+1<gb.size()&&abs(ga[i]-gb[j+1])<minD) minD = abs(ga[i]-gb[j+1]);
        if(j+1<gb.size()&&(i+1>=ga.size()||gb[j]<ga[i])) j++;
        else i++;
    }
    if(abs(ga[ga.size()-1]-gb[gb.size()-1])<minD) minD = abs(ga[ga.size()-1]-gb[gb.size()-1]);
    for(unsigned int i=j=0;i+1<ga.size()||j+1<gb.size();){
        if(abs(ga[i]-gb[j])<minD) minD = abs(ga[i]-gb[j]);
        if(i+1<ga.size()&&abs(ga[i+1]-gb[j])<minD) minD = abs(ga[i+1]-gb[j]);
        if(i+1<ga.size()&&(j+1>=gb.size()||ga[i]<gb[j])) i++;
        else j++;
    }
    printf("%d\n",minD);
}
