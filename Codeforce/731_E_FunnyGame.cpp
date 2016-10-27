#include "stdio.h"
#include "algorithm"
#include "queue"

int n,mx;
int a[200005];

int main(){
	scanf("%d",&n);
	for(int i = 1; i <= n; i++){
		scanf("%d",&a[i]);
		a[i] += a[i-1];
	}
	mx = a[n];
	for(int i = n-1; i > 1; i--){
		mx = std::max(mx,a[i]-mx);
	}

	printf("%d\n",mx);
}