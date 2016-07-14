#include "stdio.h"
#include "vector"
#include "algorithm"
#include "queue"

int n,m,i,j,a,b,sum;
std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<std::pair<int,int>>> qu;
std::pair<int,int> pi;
std::vector<int> edge[100005];
int p[100005];
bool isV[100005];

int main(){
    scanf("%d",&n);
    for(i = 1; i <= n; i++){
        scanf("%d",&p[i]);
    }
    scanf("%d",&m);
    for(i = 0; i < m; i++){
        scanf("%d%d",&a,&b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    qu.push({0,1});
    while(!qu.empty()){
        pi = qu.top();
        qu.pop();
        if(!isV[pi.second]){
            isV[pi.second] = true;
            sum += pi.first;
            for(int x : edge[pi.second]){
                if(!isV[x]){
                    qu.push({p[x]+p[pi.second],x});
                }
            }
        }
    }
    printf("%d\n",sum);
}
