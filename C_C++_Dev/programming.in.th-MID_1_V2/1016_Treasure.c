#include "stdio.h"
#include "math.h"

int main(){
    int n;
    double x=0.0,y=0.0;
    char s[3];
    while(scanf("%d%s", &n,s)==2){
        if(s[0] == 'N'){
            if(s[1] == 'E'){
                x += M_SQRT1_2*n;
                y += M_SQRT1_2*n;
            }else if(s[1] == 'W'){
                x -= M_SQRT1_2*n;
                y += M_SQRT1_2*n;
            }else{
                y+=n;
            }
        }else if(s[0] == 'E'){
            x+=n;
        }else if(s[0] == 'S'){
            if(s[1] == 'E'){
                x += M_SQRT1_2*n;
                y -= M_SQRT1_2*n;
            }else if(s[1] == 'W'){
                x -= M_SQRT1_2*n;
                y -= M_SQRT1_2*n;
            }else{
                y-=n;
            }
        }else{
            x-=n;
        }
    }

    printf("%.3lf %.3lf\n%.3lf",x,y,sqrt(x*x+y*y));
}
