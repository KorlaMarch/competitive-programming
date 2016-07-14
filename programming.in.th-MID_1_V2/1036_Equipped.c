#include "stdio.h"

int main(){
    int n,k,i,j,l,wi,pi,sp,m;
    int p[257];
    scanf("%d%d",&n,&k);
    m = (1<<k);
    for(i = 0; i < m; i++) p[i] = 200000;
    for(i = 0; i < n; i++){
        scanf("%d",&wi);
        for(j = sp = 0; j < k; j++){
            scanf("%d", &pi);
            sp = sp*2+pi;
        }
        if(wi < p[sp]) p[sp] = wi;
    }

    for(i = 1; i < m; i++){
        for(j = 1; j < i; j++){
            for(l = j+1; l < i; l++){
                if((j|l)==i && p[j]+p[l] < p[i])
                    p[i] = p[j]+p[l];
            }
        }
    }
    printf("%d\n", p[m-1]);
}
