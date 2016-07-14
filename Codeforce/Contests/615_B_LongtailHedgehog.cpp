#include "stdio.h"
#include "vector"

int n,m,i,j,u,v,mx;
long long int beau;
std::vector<int> edge[100050];
std::vector<int>::iterator it;
int tailL[100050];

int main(){
    scanf("%d%d",&n,&m);
    for(i = 0; i < m; i++){
        scanf("%d%d",&u,&v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    for(i = 1; i <= n; i++){
        for(it = edge[i].begin(),mx = 0; it != edge[i].end(); ++it){
            if(*it < i && tailL[*it]>mx) mx = tailL[*it];
        }
        tailL[i] = mx+1;
        if(tailL[i]*(long long int)edge[i].size()>beau) beau = tailL[i]*(long long int)edge[i].size();
    }
    printf("%I64d\n",beau);
}
