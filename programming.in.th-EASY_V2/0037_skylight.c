#include "stdio.h"
#include "math.h"
int main(){
    int n,m,i,j,sum,l,k,c,x;
    scanf("%d%d%d%d%d",&n,&m,&l,&k,&c);
    for(i=sum=0; i < n; i++){
        for(j = 0; j < m; j++){
            scanf("%d",&x);
            sum += x;
        }
    }
    printf("%d\n",(int)ceil(((float)sum+c*l*k)/c));
}
