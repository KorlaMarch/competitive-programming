#include "stdio.h"

double x;
bool isP;

double diffAngle(double a, double b){
	double diff;
	if(a>=b){
		diff = a-b;
	}else{
		diff = b-a;
	}
	if(diff>180.0) diff = 360.0-diff;
	return diff;
}

int main(){
	scanf("%lf",&x);
	for(int i = 0; i < 24; i++){
		for(int j = 0; j < 60; j++){
			if(diffAngle((i>12?i-12:i)*360.0/12.0 + j*30.0/60.0,j*360.0/60.0)==x){
				printf("%02d:%02d\n",i,j);
				isP = true;
			}
		}
	}
	if(!isP){
		printf("NONE\n");
	}

}