#include "stdio.h"
#include "algorithm"

int t,n,d,ki,si;
double minV;

int main(){
	scanf("%d",&t);
	for(int te = 1; te <= t; te++){
		scanf("%d%d",&d,&n);
		minV = 0.0;
		for(int i = 0; i < n; i++){
			scanf("%d%d",&ki,&si);
			double limV = d*(double)(si)/(d-ki);
			if(minV==0.0||limV<minV){
				minV = limV;
			}
		}
		printf("Case #%d: %.6f\n",te,minV);
	}
}