#include "stdio.h"
char mid(char a, char b, char c){
    if((a>=b&&a<=c)||(a>=c&&a<=b)) return a;
    else if((b>=a&&b<=c)||(b>=c&&b<=a)) return b;
    else return c;
}
int main(){
    int l,k,i,j;
    char ab[2][128];
    char key[128];
    scanf("%d%d",&l,&k);
    scanf(" %s %s %s", ab[0], ab[1], key);

    for(i = 0; i < l+k; i++){
        for(j=(i>=l?i-l+1:0); j<=i&&k-j>0; j++){
            key[k-j-1] = mid(ab[0][i-j],ab[1][i-j],key[k-j-1]);
        }
    }
    printf("%s\n", key);
}
