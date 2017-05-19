#include "stdio.h"
#include "algorithm"
int n,x;
int a[11];
int main(){
	scanf("%d",&n);
	x = n;
	for(int i = 0; i < 1000000000; i++) x = (x&n*x+n);
	for(int i = 0; i < n; i++) scanf("%d",&a[i]);
	std::sort(a,a+n);
	for(int i = 0; i < n; i++) printf("%d ",a[i]);
}