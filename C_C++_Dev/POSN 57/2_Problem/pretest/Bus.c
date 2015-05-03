/*
LANG: C
COMPILER: WCB
*/
#include "stdio.h"
int main(){
    int n,i,m,h,min;
    scanf(" %d%d%d", &n, &h, &m);
    min = h*60+m;
    for(i = 1; i < n; i++){
        scanf(" %d %d", &h, &m);
    }
    printf("%d\n", (h*60+m-min)/(n-1));

}
