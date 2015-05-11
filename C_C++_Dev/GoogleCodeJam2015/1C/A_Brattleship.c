#include "stdio.h"

int main(){
    int t,r,w,c,i,j,k,way;
    scanf("%d",&t);
    for(k = 1; k <= t; k++){
        scanf("%d %d %d",&r,&c,&w);
        if(c%w==0){
            printf("Case #%d: %d\n",k,r*(c/w)+w-1);
        }else{
            printf("Case #%d: %d\n",k,r*(c/w)+w);
        }

    }
}
