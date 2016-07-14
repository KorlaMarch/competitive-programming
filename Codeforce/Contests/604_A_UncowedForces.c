#include "stdio.h"

int m[6],w[6],i,j,s,u;
double score;

double max(double a, double b){
    return a>b?a:b;
}

int main(){
    for(i = 1; i <= 5; i++){
        scanf("%d",&m[i]);
    }
    for(i = 1; i <= 5; i++){
        scanf("%d",&w[i]);
    }
    scanf("%d%d",&s,&u);
    score = 100.0*s - 50.0*u;
    for(i = 1; i <= 5; i++){
        score += max(150*i,(1-m[i]/250.0)*500*i - 50.0*w[i]);
    }
    printf("%.0f\n",score);
}
