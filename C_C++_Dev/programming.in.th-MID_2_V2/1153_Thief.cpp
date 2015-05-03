#include "stdio.h"
#include "algorithm"
typedef struct{
    int p,k,v;
}thief;
int n,i,j;
thief th[1000];
int dyn[1001][3];
int spos[1001];
bool cmp(thief a, thief b){
    return a.p==b.p?(a.k<=b.k?true:false):(a.p<b.p?true:false);
}
int max(int a, int b){
    return a>b?a:b;
}
int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d %d %d", &th[i].p, &th[i].k, &th[i].v);
    }
    std::sort(th,th+n,cmp);
    for(i = 0; i < n; i++){
        printf("S:%d :%d %d %d\n",i,th[i].p,th[i].k,th[i].v);
    }
    for(i = j = 0; i <= 1000; i++){
        while(j<n&&th[j].p<i) j++;
        spos[i] = j;
    }
    dyn[spos[th[0].k]][2] = dyn[1][1] = th[0].v;
    for(i = 1; i < n; i++){
        dyn[i][2] = max(dyn[i][2],dyn[i-1][2]);
        dyn[i][1] = max(max(dyn[i][1],dyn[i-1][1]),dyn[i][2]);
        dyn[i][0] = max(max(dyn[i][0],dyn[i-1][0]),dyn[i][1]);
        j = spos[th[i].k];
        dyn[i+1][1] = max(dyn[i+1][1],dyn[i][2]+th[i].v);
        dyn[j][2] = max(dyn[j][2],max(dyn[i][2],dyn[j][1])+th[i].v);
        dyn[i+1][0] = max(dyn[i+1][0],dyn[i][1]+th[i].v);
        dyn[j][1] = max(dyn[j][1],dyn[i][1]+th[i].v);
        printf("I:%d :%d %d %d\n",i,dyn[i][0],dyn[i][1],dyn[i][2]);
    }
    dyn[n][2] = max(dyn[n][2],dyn[n-1][2]);
    dyn[n][1] = max(max(dyn[n][1],dyn[n-1][1]),dyn[n][2]);
    dyn[n][0] = max(max(dyn[n][0],dyn[n-1][0]),dyn[n][1]);
    printf("%d\n",dyn[n][0]);
}
