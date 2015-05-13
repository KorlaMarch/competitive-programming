#include "stdio.h"

int main(){
    int max,min,n,x,i;
    scanf("%d%d",&n,&x);
    min = max = x;
    for(i = 1; i < n; i++){
        scanf("%d",&x);
        if(x<min) min = x;
        if(x>max) max = x;
    }
    printf("%d\n%d\n",max,min);
}
