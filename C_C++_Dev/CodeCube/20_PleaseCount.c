#include "stdio.h"
int n,x,q,i,j,A,B;
int bucket[3500001],num[3500001];

int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d",&x);
        bucket[x]++;
    }
    for(i=j=0; i <= n; i++){
        while(bucket[i]){
            num[j++] = i;
            bucket[i]--;
        }
    }
    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d %d",&A,&B);
        printf("%d\n",num[A-1]-num[B-1]);
    }
}
