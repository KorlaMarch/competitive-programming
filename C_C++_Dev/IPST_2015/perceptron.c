#include "stdio.h"

double lr = 0.1;
double w[3] = {0.1,0.2,0.3},x[3];
int i,j,n;
char c;

double dot(double a[], double b[], int n){
    int i;
    double pro = 0.0;
    for(i = 0; i < n; i++){
        pro += a[i]*b[i];
    }
    return pro;
}

int main(){
    n = 3;
    while(1){
        scanf("%lf%lf %c",&x[1],&x[2],&c);
        x[0] = 1.0;
        if(dot(w,x,n)>=0.0){
            if(c=='+'){
                printf("Correct\n");
            }else{
                printf("Incorrect\n");
                for(i = 0; i < n; i++){
                    w[i] -= lr*x[i];
                }
            }
        }else{
            if(c=='-'){
                printf("Correct\n");
            }else{
                printf("Incorrect\n");
                for(i = 0; i < n; i++){
                    w[i] += lr*x[i];
                }
            }
        }
        printf("%.3f %.3f %.3f : dot = %.3f\n",w[0],w[1],w[2],dot(w,x,n));
    }
}
