#include "stdio.h"

long long n,mul,final;
int u;

int main(){
	scanf("%lld",&n);
	for(mul = 1; n != 0; n /= 3, mul *= 3){
		if(n%3==2){
			u++;
			n++;
		}else if(n%3==1){
			u++;
			final += mul;
		}
	}
	printf("%d %lld\n",u,final);
}