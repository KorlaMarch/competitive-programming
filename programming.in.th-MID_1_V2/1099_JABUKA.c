#include "stdio.h"
int gcd(int x, int y){
    int t;
    while(x%y){
        t = x%y;
        x = y;
        y = t;
    }
    return y;
}
int main(){
    int r,g,i,gc;
    scanf("%d%d", &r, &g);
    if(r>g) gc = gcd(r,g);
    else gc = gcd(g,r);
    for(i = 1; i<=gc; i++){
        if(gc%i==0){
            printf("%d %d %d\n", i, r/i, g/i);
        }
    }
}
