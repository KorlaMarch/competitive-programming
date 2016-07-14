#include <stdio.h>
#include <conio.h>
#include <math.h>

double fac(double n){
    if(n <= 1){
        return 1.0;
    }
    return n * fac(n - 1);
}

double power(double base, int r){
    if(r <= 1){
        return base;
    }
    return base*power(base, r - 1);
}

double Xsin(double x){
    int n;
    double sum = x;
    for(n = 3; n <= 20; n += 2){
        if((n - 1)%4 == 0){
            //printf("plus n = %d p = %f\n", n, (double)fac(n));
            sum += (double)power(x,n)/fac(n);
        }else{
            //printf("nega n = %d p = %f\n", n, -1.0*(double)fac(n));
            sum += -1.0*(double)power(x,n)/fac(n);
        }
    }
    return sum;
}

double Xcos(double x){
    int n;
    double sum = 1;
    for(n = 2; n <= 12; n += 2){
        if(n%4 == 0){
            //printf("plus n = %d p = %f\n", n, (double)fac(n));
            sum += (double)power(x,n)/fac(n);
        }else{
            //printf("nega n = %d p = %f\n", n, -1.0*(double)fac(n));
            sum += -1.0*(double)power(x,n)/fac(n);
        }
    }
    return sum;
}

double Xe(double x){
    int n;
    double sum = 1 + x;
    for(n = 2; n <= 20; n++){
        sum += (double)power(x,n)/fac(n);
    }
    return sum;
}

double Xln(double x){
    int n;
    x = x - 1;
    double sum = x;
    for(n = 2; n <= 200; n++){
        if(n % 2 == 0){
            sum += -1*(double)power(x,n)/(double)n;
        }else{
            sum += (double)power(x,n)/(double)n;
        }
    }
    return sum;
}

double Xarctan(double x){
    int n;
    double sum = x;
    for(n = 3; n <= 200; n += 2){
        if((n - 1)%4 == 0){
            //printf("plus n = %d p = %f\n", n, (double)fac(n));
            sum += (double)power(x,n)/n;
        }else{
            //printf("nega n = %d p = %f\n", n, -1.0*(double)fac(n));
            sum += -1.0*(double)power(x,n)/n;
        }
    }
    return sum;
}

double facTo(int s, int n){
    double t = s;
    int x;
    for(x = 1; x < n; x++){
        t *= s - x;
    }
    return t;
}

double X1p(double x, double p){
    int y;
    double sum = 1 + p*x;
    for(y = 2; y < 20; y++){
        printf("loop = %d sum = %f\n", y, sum);
        sum += power(x, y)*facTo(p,y)/fac(y);
    }
    return sum;
}

int main(){
    printf("%.10f\n%.10f", X1p(0.5, 6), Xe(5));
    getch();
    return 0;
}
