#include "stdio.h"
int n,k,i,j;
int t[1000];
int main(){
    scanf("%d%d",&n,&k);
    for(i=2; i <= n; i++){
        if(!t[i]) for(j = i; j <= n; j += i){
            if(!t[j]){
                t[j] = 1;
                if(--k == 0){
                    printf("%d\n", j);
                    return 0;
                }
            }
        }
    }
}
