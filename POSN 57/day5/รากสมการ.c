#include "stdio.h"

double fx1(double x){
    return x*x*x*x-x-1;
}

double fx2(double x){
    return x*x-7;
}

double abs(double x){
    return x < 0 ? x*-1 : x;
}

double FindRoot(double (*fx)(double), double a, double b){
    double x = (a+b)/2.0;
    while(abs((*fx)(x)) >= 0.0000001){
        x = (a+b)/2.0;
        if((*fx)(x)*(*fx)(a) < 0){
            b = x;
        }else if((*fx)(x)*(*fx)(b) < 0){
            a = x;
        }else{
            return x;
        }

    }

    return x;
}

int main(){
    printf("Fx1\t=  %f\n", FindRoot(fx1, 0.0, 10000.0));
    printf("\t= %f\n\n", FindRoot(fx1, -10000.0, 0.0));
    printf("Fx2\t=  %f\n", FindRoot(fx2, 0.0, 10000.0));
    printf("\t= %f\n", FindRoot(fx2, -10000.0, 0.0));
}
