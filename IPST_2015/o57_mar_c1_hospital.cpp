#include "stdio.h"
#include "algorithm"
#include "queue"
#include "vector"
#define X first
#define Y second

std::vector<int> edge[100005];
std::vector<int> qu;
int deg[100005];
int n,i,j,a,b;

int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d%d",&a,&b);
        edge[a].push_back(b);
        edge[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    for(i = 0; i < n; i++){
        if(deg[i]==1){
            qu.push_back(i);
        }
    }

}
