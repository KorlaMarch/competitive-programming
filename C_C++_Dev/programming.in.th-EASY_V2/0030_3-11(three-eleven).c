#include "stdio.h"

int main(){
    char s[1000005];
    int i,sum1=0,sum2=0,sum3=0;
    scanf(" %s", s);
    for(i = 0; s[i]; i++){
        sum1 += s[i]-'0';
        if(i%2) sum2 += s[i]-'0';
        else sum3 += s[i]-'0';
    }
    i=(sum3-sum2)*(i%2?1:-1)%11;
    printf("%d %d", sum1%3, i<0?i+11:i);
}
