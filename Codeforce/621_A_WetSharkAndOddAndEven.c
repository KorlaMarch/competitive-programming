#include "stdio.h"

long long sum,mn,x;
int n,i;


int main(){
    scanf("%d",&n);
    mn = 1000000005;
    for(i = 0; i < n; i++){
        scanf("%I64d",&x);
        sum += x;
        if(x%2&&x<mn) mn = x;
    }
    if(sum%2) sum -= mn;
    printf("%I64d\n",sum);
}
