#include "stdio.h"
#include "math.h"
#include "algorithm"

unsigned long long house[1000000];

long long abs2(long long n){
    return n < 0 ? n*-1 : n;
}

int main(){
    int h;
    int i,j;
    unsigned long long pos = 0, minD;
    scanf("%d", &h);
    for(i = 0; i < h; i++){
        scanf("%llu", &house[i]);
    }
    std::sort(house,house+h);
    pos = house[h/2];
    for(i = 0,minD = 0; i < h; i++){
        minD += (unsigned long long)abs2(pos-house[i]);
    }
    printf("%llu\n", minD);
}
