#include <stdio.h>
#include <conio.h>

double f_x(double x){
    return x*x - 7;
}

double findX(double a, double b){
    //printf("f_x((a+b)/2.0) = %f\n", f_x((a+b)/2.0));
    if(f_x((a+b)/2.0) > -0.000000001 && f_x((a+b)/2.0) < 0.000000001){
        return (a+b)/2.0;
    }else if(f_x((a+b)/2.0) < 0){
        return findX((a+b)/2.0 , b);
    }else{
        return findX(a, (a+b)/2.0);
    }
}

int main(){
    double a = 0,b = 0;
    double x;
    //find A
    while(f_x(a) > 0){
        a -= 5;
    }

    while(f_x(b) < 0){
        b += 5;
    }

    x = findX(a,b);
    printf("\n x = %.10lf\n", x);
    getch();
    return 0;
}
