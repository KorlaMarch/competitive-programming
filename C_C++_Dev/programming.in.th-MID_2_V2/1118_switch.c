#include "stdio.h"

int main(){
    char a[15][15];
    char c;
    int n,i,j;
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf(" %c", &a[i][j]);
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf(" %c", &c);
            a[i][j] = !(a[i][j]==c);
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            putchar(a[i][j]+'0');
        }
        putchar('\n');
    }
}
