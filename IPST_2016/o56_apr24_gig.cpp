#include "stdio.h"
#include "algorithm"

#define INF 1000000000

int n;
int dyn[505][505];
int m[505][505];
int mn;

int main(){
	scanf("%d",&n);
	for(int i = 1; i < n; i++){
		for(int j = i+1; j <= n; j++){
			scanf("%d",&m[i][j]);
			//printf("M[%d][%d] = %d\n",i,j,m[i][j]);
		}
	}

	dyn[2][1] = m[1][2];

	for(int i = 3; i < n; i++){
		for(int j = 1; j < i-1; j++){
			dyn[i][j] = dyn[i-1][j]+m[i-1][i];
		}

		dyn[i][i-1] = INF;
		for(int k = 1; k < i-1; k++){
			dyn[i][i-1] = std::min(dyn[i][i-1],dyn[i-1][k]+m[k][i]);
		}

		// for(int j = 1; j < i; j++){
		// 	printf("%d %d: %d\n",i,j,dyn[i][j]);
		// }
	}

	mn = INF;
	for(int j = 1; j+1 < n; j++){
		//printf("%d : %d %d %d\n",j,dyn[n-1][j],m[n-1][n],m[j][n]);
		mn = std::min(mn,dyn[n-1][j]+m[n-1][n]+m[j][n]);
	}

	printf("%d\n",mn);
}