#include "stdio.h"

#define MOD 2012

int n,k;
int dyn[2][10005];

int main(){
	scanf("%d%d",&n,&k);
	dyn[1][0] = 1;
	for(int i = 2; i <= n; i++){
		const int ind = i%2;
		int sum = 0;
		for(int j = 0; j <= k; j++){
			sum += dyn[!ind][j];
			if(j-i>=0) sum += MOD - dyn[!ind][j-i];
			sum %= MOD;
			dyn[ind][j] = sum;
		}
	}
	printf("%d\n",dyn[n%2][k]);
}