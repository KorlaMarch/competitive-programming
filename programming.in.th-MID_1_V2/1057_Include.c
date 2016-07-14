#include "stdio.h"
int n,k,i,j,a;
char isVisit[1000];
char adjM[1000][1000];

int dfs(int p){
     int i;
     isVisit[p] = 1;
     for(i = 0; i < n; i++){
        if(adjM[p][i]){
            if(isVisit[i]) return 1;
            else if(dfs(i)) return 1;
        }
     }
     return 0;
}

int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d",&k);
        for(j = 0; j < k; j++){
            scanf("%d", &a);
            adjM[i][a-1] = 1;
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++) isVisit[j] = 0;
        if(dfs(i)) printf("YES\n");
        else printf("NO\n");
    }
}
