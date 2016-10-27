#include "stdio.h"
#include "algorithm"

int n,ai,mxA;
int qs[200005];
long long sum,sol;

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&ai);
		qs[ai]++;
		mxA = std::max(ai,mxA);
	}
	for(int i = 1; i <= mxA; i++){
		qs[i] += qs[i-1];
	}
	for(int i = 1; i <= mxA; i++){
		if(qs[i]-qs[i-1]!=0){
			sum = 0;
			long long j;
			for(j = i; j+i-1 <= mxA; j += i){
				sum += j*(qs[j+i-1]-qs[j-1]);
			}
			sum += j*(qs[mxA]-qs[j-1]);

			sol = std::max(sol,sum);
		}
	}

	printf("%I64d\n",sol);

}