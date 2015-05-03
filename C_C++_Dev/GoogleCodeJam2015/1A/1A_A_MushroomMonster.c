#include "stdio.h"
int max(int a, int b){
    return a>b?a:b;
}
int main(){
    int t,n,k,i,j,x,first,second;
    int m[1000];
    scanf("%d",&t);
    for(k = 1; k <= t; k++){
        scanf("%d %d",&n,&m[0]);
        first = second = 0;
        for(i = 1; i < n; i++){
            scanf("%d",&m[i]);
            first += max(m[i-1]-m[i],0);
        }

        for(i = 0;; i++){
            for(j = 1,second = i*(n-1); j < n; j++){
                if(m[j-1]-i>m[j]) break;
                if(m[j-1]-i<0) second += m[j-1]-i;
            }
            if(j==n) break;
        }
        printf("Case #%d: %d %d\n",k,first,second);
    }
}
