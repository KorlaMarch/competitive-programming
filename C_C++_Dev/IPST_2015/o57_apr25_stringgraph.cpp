#include "stdio.h"
#include "queue"
#include "string.h"
int t,n,m,k,i,j,a,c1,c2;
char s[505][10];
int edge[505][2];
bool isW[505],isV[505];
int le[505][2005];
char p[2005];

void findAns(int x){
    int i,j;
    if(isV[x]) return;
    isV[x] = true;
    if(isW[x]){
        for(i = 0; p[i]; i++){
            le[x][i] = i;
            for(j = 0; s[x][j]; j++){
                if(p[le[x][i]]==s[x][j]){
                    le[x][i]++;
                }
            }
        }
    }else{
        findAns(edge[x][0]);
        findAns(edge[x][1]);
        for(i = 0; p[i]; i++){
            le[x][i] = le[edge[x][1]][le[edge[x][0]][i]];
        }
    }
    le[x][i] = i;
}

int main(){
    for(scanf("%d",&t); t > 0; t--){
        scanf("%d%d",&n,&m);
        for(i = 0; i < n; i++){
            scanf("%d",&a);
            scanf("%d %d", &edge[a][0], &edge[a][1]);
            isW[a] = false;
        }
        for(i = 0; i < m; i++){
            scanf("%d",&a);
            scanf(" %s", s[a]);
            isW[a] = true;
        }
        scanf("%d %s", &k, p);
        n += m;
        for(i = 0; i <= n; i++){
            isV[i] = false;
        }
        findAns(k);
        if(le[k][0]!=strlen(p)) printf("NO\n");
        else printf("YES\n");
    }
}
