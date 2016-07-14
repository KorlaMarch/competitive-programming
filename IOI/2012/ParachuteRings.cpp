#include "stdio.h"
#include "set"
#include "vector"

int n,l,i,j,a,b,co,fc,tc;
int fr = -1;
int deg[1000005];
std::vector<int> adj[1000005];

bool check(int x){
    int xc = deg[x]==3?1:0;
    for(int ed : adj[x]){
        if(deg[ed]==3) xc++;
    }
    return xc==tc;
}

int main(){
    int ans;
    scanf("%d%d",&n,&l);
    for(i = 0; i < l; i++){
        scanf("%d",&a);
        if(a==-1){
            if(fc>=1){
                if(fr!=-1&&check(fr)) printf("1\n");
                else printf("0\n");
            }else{
                ans = 0;
                for(j = 0; j < n; j++){
                    if(check(j)) ans++;
                }
                printf("%d\n",ans);
            }
        }else{
            scanf("%d",&b);
            deg[a]++;
            deg[b]++;
            adj[a].push_back(b);
            adj[b].push_back(a);
            if(deg[a]==4) fc++;
            else if(deg[a]==3) tc++;

            if(deg[b]==4) fc++;
            else if(deg[b]==3) tc++;

            if(fc>=2){
                fr = -1;
                continue;
            }else if(fc==1){
                if(deg[a]==4){
                    fr = a;
                }else if(deg[b]==4){
                    fr = b;
                }
            }
        }
    }
}
