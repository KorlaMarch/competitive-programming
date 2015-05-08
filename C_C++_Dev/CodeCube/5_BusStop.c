#include "stdio.h"

unsigned long long gcd(unsigned long long a, unsigned long long b){
    unsigned long long t;
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
    int n,i,t;
    unsigned long long lcm;
    scanf("%d",&n);
    for(i=0,lcm=1; i < n; i++){
        scanf("%d",&t);
        lcm = lcm*t/gcd(lcm,t);
    }
    printf("%llu\n",lcm);
}

