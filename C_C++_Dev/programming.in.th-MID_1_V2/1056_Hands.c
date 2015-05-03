#include "stdio.h"
int n,k,i,j,ti,x;
int bk[1001];
int main(){
    scanf("%d%d",&n,&k);
    for(i = 0; i < n; i++){
        scanf("%d", &ti);
        bk[ti]++;
    }

    for(i = 1000,j=k; i >= 0; i--){
        while(bk[i]){
            bk[i]--;
            if(j>=k){
                x += i;
                j=1;
            }else j++;
        }
    }
    printf("%d\n", x);
}
