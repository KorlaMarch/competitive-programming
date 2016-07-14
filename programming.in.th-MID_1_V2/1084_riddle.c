#include "stdio.h"

int main(){
    unsigned int x,y,k,i,j,c,s;
    long long unsigned int p;
    scanf("%u%u%u", &x, &y, &k);
    for(p=5,c=0; x/p; p*=5) c += x/p;
    for(i=x+1,s=c; i<=y; i++){
        for(j = i; !(j%5); j/=5,c++);
        c %= k;
        s = (s+c)%k;
    }
    printf("%u\n", s);
}
