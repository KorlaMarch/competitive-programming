#include "stdio.h"

int main(){
    int a,b,t;
    scanf("%d%d",&a,&b);
    if(b>a){
        t = a;
        a = b;
        b = t;
    }
    while(a%b){
        t = a%b;
        a = b;
        b = t;
    }
    printf("%d\n",b);
}
