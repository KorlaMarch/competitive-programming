#include "stdio.h"
int d,i,v,x,l,c,k;

void pRoman(int n){
    if(n%10 == 4){
        n -= 4; i++; v++;
    }
    if(n%10 == 9){
        n -= 9; i++; x++;
    }
    if(n%100/10 == 4){
        n -= 40; x++; l++;
    }
    if(n%100/10 == 9){
        n -= 90; x++; c++;
    }
    c += n/100;
    n = n%100;
    l += n/50;
    n = n%50;
    x += n/10;
    n = n%10;
    v += n/5;
    n = n%5;
    i += n;
}

int main(){
    scanf("%d",&d);
    for(k = 1; k <= d; k++){
        pRoman(k);
    }
    printf("%d %d %d %d %d\n", i, v, x, l, c);
}
