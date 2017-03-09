#include "stdio.h"
#include "algorithm"

int n,x;
long long oper;
int a[100005];

int main(){
	scanf("%d%d%d",&n,&x,&a[0]);
	for(int i = 1; i < n; i++){
		scanf("%d",&a[i]);
		if(a[i]+a[i-1]>x){
			const int ch = std::min(a[i],a[i]+a[i-1]-x);
			oper += ch;
			a[i] -= ch;
		}

		if(a[i-1]>x){
			oper += a[i-1]-x;
			a[i-1] -= a[i-1]-x;
		}
	}
	printf("%lld\n",oper);
}