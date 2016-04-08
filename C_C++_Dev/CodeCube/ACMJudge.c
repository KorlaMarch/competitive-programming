#include "stdio.h"

int t,n,m,i,j;
char s[25],feq[256];
int main(){
    scanf("%d",&t);
    for(i = 0; i < t; i++){
        scanf(" %s",s);
        for(j = 0; j < 256; j++){
            feq[j] = 0;
        }
        for(j = 0; s[j]; j++){
            feq[s[j]]++;
        }
        if(feq['X']) printf("Case #%d: No - Runtime error\n",i+1);
        else if(feq['T']) printf("Case #%d: No - Time limit exceeded\n",i+1);
        else if(feq['-']) printf("Case #%d: No - Wrong answer\n",i+1);
        else printf("Case #%d: Yes\n",i+1);
    }
}
