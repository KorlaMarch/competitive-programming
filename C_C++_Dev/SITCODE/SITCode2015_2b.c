#include "stdio.h"

int main(){
    int n,i,j,c;
    char s[1024];
    scanf("%d",&n);
    for(i = 1; i <= n; i++){
        scanf(" %s",s);
        for(j=c=0; s[j]; j++){
            switch(s[j]){
            case 'B':
                c++;
            case 'A': case 'D': case 'O': case 'P': case 'Q': case 'R':
                c++;
            }
        }
        printf("Case #%d\n%d\n",i,c);
    }
}
