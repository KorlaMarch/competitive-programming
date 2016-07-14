#include "stdio.h"
int n,w;
int wi[30],vi[30];
int max(int a, int b){
    return a>b?a:b;
}
int knp(int x, int ww){
    if(x>=n) return 0;
    return ww+wi[x]>w?knp(x+1,ww): max(knp(x+1,ww+wi[x])+vi[x],knp(x+1,ww));
}

int main(){
    int i;
    scanf("%d%d",&n,&w);
    for(i=0;i<n;i++) scanf("%d%d",&wi[i],&vi[i]);
    printf("%d\n", knp(0,0));
}
