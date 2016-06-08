#include "stdio.h"
#include "algorithm"

int n,i,j,f,e,x;

int abs(int x){
    return x<0?-x:x;
}

int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d",&x);
        if(x==1) f = i;
        else if(x==n) e = i;
    }
    printf("%d\n",std::max(std::max(abs(f-n+1),abs(f)),std::max(abs(e-n+1),abs(e))));
}
