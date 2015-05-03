#include <stdio.h>
#include <conio.h>
#include <math.h>

double DtoR(double d){
    return d/180.0*M_PI;
}

int main(){
    float x;
    double r;
    printf("| %c\t| Sin %c\t| Cos %c\t| Tan %c |\n", 155,155,155,155);
    printf("=================================\n");
    for(x = 0.0; x <= 45.0; x += 0.5){
        r = DtoR(x);
        printf("| %.1f\t| %.3lf\t| %.3lf\t| %.3lf |\n", x,sin(r),cos(r),tan(r));
    }
    getch();
    return 0;
}
