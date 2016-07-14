#include "stdio.h"
#include "stdlib.h"
#include "time.h"

double lr = 0.00001;
double w[3] = {0.1,0.2,0.3},x[3];
double o,t;
int i,j,n,co;

double fx(double x1, double x2){
    return 0.87*x1*x1-2.12*x2+8.97;
}

double fx2(double x1, double x2, double a, double b, double c){
    return a*x1*x1+b*x2+c;
}

/*double fx(double x1, double x2){
    return 5.847*x1+5.0;
}

double fx2(double x1, double x2, double a, double b, double c){
    return a*x1+c;
}*/

double abs(double x){
    return x<0.0?-x:x;
}

int main(){
    n = 3;
    srand(time(NULL));
    for(j = 0; ; j++){
        //scanf("%lf%lf",&x[0],&x[1]);
        x[0] = (rand()-RAND_MAX/2.0)/500.0;
        x[1] = (rand()-RAND_MAX/2.0)/500.0;
        x[2] = 1;
        t = fx(x[0],x[1]);
        o = fx2(x[0],x[1],w[0],w[1],w[2]);
        if(j%1000==0) printf("%d : %.3f %.3f %.3f : Out %.3f %.3f : Diff = %.3f\n",j,w[0],w[1],w[2],t,o,t-o);
        if(abs(t-o)>0.0001){
            co = 0;
            for(i = 0; i < n; i++){
                w[i] += lr*x[i]*(t-o);
            }
        }else{
            co++;
            if(co>1000){
                printf("End\n");
                break;
            }
        }
    }
}
