#include "stdio.h"

long long n,a,b,p,q,lcm,s;

long long gcd(long long a, long long b){
    long long t;
    if(a<b){
        t = a;
        a = b;
        b = t;
    }
    while(b){
        t = a%b;
        a = b;
        b = t;
    }
    return a;
}

int main(){
    scanf("%I64d%I64d%I64d%I64d%I64d",&n,&a,&b,&p,&q);
    lcm = a*b/gcd(a,b);
    s = p*(n/a-n/lcm)+q*(n/b-n/lcm);
    if(p>q) s += p*(n/lcm);
    else s += q*(n/lcm);
    printf("%I64d\n",s);
}
