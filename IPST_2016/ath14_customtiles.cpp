#include "stdio.h"

int t,n,k;
long long way[105][105];

int main(){
	scanf("%d",&t);
	for(int x = 0; x < t; x++){
		scanf("%d%d",&n,&k);

		for(int i = 1; i <= k; i++){
			way[0][i] = 0;
		}
		way[0][0] = 1;
		for(int i = 1; i <= n; i++){
			for(int j = 0; j <= k; j++){
				way[i][j] = way[i-1][j];
				if(i>1) way[i][j] += way[i-2][j];
				if(i>1&&j>0) way[i][j] += way[i-2][j-1];
				
				if(j>1){
					for(int p = i-3; p >= 0; p -= 2){
						way[i][j] += 2*way[p][j-2];
					}
					for(int p = i-4; p >= 0; p -= 2){
						way[i][j] += 2*way[p][j-2];
					}
				}
				way[i][j] %= 9241;
			}
		}
		
		long long ans = 0;
		for(int i = 0; i <= k; i++){
			ans += way[n][i];
		}

		printf("%lld\n",ans%9241);
	}
}