#include "stdio.h"
#include "math.h"
int mx1,my1,mx2,my2,r1,r2;
double R,r,d;
int main(){
    scanf("%d%d%d %d%d%d",&mx1,&my1,&r1,&mx2,&my2,&r2);
    d = sqrt((mx1-mx2)*(double)(mx1-mx2)+(my1-my2)*(double)(my1-my2));
    if(r1>r2){
        R = r1;
        r = r2;
    }else{
        R = r2;
        r = r1;
    }
    //printf("%f %f %f\n",R,r,d);
    if(d>=r+R) printf("0.0000000000\n");
    else if(isnan(r*r*acos((d*d+r*r-R*R)/(2*d*r))+R*R*acos((d*d+R*R-r*r)/(2*d*R))
           -0.5*sqrt((-d+r+R)*(d+r-R)*(d-r+R)*(d+r+R)))) printf("%.12f\n",3.1415926535897932384626433832795028841971693993751058*r*r);
    else printf("%.12f\n",r*r*acos((d*d+r*r-R*R)/(2*d*r))+R*R*acos((d*d+R*R-r*r)/(2*d*R))
           -0.5*sqrt((-d+r+R)*(d+r-R)*(d-r+R)*(d+r+R)));
}
