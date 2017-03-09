#include "stdio.h"
#include "algorithm"

#define INF 1000000000

int t,n,m;
int c[400][400];
int dyn[400][400];

int main(){
	scanf("%d",&t);
	for(int k = 1; k <= t; k++){
		scanf("%d%d",&n,&m);
		for(int j = 0; j <= m; j++){
			dyn[0][j] = INF;
		}
		dyn[0][0] = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 0; j < m; j++){
				scanf("%d",&c[i][j]);
			}
			
			std::sort(c[i],c[i]+m);

			for(int j = 0; j <= m; j++){
				//buy 0
				if(j<m) dyn[i][j] = dyn[i-1][j+1];
				else dyn[i][j] = INF;
				int sum = 0;
				for(int x = 0; x < m && j-x>=0; x++){
					sum += c[i][x];
					dyn[i][j] = std::min(dyn[i][j],dyn[i-1][j-x] + sum + (x+1)*(x+1) );
				}
			}

		}
		printf("Case #%d: %d\n",k,dyn[n][0]);
	}
}