#include "stdio.h"
#include "algorithm"

long long d,k,a,b,t;
long long time;

int main(){
	scanf("%I64d %I64d %I64d %I64d %I64d",&d,&k,&a,&b,&t);
	if(b<=a){
		printf("%I64d\n",b*d);
	}else if(k*b<=k*a+t){
		if(d>=k){
			time = k*a;
			d -= k;
		}else{
			time = d*a;
			d = 0;
		}
		printf("%I64d\n",time+b*d);
	}else{
		time = d/k*(k*a+t);
		d %= k;
		time -= t;
		time += std::min(a*d+t,b*d);
		printf("%I64d\n",time);
	}
}