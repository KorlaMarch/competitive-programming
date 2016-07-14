#include "stdio.h"

int n,q;
int num[100001];
int main(){
    int i,a,b;
    scanf("%d%d",&n,&q);
    for(i=1;i<=n;i++){
        scanf("%d",&num[i]);
        num[i] += num[i-1];
    }
    for(i=0;i<q;i++){
        scanf("%d%d",&a,&b);
        printf("%d\n", num[b]-num[a-1]);
    }
}
