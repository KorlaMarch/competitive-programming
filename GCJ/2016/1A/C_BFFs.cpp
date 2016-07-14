#include "stdio.h"
#include "vector"

int t,k,n,i,j;
int f[1005];
std::vector<int> lf[1005];
int concom[1005];
int mp[1005];
bool isV[1005];

void dfs(int x, int c){
    if(concom[x]) return;
    concom[x] = c;
    dfs(f[x],c);
    for(int i : lf[x]){
        dfs(i,c);
    }
}

int findMP(int x){
    isV[x] = true;
    findMP[]
}

int main(){
    scanf("%d",&t);
    for(k = 1; k <= t; k++){
        scanf("%d",&n);
        for(i = 0; i < n; i++){
            lf[i].clear();
            concom[i] = 0;
        }
        for(i = 0; i < n; i++){
            scanf("%d",&f[i]);
            lf[f[i]].push_back(i);
        }
        for(i = 0; i < n; i++){
            if(concom[i]==0){
                dfs(i,i+1);
            }
        }
        for(i = 0; i < n; i++){
            //setmp
            for(j = 0; j < n; j++){
                isV[j] = false;
            }
            mp[i] = findMP(i);
        }
    }
}
