#include "stdio.h"

long long int facTo(int n, int t){
    if(n == t) return n;
    return n*(long long int)facTo(n-1,t);
}

int c(int n, int r){
    return facTo(n,n-r+1)/facTo(r,1);
}

int main(){
    int n;
    scanf("%d",&n);
    if(n==1) printf("2\n");
    else if(n%2) printf("%d\n",c(n,n/2)+c(n,n/2+1));
    else printf("%d\n",c(n,n/2));
}
