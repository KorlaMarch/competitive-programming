#include "stdio.h"
long long gcd(long long a, long long b){
    long long t;
    if(b>a){
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
long long lcm(long long a, long long b){
    return (a*b)/gcd(a,b);
}
int main(){
    int n,i;
    long long c,lc,l,gc,a,b,la,lb;
    scanf("%d",&n);
    for(i=c=0,la=0,lb=1; i < n; i++){
        scanf(" %lld/%lld",&a,&b);
        lc = lcm(lb,b);
        la = la*(lc/lb)+a*(lc/b);
        c += la/lc;
        la = la%lc;
        gc = gcd(lc,la);
        la /= gc;
        lb = lc/gc;
    }
    if(la!=0){
        printf("%lld\n",c+1);
        l = lb-la;
        gc = gcd(lb,l);
        printf("%lld/%lld\n",l/gc,lb/gc);
    }else{
        printf("%d\n0\n",c);
    }
}
