#include "stdio.h"
#include "algorithm"
#include "math.h"

double d,mxDis,dis;

int main(){
	scanf("%lf",&d);
	d *= d;
	mxDis = 0.0;
	for(int i = 0; i*i <= d; i++){
		dis = i;
		if(d-i*i<=1) dis += 1;
		else dis += sqrt(d-i*i);
		mxDis = std::max(dis,mxDis);
	}
	mxDis = std::max(mxDis,sqrt(2.0*d));
	printf("%.10f\n",mxDis);
}