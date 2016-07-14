#include "stdio.h"

int main(){
    int n,i,j;
    int per[1001];
    scanf("%d",&n);
    per[0] = 1;
    for(i = 1; i <= n; i++){
        per[i] = 0;
        for(j = 0; j < i; j++){
            per[i] = (per[i]+per[j]*per[i-j-1])%10001;
        }
    }
    printf("%d\n",per[n]);
}
