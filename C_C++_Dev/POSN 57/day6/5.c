#include "stdio.h"

double fx(double x){
    return x;
}

int main(){
    int n,a,b;
    double dx,area,i;
    scanf("%d%d%d",&a,&b,&n);
    dx = (double)(b-a)/n;
    printf("dx = %f\n", dx);
    for(i = a,area = 0; i+dx <= b; i += dx){
        area += (fx(i)+fx(i+dx))/2.0*dx;
    }
    printf("Area = %f\n", area);
}
