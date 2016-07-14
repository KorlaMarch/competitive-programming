#include "stdio.h"

int t,n,m,i,c;

int main(){
    scanf("%d",&t);
    for(i = 0; i < t; i++){
        scanf("%d%d",&m,&n);
        for(c=0;n>=0;n-=20){
            if(n<=m) c++;
        }
        printf("Case #%d: %d\n",i+1,c);
    }
}
