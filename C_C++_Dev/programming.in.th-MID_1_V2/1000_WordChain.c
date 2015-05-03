#include "stdio.h"

int main(){
    int l,n,i,j,d;
    char s[2][1001];
    scanf("%d%d", &l,&n);
    scanf(" %s", s[0]);
    for(i = 1; i < n; i++){
        scanf(" %s", s[i%2]);
        for(j = d = 0; s[0][j]; j++){
            if(s[0][j]!=s[1][j]) d++;
        }
        if(d>2){
            printf("%s\n",s[(i+1)%2]);
            return 0;
        }
    }
    printf("%s\n", s[(i+1)%2]);
}
