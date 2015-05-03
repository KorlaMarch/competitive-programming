#include "stdio.h"

int abs(int n){
    return n<0?n*-1:n;
}

int main(){
    int n,n2=0,i,j;
    scanf("%d",&n);
    if(n%2==0){
        n--;
        n2=1;
    }
    for(i = 0; i < n;){

        for(j = 0; j < n; j++){
            if(n/2-abs(i-n/2)==abs(j-n/2)) putchar('*');
            else putchar('-');
        }
        putchar('\n');
        i++;
        if(i==n/2+1 && n2){
            i--;
            n2=0;
        }
    }
}
