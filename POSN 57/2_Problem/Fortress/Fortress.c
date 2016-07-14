#include "stdio.h"

int main(){
    int i,m,n;
    for(i = 0; i < 20; i++){
        scanf("%d%d", &m,&n);
        if(n*2<=m&&2*n-m/2+1>0){
            printf("%d\n", 2*n-m/2+1);
        }else{
            printf("0\n");
        }
    }
}
