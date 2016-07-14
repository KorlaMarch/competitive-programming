#include "stdio.h"

int main(){
    int n,m,i,j;
    char c;
    scanf("%d%d",&m,&n);
    for(i=c=0; i < m; i++){
        for(j = 0; j < n; j++,c=(c+1)%26){
            putchar(c+'A');
        }
        putchar('\n');
    }
}
