#include "stdio.h"
typedef struct{
    short a,b,c,w;
}way;
int n,m,k,s,t,i,j,mx,x;
way w[5000];
char canR[2001][300];
int maxC[2001][300];

int main(){
    scanf("%d%d%d%d%d",&n,&m,&k,&s,&t);
    for(i = 0; i < m; i++){
        scanf("%d%d%d%d",&w[i].a,&w[i].b,&w[i].c,&w[i].w);
        w[i].a--;
        w[i].b--;
    }
    canR[0][s-1] = 1;
    for(i = 1; i <= k; i++){
        for(j = 0; j < m; j++){
            if(i>=w[j].w){
                if(canR[i-w[j].w][w[j].a]){
                    canR[i][w[j].b] = 1;
                    x = maxC[i-w[j].w][w[j].a]+w[j].c;
                    if(x>maxC[i][w[j].b]) maxC[i][w[j].b] = x;
                }
                if(canR[i-w[j].w][w[j].b]){
                    canR[i][w[j].a] = 1;
                    x = maxC[i-w[j].w][w[j].b]+w[j].c;
                    if(x>maxC[i][w[j].a]) maxC[i][w[j].a] = x;
                }
            }
        }
    }
    for(i=mx=x=0; i <= k; i++){
        if(maxC[i][t-1]>mx) mx = maxC[i][t-1];
        if(canR[i][t-1]) x = 1;
    }
    if(x) printf("%d\n",mx);
    else printf("Impossible\n");
}
