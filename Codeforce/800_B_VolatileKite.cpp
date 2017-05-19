#include "stdio.h"
#include "math.h"
#include "algorithm"

int n,xi,yi;
double x[1005],y[1005];
double minD;

double caldis(int a, int b, int c){
	return fabs( (y[c]-y[a])*(double)x[b] - (x[c]-x[a])*(double)y[b] + x[c]*(double)y[a] - y[c]*(double)x[a] ) 
	/ sqrt((y[c]-y[a])*(double)(y[c]-y[a]) + (x[c]-x[a])*(double)(x[c]-x[a]));
}

double dis2(int a, int c){
	return sqrt((y[c]-y[a])*(double)(y[c]-y[a]) + (x[c]-x[a])*(double)(x[c]-x[a]));
}

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d%d",&xi,&yi);
		x[i] = (double)xi;
		y[i] = (double)yi;
	}
	minD = caldis(0,1,2);
	for(int i = 0; i < n; i++){
		//printf("%d %.10f\n",i,caldis(i,(i+1)%n,(i+2)%n));
		minD = std::min(minD,caldis(i,(i+1)%n,(i+2)%n));
	}
	for(int i = 0; i < n; i++){
		//printf("%d %.10f\n",i,caldis(i,(i+1)%n,(i+2)%n));
		minD = std::min(minD,dis2(i,(i+1)%n));
	}
	printf("%.10f\n",minD/2.0);
}