#include "stdio.h"

int main(){
    int a,b,c,i;
    scanf("%d%d%d",&a,&b,&c);
    for(i = 0; a>1||b>1||c>1; i++){
        if(a>=b&&a>=c) a /= 2;
        else if(b>=a&&b>=c) b /= 2;
        else c /= 2;
    }
    printf("%d\n", i);
}
