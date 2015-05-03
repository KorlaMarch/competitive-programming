#include "stdio.h"

int main(){
    int n,i,j,k,val,a;
    scanf("%d",&n);
    for(i=j=val=k=0; i < n; i++){
        scanf(" %d",&a);
        k += a;
        j += k;
        j %= 2553;
        val += j;
        val %= 2553;
    }
    printf("%d\n",val);
}
