#include "stdio.h"

#define MOD 1000000007

long long a,b,x,n,s,an;

long long pow(long long a, long long r){
    long long p;
    if(r==0) return 1;
    else{
        p = pow(a,r/2);
        if(r%2) return (((p*p)%MOD)*a)%MOD;
        else return (p*p)%MOD;
    }
}

long long inv(long long i, long long n){
    long long a=n,b=i,t,pa=0,pb=1;
    while(b!=0){
        t = pb;
        pb = ((pa-pb*(a/b)%MOD)+MOD)%MOD;
        pa = t;
        t = a%b;
        a = b;
        b = t;
        //printf("%d %d ");
    }
    if(a>1) while(1);
    if(pa<0) pa += n;
    return pa%MOD;
}

int main(){
    scanf("%I64d%I64d%I64d%I64d",&a,&b,&n,&x);
    an = pow(a,n);
    //printf("%d %I64d ",an,(an-a+MOD)*inv(a-1,MOD)%MOD+1L);
    s = (x*an)%MOD;
    if(a!=1){
        s += b*((an-a+MOD)%MOD*inv(a-1,MOD)%MOD+1)%MOD;
    }else{
        s += b*n%MOD;
    }
    s %= MOD;
    printf("%I64d\n",s);
}
