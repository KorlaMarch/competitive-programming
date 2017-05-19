#include "stdio.h"
#include "algorithm"

#define INF 1000000000

int n;
int ci[305];
int dyn[305][305];

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&ci[i]);
	}
	for(int i = n-1; i >= 0; i--){
		dyn[i][i] = ci[i];
		for(int j = i+1; j < n; j++){
			dyn[i][j] = INF;
			for(int k = i; k <= j; k++){
				dyn[i][j] = std::min(dyn[i][j],ci[k]+std::max(dyn[i][k-1],dyn[k+1][j]));
			}
		}
	}
	printf("%d\n",dyn[0][n-1]);
}