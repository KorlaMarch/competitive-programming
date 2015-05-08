#include "stdio.h"

int gcd(int a, int b){
    int t;
    if(!a&&!b) return 0;
    if(!a||!b) return a>b?a:b;
    if(a<b){
        t = a;
        a = b;
        b = t;
    }
    while(a%b){
        t = a%b;
        a = b;
        b = t;
    }
    return b;
}

int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%llu\n",((unsigned long long)a)*b/gcd(a,b));
}
