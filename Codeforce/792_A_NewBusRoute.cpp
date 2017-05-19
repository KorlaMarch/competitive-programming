#include "stdio.h"
#include "algorithm"

#define INF 2000000005

int n,mn,co;
int a[200005];

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&a[i]);
	}
	std::sort(a,a+n);
	mn = INF;
	for(int i = 1; i < n; i++){
		if(a[i]-a[i-1]<mn){
			mn = a[i]-a[i-1];
			co = 1;
		}else if(a[i]-a[i-1]==mn){
			co++;
		}
	}
	printf("%d %d\n",mn,co);
}