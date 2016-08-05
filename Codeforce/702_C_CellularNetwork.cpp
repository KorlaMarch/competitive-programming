#include "stdio.h"
#include "algorithm"

#define INF 3000000001LL

int n,m;
long long a[100005];
long long b[100005];
long long r;

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++){
		scanf("%I64d",&a[i]);
	}
	for(int j = 1; j <= m; j++){
		scanf("%I64d",&b[j]);
	}
	b[0] = -INF;
	b[m+1] = INF;

	for(int i = 0, j = 0; i < n; i++){
		for(; j <= m && b[j+1]<=a[i]; j++);
		r = std::max(r,std::min(a[i]-b[j],b[j+1]-a[i]));
	}
	printf("%I64d",r);

}