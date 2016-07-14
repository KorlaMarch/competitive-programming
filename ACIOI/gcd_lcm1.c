#include "stdio.h"
int euclid(int a, int b){
    int t;
    while(b){
        t = a%b;
        a = b;
        b = t;
    }
    return a;
}

int main(){
    int gcd;
    int a,b;
    scanf("%d%d", &a,&b);
    gcd = euclid(a,b);
    printf("%d %lld\n", gcd,((long long int)a)*b/gcd);
}
