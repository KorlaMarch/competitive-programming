#include "stdio.h"

int min(int a, int b){
    return a<b?a:b;
}
int minstep(int x){
    int minS[2001] = {};
    int i;
    for(i = 2; i <= x; i++){
        minS[i] = minS[i-1]+1;
        if(i%2==0) minS[i] = min(minS[i],minS[i/2]+1);
        if(i%3==0) minS[i] = min(minS[i],minS[i/3]+1);
    }
    return minS[x];
}
