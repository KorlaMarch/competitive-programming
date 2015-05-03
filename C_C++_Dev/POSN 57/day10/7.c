#include "stdio.h"

int main(){
    char s[3][32];
    int space[3] = {};
    int i,j,k,l,isFind,postfix = 0;
    for(i = 0; i < 3; i++) scanf("%s", s[i]);
    for(i = l = 1; i < 3; i++){
        for(j = 0,isFind = 0; s[i][j] != '\0' && !isFind; j++){
            for(k = 0; s[i-1][k] != '\0' && !isFind; k++){
                if(s[i][j] == s[i-1][k]) isFind = 1;
            }
        }
        l += i-j+1;
        space[i] = l;
        if(l*-1 > postfix) postfix = l*-1;
    }

    for(i = 0; i < 3; i++){
        for(k = 0; k < postfix+space[i]; k++){
            printf(" ");
        }
        printf("%s\n",s[i]);
    }
}
