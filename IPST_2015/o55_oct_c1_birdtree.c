#include "stdio.h"
void findPath(int a, int b){
    if(a==b){
        putchar('\n');
    }else if(a>b){
        putchar('R');
        findPath(b,a-b);
    }else{
        putchar('L');
        findPath(b-a,a);
    }
}
int main(){
    int t,i,a,b;
    scanf("%d",&t);
    for(i = 0; i < t; i++){
        scanf("%d/%d",&a,&b);
        findPath(a,b);
    }
}
