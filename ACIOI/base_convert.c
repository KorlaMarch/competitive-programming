#include "stdio.h"
int getV(char c){
    return c >= '0' && c <= '9' ? c-'0' : c-'A'+10;
}
char getC(int v){
    return v >= 0 && v <= 9 ? v+'0' : v+'A'-10;
}

int main(){
    int n,k,i,j;
    unsigned int tenTh = 0;
    char s[32];
    scanf("%d%d %s", &n, &k, s);
    for(i = 0; s[i]; i++){
        tenTh*=n;
        tenTh += getV(s[i]);
    }
    for(i = 0; tenTh; i++){
        s[i]=getC(tenTh%k);
        tenTh /= k;
    }
    for(i--;i>=0;i--){
        putchar(s[i]);
    }
    putchar('\n');
}
