#include "stdio.h"
int abs(int a){
    return a<0?-a:a;
}
int getMD(int n){
    int i,md;
    for(i = 1, md = n-1; i < n; i++){
        if(n%i==0&&abs(i-n/i)<md){
            md = abs(i-n/i);
        }
    }
    return md;
}
int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i = 1; i <= n; i++){
        scanf("%d",&j);
        printf("Case #%d\n%d\n",i,getMD(j));
    }
}
