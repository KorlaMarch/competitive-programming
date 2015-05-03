#include "stdio.h"
int main(){
    int i,n;
    long long int a,b,x,y,t;
    scanf("%d%lld",&n,&a);
    for(i = 1; i<n; i++){
        scanf("%lld",&b);
        if(a>b){
            x = a; y = b;
        }else{
            x = b; y = a;
        }
        while(x%y){
            t = x%y;
            x = y; y = t;
        }
        a = a*b/y;
    }
    printf("%lld\n", a);
}
