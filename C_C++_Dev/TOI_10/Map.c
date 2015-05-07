/*
LANG: C
*/
#include "stdio.h"

int m,n,i,j,k,lim,topleft;
int minI,minJ,minP=1;
char c;
int u[40001],d[40001],r[40001],l[40001];
char visit[40001];
int map[200][200];

void getTopLeft(int p,int relaI,int relaJ){
    visit[p] = 1;
    if(relaI<minI||(relaI==minI&&relaJ<minJ)){
        minI = relaI;
        minJ = relaJ;
        minP = p;
    }
    if(u[p]&&!visit[u[p]]) getTopLeft(u[p],relaI-1,relaJ);
    if(d[p]&&!visit[d[p]]) getTopLeft(d[p],relaI+1,relaJ);
    if(l[p]&&!visit[l[p]]) getTopLeft(l[p],relaI,relaJ-1);
    if(r[p]&&!visit[r[p]]) getTopLeft(r[p],relaI,relaJ+1);
}

void makeMap(int p, int i, int j){
    if(i<0||j<0||i>=m||j>=n) return;
    map[i][j] = p;
    visit[p] = 0;
    if(u[p]&&visit[u[p]]) makeMap(u[p],i-1,j);
    if(d[p]&&visit[d[p]]) makeMap(d[p],i+1,j);
    if(l[p]&&visit[l[p]]) makeMap(l[p],i,j-1);
    if(r[p]&&visit[r[p]]) makeMap(r[p],i,j+1);
}

int main(){
    scanf("%d%d",&m,&n);
    lim = m*n-1;
    for(k = 1; k <= lim; k++){
        scanf(" %d %c %d", &i, &c, &j);
        if(c=='U'){
            u[j+1] = i+1;
            d[i+1] = j+1;
        }else{
            l[j+1] = i+1;
            r[i+1] = j+1;
        }
    }
    getTopLeft(1,0,0);
    makeMap(minP,0,0);
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            printf("%d ", map[i][j]-1);
        }
        printf("\n");
    }
}
