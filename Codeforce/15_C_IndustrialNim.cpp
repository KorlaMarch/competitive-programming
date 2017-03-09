#include "stdio.h"
#include "algorithm"

int n;
long long xi,mi,xo;

long long countZT(long long x, int d){
	long long pv = (1LL<<d);
	return x/(2*pv)*pv + std::min(x%(2*pv)+1,pv);
}

long long getXOR(long long xi, long long mi){
	long long c0,c1;
	long long res = 0;
	for(int i = 0; i < 60; i++){
		c0 = countZT(xi+mi-1,i)-countZT(xi-1,i);
		c1 = mi-c0;
		if(c1%2) res |= (1LL<<i);
	}
	return res;
}

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%I64d %I64d",&xi,&mi);
		xo ^= getXOR(xi,mi);
	}
	if(xo==0) printf("bolik\n");
	else printf("tolik\n");
}