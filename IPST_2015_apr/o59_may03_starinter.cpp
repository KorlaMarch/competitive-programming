#include "stdio.h"
#include "vector"
#include "algorithm"
#include "queue"

int n,k,i,j,a,b,c,x;
std::vector<std::pair<int,int>> edge[200005];
int deg[200005];
std::vector<int> dis[200005];
std::vector<int> tmp;
long long sum,sum2;

void calDis(int ind, int x, int o, int d){
    dis[ind].push_back(d);
    if(edge[x][0].first!=o) calDis(ind,edge[x][0].first,x,d+edge[x][0].second);
    else if(edge[x].size()>=2) calDis(ind,edge[x][1].first,x,d+edge[x][1].second);
}

void calsubsum(int ind){
    int i;
    for(i = 0; i < dis[ind].size(); i++){
        sum += (std::upper_bound(dis[ind].begin(),dis[ind].end(),k+dis[ind][i])-dis[ind].begin())-i-1;
    }
}

void calmainsum(int ind, int n){
    int i,j;
    if(n<2) return;
    else{
        calmainsum(ind,n/2);
        calmainsum(ind+n/2,n-n/2);
        if(dis[ind].size()<=dis[ind+n/2].size()){
            for(int x : dis[ind]){
                sum2 += std::upper_bound(dis[ind+n/2].begin(),dis[ind+n/2].end(),k-x)-dis[ind+n/2].begin();
            }
        }else{
            for(int x : dis[ind+n/2]){
                 sum2 += std::upper_bound(dis[ind].begin(),dis[ind].end(),k-x)-dis[ind].begin();
            }
        }
        tmp.resize(dis[ind].size()+dis[ind+n/2].size());
        std::merge(dis[ind].begin(),dis[ind].end(),dis[ind+n/2].begin(),dis[ind+n/2].end(),tmp.begin());
        dis[ind].resize(tmp.size());
        std::copy(tmp.begin(),tmp.end(),dis[ind].begin());
    }
}

int main(){
    scanf("%d%d",&n,&k);
    for(i = 1; i < n; i++){
        scanf("%d%d%d",&a,&b,&c);
        edge[a].push_back({b,c});
        edge[b].push_back({a,c});
        deg[a]++;
        deg[b]++;
    }
    for(i = 1, c = 0; i <= n; i++){
        if(deg[i]>2){
            c = i;
        }else if(deg[i]==1){
            x = i;
        }
    }
    if(c){
        for(i = 0; i < edge[c].size(); i++){
            calDis(i,edge[c][i].first,c,edge[c][i].second);
            calsubsum(i);
            sum += std::upper_bound(dis[i].begin(),dis[i].end(),k)-dis[i].begin();
        }
        calmainsum(0,edge[c].size());
        printf("%lld\n",sum+sum2);
    }else{
        calDis(0,x,-1,0);
        calsubsum(0);
        printf("%lld\n",sum);
    }
}
