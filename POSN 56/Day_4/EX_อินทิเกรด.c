#include <stdio.h>

double f(double x){
    return x*x+1;
}

double findArea(double x, double d_x){
    return d_x*(f(x) + f(x + d_x))/2;
}
int main(){
    double area = 0;
    int from = 0;
    int to = 10;
    int scal = 1000;
    double x;

    printf("Form : "); scanf("%d", &from);
    printf("To : "); scanf("%d", &to);
    printf("In scal : "); scanf("%d", &scal);
    //delta x == to/range
    for(x = from; x < to; x += to/(double)scal){
        area += findArea(x, to/(double)scal);
    }

    printf("Integate = %lf", area);
}
