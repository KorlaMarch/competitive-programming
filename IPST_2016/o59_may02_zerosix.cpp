#include "stdio.h"
#include "algorithm"

int n,m,x,ans;
int dyn[105][105][1500];
int num[105][105];

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%d",&num[i][j]);
		}
	}
	dyn[0][1][0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			int c2 = 0, c3 = 0;
			x = num[i][j];

			while(x%2==0){
				c2++;
				x /= 2;
			}
			while(x%3==0){
				c3++;
				x /= 3;
			}

			for(int x = c3; x < 1500; x++){
				int mx = std::max(dyn[i-1][j][x-c3],dyn[i][j-1][x-c3]);
				if(mx){
					dyn[i][j][x] = mx+c2;
				}
			}
		}
	}

	for(int x = 0; x < 1500; x++){
		ans = std::max(ans,std::min(x,dyn[n][m][x]-1));
	}

	printf("%d\n",ans);
}