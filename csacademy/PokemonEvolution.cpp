#include "stdio.h"

long long n,m,x,y;

int main(){
	scanf("%lld%lld%lld%lld",&n,&m,&x,&y);
	long long i=0,j=n,mid;
	while(i<=j){
		mid = (i+j)/2;
		if(x*mid<=m+(n-mid)*y){
			i = mid+1;
		}else{
			j = mid-1;
		}
	}
	printf("%lld\n",j);
}