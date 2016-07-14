#include "stdio.h"
int a,b,n,i,j,c;
char canC[10300];
int main(){
    scanf("%d%d%d",&a,&b,&n);
    canC[0] = 1;
    for(i = 0; i <= 10000; i++){
        if(canC[i]){
            canC[i+a] = canC[i+b] = 1;
        }
    }
    for(i = 0; i < n; i++){
        scanf("%d",&c);
        for(j = c; !canC[j]; j++);
        printf("%d\n",j);
    }
}
