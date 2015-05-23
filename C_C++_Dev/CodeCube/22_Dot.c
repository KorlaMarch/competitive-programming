#include "stdio.h"
int n,c,a,b,i;
char isH[1001][1001];
int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d%d",&a,&b);
        if(!isH[a][b]){
            isH[a][b] = 1;
            c++;
        }
    }
    printf("%d\n",c);
}
