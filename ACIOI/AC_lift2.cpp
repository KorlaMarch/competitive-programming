#include "stdio.h"
#include "algorithm"

typedef struct{
    int w;
    int k;
}nak_tod;

bool cmp(nak_tod a, nak_tod b){
    if(a.k == b.k){
        return a.w <= b.w;
    }else{
        return a.k > b.k;
    }
}

int main(){
    int n,m,i,ws,ks;
    nak_tod a[100000];
    scanf("%d%d", &n, &m);
    for(i = 0; i < n; i++){
        scanf("%d%d", &a[i].w, &a[i].k);
    }
    std::sort(a,a+n,cmp);
    for(i = 0,ws = 0, ks = 0; i < n; i++){
        if(ws+a[i].w <= m){
            ws += a[i].w;
            ks += a[i].k;
        }else{
            break;
        }
    }
    printf("%d %d %d",i,ks,ws);
}
