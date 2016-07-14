#include "stdio.h"
int n,b,i,j,c;
char isP[500001];

int main(){
    scanf("%d %d",&n,&b);
    for(i = 2; i <= n; i++){
        if(!isP[i]){
            c++;
            for(j = i+i; j <= n; j += i) isP[j] = 1;
        }
    }
    if(b>=c) printf("0\n");
    else printf("%d\n",c-b);
}
