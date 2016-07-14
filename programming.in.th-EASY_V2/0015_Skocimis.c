#include "stdio.h"
int max(int a, int b){
    return a>b?a:b;
}
int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    printf("%d\n", max(b-a,c-b)-1);
}
