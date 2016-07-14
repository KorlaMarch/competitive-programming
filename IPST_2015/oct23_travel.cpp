#include "stdio.h"
#include "vector"
using namespace std;
int n,m,i,j,a,b,l,sumd,sc,ptr,cl;
vector<int> edge[30002];
int tra[70000],lev[70000],fp[30002];
int sparseT[17][70000];

int min(int a, int b){
    return a<b?a:b;
}
void treeTar(int x, int lv, int p){
    lev[ptr] = lv;
    fp[x] = ptr;
    tra[ptr++] = x;
    for(vector<int>::iterator it = edge[x].begin(); it != edge[x].end(); ++it){
        if(*it != p){
            treeTar(*it,lv+1,x);
            lev[ptr] = lv;
            tra[ptr++] = x;
        }
    }
}
int getMin(int a, int b){
    int i;
    if(b==a) return lev[fp[a]];
    for(i = 0; (1<<i) <= b-a; i++);
    i--;
    return min(sparseT[i][a],sparseT[i][b-(1<<i)+1]);
}
int main(){
    scanf("%d",&n);
    for(i = 1; i < n; i++){
        scanf("%d%d",&a,&b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    ptr = 0;
    treeTar(1,1,-1);
    for(j = 0; j < ptr; j++){
        sparseT[0][j] = lev[j];
    }
    for(i = 1; (1<<i) <= ptr; i++){
        for(j = 0; j+(1<<i) <= ptr; j++){
            sparseT[i][j] = min(sparseT[i-1][j],sparseT[i-1][j+(1<<(i-1))]);
        }
    }
    scanf("%d",&m);
    for(i = 1,sc=1; i <= m; i++){
        scanf("%d",&l);
        if(fp[sc]<=fp[l]) cl = getMin(fp[sc],fp[l]);
        else cl = getMin(fp[l],fp[sc]);
        sumd += (lev[fp[sc]]-cl)+(lev[fp[l]]-cl);
        sc = l;
    }
    printf("%d\n",sumd);
}
