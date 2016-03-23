#include "stdio.h"
#include "vector"
#include "algorithm"

int n,m,i,j,a,b;
std::vector<std::pair<int,int> > edge[100005];
int inDeg[100005];
int main(){
    scanf("%d%d",&n,&m);
    for(i = 0; i < m; i++){
        scanf("%d%d",&a,&b);
        edge[a].push_back(b);
        inDeg[b]++;
    }
    for(i = 0; i < m; i++){

    }
}
