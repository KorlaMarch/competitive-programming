#include "stdio.h"
#include "math.h"
#include "algorithm"

#define EPSI 0.0000001

int k,n;
int ax[10],ay[10];
int mx[1005],my[1005];
bool canHit[1005];

bool isPosi(int x){
	return x>=0;
}

long long dis(int x, int y, int ind){
	return (x-mx[ind])*(long long)(x-mx[ind]) + (y-my[ind])*(long long)(y-my[ind]);
}

double getM(int x, int y, int ind){
	printf("Called %d %d %d : %d %d\n", x,y,ind,(y-my[ind]),(x-mx[ind]));
	return (y-my[ind])/(double)(x-mx[ind]);
}

double abs(double x){
	return x<0?-x:x;
}
bool checkHit(int x, int y, int ind){
	for(int i = 0; i < n; i++){
		if(i!=ind&&dis(x,y,i)<dis(x,y,ind)&&(isPosi(x-mx[i])==isPosi(x-mx[ind]))&&
			(abs(getM(x,y,ind)-getM(x,y,i))<EPSI||(std::isinf(getM(x,y,ind))&&std::isinf(getM(x,y,i))))){
			printf("%d %d CK %d(%d %d) %d(%d %d) : %f %f\n",x,y,ind,mx[ind],my[ind],i,mx[i],my[i],getM(x,y,ind),getM(x,y,i));
			return false;
		}
	}
	return true;
}

int main(){
	scanf("%d%d",&k,&n);
	for(int i = 0; i < k; i++){
		scanf("%d%d",&ax[i],&ay[i]);
	}
	for(int i = 0; i < n; i++){
		scanf("%d%d",&mx[i],&my[i]);
	}
	for(int i = 0; i < k; i++){
		printf("R:%d\n",i);
		for(int j = 0; j < n; j++){
			if(checkHit(ax[i],ay[i],j)){
				canHit[j] = true;
			}
		}
	}
	int co = 0;
	for(int i = 0; i < n; i++){
		if(canHit[i]) co++;
	}
	printf("%d\n",co);
}