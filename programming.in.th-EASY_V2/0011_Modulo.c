#include "stdio.h"

int main(){
    int i,x;
    int mod[42] = {};
    for(i=0; i < 10; i++){
        scanf("%d",&x);
        mod[x%42] = 1;
    }
    for(i=x=0;i<42;i++){
        if(mod[i]) x++;
    }
    printf("%d\n",x);
}
