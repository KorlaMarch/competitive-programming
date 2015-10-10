#include "stdio.h"

int minE(int a, int b, int c){
    if(a<=c&&b<=c) return c;
    else if(a<=c) return b;
    else if(b<=c) return a;
    else return a<b?a:b;
}

int main(){
    int a,b,c,n,i;
    scanf("%d%d%d%d",&n,&a,&b,&c);
    for(i = 0; i < n; i++){
        switch(i%3){
        case 0:
            a += (minE(b,c,a)-a)*2;
            break;
        case 1:
            b += (minE(a,c,b)-b)*2;
            break;
        case 2:
            c += (minE(a,b,c)-c)*2;
            break;
        }
    }
    printf("%d\n%d\n%d\n",a,b,c);
}
