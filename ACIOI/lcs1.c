#include "stdio.h"
int max(int a, int b){
    return a>b?a:b;
}
char s[1001],t[1001];
int a[1001][1001];
int i,j;
int main(){
    scanf(" %s %s", s, t);
    for(i = 1; s[i-1]; i++){
        for(j = 1; t[j-1]; j++){
            if(s[i-1]==t[j-1]) a[i][j] = a[i-1][j-1]+1;
            else a[i][j] = max(a[i-1][j],a[i][j-1]);
        }
    }
    printf("%d\n",a[i-1][j-1]);
}
