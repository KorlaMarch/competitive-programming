#include "stdio.h"

int a,b,c,d,i,cu;
char fe[105];

int main(){
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    scanf("%d%d %d%d",&a,&b,&c,&d);
    for(i = a; i < b; i++) fe[i] = 1;
    for(i = c; i < d; i++) fe[i] = 1;
    for(i = 0; i <= 102; i++){
        if(fe[i]) cu++;
    }
    printf("%d\n",cu);
    return 0;
}
