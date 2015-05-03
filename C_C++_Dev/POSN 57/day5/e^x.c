#include "stdio.h"

double ex(double x,double pw,int n,long long fac){
    if(pw/fac < 0.0000001) return x/fac;
    //printf("ex %f %f %d %lld\n",x,pw,n,fac);
    return pw/fac + ex(x, pw*x,n+1,fac*n);
}

int main(){
    double x;
    printf("Enter x:");
    scanf("%lf", &x);
    printf("e^%.2f=%f\n",x,1+ex(x,x,2,1));
}
