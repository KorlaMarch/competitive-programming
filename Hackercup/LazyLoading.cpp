#include "stdio.h"
#include "algorithm"

int t,n;
int w[1000];

int main(){
	scanf("%d",&t);
	for(int k = 1; k <= t; k++){
		scanf("%d",&n);
		for(int i = 0; i < n; i++){
			scanf("%d",&w[i]);
		}
		std::sort(w,w+n);
		int i,j,count = 0;
		for(i = 0, j = n-1; i <= j; j--, count++){
			int sum = w[j];
			for(; i < j && sum < 50; i++) sum += w[j];
			if(sum<50) break;
		}
		printf("Case #%d: %d\n",k,count);
	}
}