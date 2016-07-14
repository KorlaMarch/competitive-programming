#include "stdio.h"

int main(){
    int n,a,b,c,i,j,ways=0;
    scanf("%d%d%d%d",&n,&a,&b,&c);
    n = n*2;
    for(i = 0; i <= c; i++){
        for(j = 0; j <= b; j++){
            if(3*i+2*j<=n&&3*i+2*j+a>=n) ways++;
        }
    }
    printf("%d\n",ways);
    return 0;
}
