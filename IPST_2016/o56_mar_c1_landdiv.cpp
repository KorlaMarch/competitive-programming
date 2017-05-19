#include "stdio.h"
#include "algorithm"

#define INF 100000000

int n,k,diff;
int v[105],qs[105];
int dyn[105][105];

int main(){
	scanf("%d%d",&n,&k);
	for(int i = 1; i <= n; i++){
		scanf("%d",&v[i]);
		qs[i] = qs[i-1]+v[i];
	}
	diff = qs[n];
	dyn[0][0] = INF;
	for(int a = 1; a <= n; a++){
		for(int b = a; b <= n; b++){
			const int maxL = qs[b]-qs[a-1];
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= k; j++){
					dyn[i][j] = 0;
					for(int x=i, sum = 0; x > 0; x--){
						sum += v[x];
						if(sum>maxL) break;
						dyn[i][j] = std::max(dyn[i][j],std::min(sum,dyn[x-1][j-1]));
					}
					//printf("%d %d %d : %d\n",maxL,i,j,dyn[i][j]);	
				}
			}
			if(dyn[n][k]) diff = std::min(diff,maxL-dyn[n][k]);
		}
	}

	printf("%d\n",diff);
}