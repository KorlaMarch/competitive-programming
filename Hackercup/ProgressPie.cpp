#include "stdio.h"
#include "math.h"

#define PI 3.14159265

int t;
int p,x,y;

double getDegree(double x, double y){
	double r = atan2(x,y)*180.0/PI;
	if(r<0.0) r += 360.0;
	return r;
}

int main(){
	scanf("%d",&t);
	for(int k = 1; k <= t; k++){
		scanf("%d%d%d",&p,&x,&y);
		x -= 50;
		y -= 50;
		if(p==0 || x*x+y*y>50*50 || getDegree(x,y)>p/100.0*360.0) printf("Case #%d: white\n",k);
		else printf("Case #%d: black\n",k);
	}
}