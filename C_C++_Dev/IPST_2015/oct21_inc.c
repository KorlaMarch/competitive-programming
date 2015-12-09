#include "stdio.h"
int max(int a, int b){
    return a>b?a:b;
}
int n,i,j,mx;
int x[1001],inc[1001],p[1001];
void printR(int i){
    if(i){
        printR(p[i]);
        printf("%d ",x[i]);
    }
}
int main(){
    scanf("%d",&n);
    for(i = 1; i <= n; i++){
        scanf("%d",&x[i]);
    }
    mx = 1;
    for(i = 1; i <= n; i++){
        inc[i] = 1;
        for(j = i-1; j>=1; j--){
            if(x[j]<x[i]){
                if(inc[j]+1>inc[i]){
                    inc[i] = inc[j]+1;
                    p[i] = j;
                }
            }
        }
        if(inc[i]>inc[mx]){
            mx = i;
        }
    }
    printf("%d\n",inc[mx]);
    printR(mx);
}
