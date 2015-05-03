#include "stdio.h"

int main(){
    int n,i,a,min,max;
    scanf("%d%d",&n,&a);
    min = max = a;
    for(i = 1; i < n; i++){
        scanf("%d", &a);
        if(a < min) min = a;
        if(a > max) max = a;
    }
    printf("%d\n%d\n",min,max);

}
