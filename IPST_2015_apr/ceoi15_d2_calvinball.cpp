#include "stdio.h"
#include "algorithm"

#define MOD  1000007

int n;
int s[10005];
int mxS[10005];
long long dyn[2][10005];
long long sum;

int main(){
	scanf("%d",&n);
	for(int i = 1; i <= n; i++){
		scanf("%d",&s[i]);
		mxS[i] = std::max(s[i],mxS[i-1]);
	}
	for(int i = 2; i <= n; i++){
		for(int j = 1; j <= i; j++){
			dyn[i%2][j] = dyn[(i-1)%2][j]*j%MOD;
			dyn[i%2][j] = (dyn[i%2][j]+dyn[(i-1)%2][j-1])%MOD;
		}
		for(int j = 1; j < s[i]; j++){
			dyn[i%2][std::max(mxS[i-1],j)] = (dyn[i%2][std::max(mxS[i-1],j)]+1)%MOD;
		}
	}
	for(int i = 1; i <= n; i++){
		sum = (sum+dyn[n%2][i])%MOD;
	}
	printf("%lld\n",sum+1);
}