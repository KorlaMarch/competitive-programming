#include "stdio.h"
int main(){
    int n,i,j;
    char s[501];
    scanf("%d %s", &n, s);
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            putchar(s[(i+j+n)%n]);
        }
        putchar('\n');
    }
}
