#include "stdio.h"
#include "algorithm"

int n;
std::pair<double,int> p[25][25];
bool isSe[25];
double mxP;
double bestPi[25];

bool cmp(std::pair<double,int> a, std::pair<double,int> b){
	return a.first>b.first;
}

void findMax(int d, double pi){
	if(pi*bestPi[d]<=mxP) return;
	else if(d==n){
		if(pi>mxP) mxP = pi;
	}else{
		for(int i = 0; i < n; i++){
			if(!isSe[p[d][i].second]){
				isSe[p[d][i].second] = true;
				findMax(d+1,pi*p[d][i].first);
				isSe[p[d][i].second] = false;
			}
		}
	}
}

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%lf",&p[i][j].first);
			p[i][j].first /= 100.0;
			p[i][j].second = j;
		}
		std::sort(p[i],p[i]+n,cmp);
	}
	mxP = 0;
	bestPi[n] = 1.0;

	for(int i = n-1; i >= 0; i--){
		bestPi[i] = bestPi[i+1]*p[i][0].first;
	}
	findMax(0,1.0);
	printf("%.10f\n",mxP*100.0);
}