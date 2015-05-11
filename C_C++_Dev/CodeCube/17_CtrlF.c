#include "stdio.h"

int main(){
    int m,n,i,j,f;
    char s[1001],t[1001];
    scanf("%d %d %s %s",&n,&m,s,t);
    for(i=f=0; i+m <= n; i++){
        for(j = i; j < i+m; j++){
            if(s[j]!=t[j-i]) break;
        }
        if(j==i+m) f++;
    }
    printf("%d\n",f);
}
