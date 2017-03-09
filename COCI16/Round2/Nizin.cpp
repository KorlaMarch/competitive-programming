#include "stdio.h"

int n,co;
long long v[1000005];
long long sumX,sumY;

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%lld",&v[i]);
	}

	sumX = v[0];
	sumY = v[n-1];

	for(int x = 0, y = n-1; x < y; ){
		if(sumX==sumY){
			x++;
			y--;
			sumX = v[x];
			sumY = v[y];
		}else if(sumX<sumY){
			x++;
			sumX += v[x];
			co++;
		}else{
			y--;
			sumY += v[y];
			co++;
		}
	}

	printf("%d\n",co);
}