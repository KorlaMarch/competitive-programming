#include "stdio.h"

int main(){
    int n,i,m1=100001,m2=100001,mx=0,x;
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d",&x);
        if(x > mx) mx = x;
        if(x < m1) m1 = x;
        else if(x < m2) m2 = x;
    }
    if(m1+m2<=mx){
        printf("yes\n");
    }else{
        printf("no\n");
    }
}
