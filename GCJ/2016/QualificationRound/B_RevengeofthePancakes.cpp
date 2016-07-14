#include "stdio.h"
#include "string.h"
int t,k,i,c,l;
char s[200];

int main(){
    scanf("%d",&t);
    for(k = 1; k <= t; k++){
        scanf(" %s",s);
        l = strlen(s);
        s[l++] = '+';
        s[l] = '\0';
        c = 0;
        for(i = 1; i<l; i++){
            if(s[i]!=s[i-1]) c++;
        }
        printf("Case #%d: %d\n",k,c);
    }
}
