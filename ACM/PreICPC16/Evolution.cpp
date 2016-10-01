#include <stdio.h>
#include "vector"
#include "algorithm"

int n,a,b;
char isV[1000];
std::vector<int> edge[1000];

bool dfs(int x){
    if(isV[x]==2) return true;
    else if(isV[x]==1) return false; 
    isV[x] = 1;
    for(int i : edge[x]){
        if(!dfs(i)) return false;
    }
    isV[x] = 2;
    return true;
}

int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf(" %d %d",&a,&b);
        edge[a].push_back(b);
    }
    for(int i = 0; i < 1000; i++){
        std::sort(edge[i].begin(),edge[i].end());
        edge[i].resize(std::unique(edge[i].begin(),edge[i].end())-edge[i].begin());
    }
    for(int i = 0; i < 1000; i++){
        for(int j = 0; j < 1000; j++){
            isV[j] = 0;
        }
        if(!dfs(i)){
            //printf("BUG AT %d\n",i);
            printf("BUG\n");
            return 0;
        }
    }
    printf("OK\n");
    return 0;
}
