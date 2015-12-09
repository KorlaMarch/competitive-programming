#include "stdio.h"
#include "algorithm"
struct job{
    int s,t,w;
};
bool cmp(job a, job b){
    return a.s<b.s;
}
job jb[1001];
int sw[1001],dyn[1001];
int n,i,j;
int main(){
    scanf("%d",&n);
    for(i = 1; i <= n; i++){
        scanf("%d",&jb[i].s,&jb[i].t,&jb[i].w);
    }
    std::sort(jb+1,jb+n+1,cmp);
}
