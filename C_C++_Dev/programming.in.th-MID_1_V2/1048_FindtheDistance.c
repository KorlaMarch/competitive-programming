#include "stdio.h"

int main(){
    int k,n,i,s;
    scanf("%d%d",&k,&n);
    for(i = s = 0; i<k;i++){
        s += n/(1<<i);
    }
    printf("%d\n", s);
}
