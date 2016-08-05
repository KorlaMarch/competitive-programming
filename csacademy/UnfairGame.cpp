#include "stdio.h"
#include "algorithm"

int n;
int a[100005];
long long sum;

long long jmps(int i){
	long long sm = 0;
	for(; i >= 0; i -= 2) sm += a[i];
	return sm;
}

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&a[i]);
	}
	std::sort(a,a+n);
	int i;
	for(i = n-1; i >= 0 && a[i] >= 0; i--){
		sum += a[i];
	}
	if(i==n-1){
		sum += a[i];
		i--;
	}
	sum += std::max(jmps(i),jmps(i-1));
	printf("%lld\n",sum);
}