#include "stdio.h"
#include "math.h"
#include "algorithm"

long long abs(long long x){
	return x<0?-x:x;
}

int n;
int p[300005];
long long sum,sumA,sumB;
double avg;

long long findD(int x){
	long long sumD = 0;
	for(int i = 0; i < n; i++){
		sumD += abs(p[i]-x);
	}
	return x;
}

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&p[i]);
	}
	std::sort(p,p+n);
	if(n%2==1){
		printf("%d\n",p[n/2]);
	}else{
		printf("%d\n",p[n/2-1]);
	}
}