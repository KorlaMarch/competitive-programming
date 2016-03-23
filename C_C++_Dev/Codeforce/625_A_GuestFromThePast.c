#include "stdio.h"

long long int n,a,b,c,t,k;

int main(){
    scanf("%I64d%I64d%I64d%I64d",&n,&a,&b,&c);
    if(a<=b-c&&n>=a){
        printf("%I64d\n",n/a);
    }else if(n>=b){
        t = (n-b+1)%(b-c)+b-1;
        while(t>=b){
            k++;
            t -= b-c;
        }
        printf("%I64d\n",(n-b+1)/(b-c)+t/a+k);
    }else{
        printf("0\n");
    }
}
