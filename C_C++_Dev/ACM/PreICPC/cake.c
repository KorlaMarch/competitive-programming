#include "stdio.h"
long long int n,i,j,fac,c,a,b,g;
long long int cake[25][2];
long long int factor[155];
long long int maxF[155];

long long int gcd(long long int a, long long int b){
    long long int t;
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
    scanf("%lld",&n);
    for(i = 0; i < n; i++){
        scanf("%lld/%lld",&cake[i][0],&cake[i][1]);
        a = cake[i][1];
        //Find LCM
        for(j = 0; j < 105; j++) factor[j] = 0;
        for(j = 2; a != 1; j++){
            while(a%j==0){
                factor[j]++;
                a /= j;
            }
        }
        for(j = 0; j < 105; j++){
            if(factor[j]>maxF[j]) maxF[j] = factor[j];
        }
        /////
    }
    for(i = 2,fac = 1; i < 105; i++){
        for(j = 0; j < maxF[i]; j++){
            fac *= i;
        }
    }
    for(i = 0; i < n; i++){
        c += cake[i][0]*(fac/cake[i][1]);
    }
    if(c%fac){
        a = fac-c%fac;
        b = fac;
        g = gcd(a,b);
        printf("%lld\n%lld/%lld\n",c/fac+1,a/g,b/g);
    }
    else printf("%lld\n0\n",c/fac);
}
