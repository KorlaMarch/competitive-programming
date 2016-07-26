#include "stdio.h"
#include "algorithm"

int n;
std::pair<int,int> a[105];

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&a[i].first);
		a[i].second = i+1;
	}
	std::sort(a,a+n);
	for(int i = 0; i < n-i; i++){
		printf("%d %d\n",a[i].second,a[n-i-1].second);
	}

}