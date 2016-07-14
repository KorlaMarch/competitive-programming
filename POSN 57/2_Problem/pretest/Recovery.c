/*
LANG: C
COMPILER: WCB
*/
#include "stdio.h"

int main(){
    int n,i,sumA,sumW,ca,cw;
    int ai[1000],wi[1000];
    scanf("%d", &n);
    for(i = sumA = sumW = ca = cw = 0; i < n; i++){
        scanf("%d%d", &ai[i], &wi[i]);
        if(ai[i] != -1) { sumA += ai[i]; ca++; }
        if(wi[i] != -1) { sumW += wi[i]; cw++; }
    }
    sumA /= ca;
    sumW /= cw;
    for(i = 0; i < n; i++){
        if(ai[i]!=-1||wi[i]!=-1){
            if(ai[i] == -1) ai[i] = sumA;
            if(wi[i] == -1) wi[i] = sumW;
            printf("%d %d\n", ai[i], wi[i]);
        }
    }
}
