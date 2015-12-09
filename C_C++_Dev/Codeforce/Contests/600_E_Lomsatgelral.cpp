#include "stdio.h"
#include "vector"

int n,i;
int c[100005];
std::vector<int> edge[100005];

int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d",&c[i]);
    }
    for(i = 1; i < n; i++){
        scanf("%d",&x,&y);
        edge[x].push_back(y);
        edge[y].push_back(x);
    }

}
