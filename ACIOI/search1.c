#include "stdio.h"
int a[7500013];
int main(){
    int n,q,i,p,x,f;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &x);
        if(!x) x = 1500000000;
        p = (x<0?x*-1:x)%7500013;
        while(a[p]) p = (p+900001)%7500013;
        a[p] = x;
    }
    scanf("%d", &q);
    for(i = 0; i < q; i++){
        scanf("%d", &x);
        if(!x) x = 1500000000;
        p = (x<0?x*-1:x)%7500013;
        f = 1;
        while(a[p]&&f){
            if(a[p] == x) f = 0;
            p = (p+900001)%7500013;
        }
        printf("%c",f?'N':'Y');
    }
}
