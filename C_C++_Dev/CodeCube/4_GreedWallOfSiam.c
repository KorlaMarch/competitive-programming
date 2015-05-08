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
    int h[100000];
    int n,i,g;
    unsigned long long c;
    scanf("%d",&n);
    for(i=g=0; i < n; i++){
        scanf("%d",&h[i]);
        g = gcd(g,h[i]);
    }
    for(i=c=0; i < n; i++){
        c += h[i]/g;
    }
    printf("%llu\n",c);
}

