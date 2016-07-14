#include "stdio.h"

int main(){
    int n,i,x,ln;
    long long int sum,dif;
    scanf("%d %d",&n,&ln);
    for(i=1,sum=dif=0; i < n; i++){
        scanf("%d",&x);
        dif += (x-ln)*i;
        sum += dif;
        ln = x;
    }
    for(x = sum%49999,i=3; i < n; i++){
        x = x*(i-1)%49999;
    }
    printf("%d\n", x);
}
