#include "stdio.h"

#define EPSI 0.00000001

int n,k;
double l,v1,v2;
double x,y,mid,minT;

bool canDo(double dis){
	double t = 0;
	double sd;
	for(int i = n; i > 0; i -= k){
		//go
		t += dis/(v2*(1.0-v1/v2));
		if(i-k>0){
			//back
			t += dis/(v2*(1.0+v1/v2));
		}
		sd = v1*t+dis;
	}
	if(sd<=l){
		t += (l-sd)/v1;
		if(t<minT){
			minT = t;
		}
	}
	return sd<l;
}

int main(){
	scanf("%d %lf%lf%lf %d",&n,&l,&v1,&v2,&k);
	x = 0;
	y = l;
	minT = y/v1;
	if(v1<v2){
		for(int i = 0; i < 1000; i++){
			mid = (y+x)/2.0;
			if(canDo(mid)){
				x = mid;
			}else{
				y = mid;
			}
		}
	}
	printf("%.10f\n",minT);
}