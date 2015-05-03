#include "stdio.h"
int abs(int n){
    return n<0?n*-1:n;
}
int main(){
    int a,b,c,i,j;
    scanf("%d%d%d",&a,&b,&c);
    for(i = 1; i <= a; i++){
        for(j = abs(c)*-1; j <= abs(c); j++){
            if(i&&j&&a%i==0&&c%j==0&&i*(c/j)+j*(a/i)==b){
                printf("%d %d %d %d\n",i,j,a/i,c/j);
                return 0;
            }
        }
    }
    printf("No Solution\n");
}
