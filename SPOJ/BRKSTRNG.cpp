#include "stdio.h"

#define INF 1000000000

int n,m;
int pos[1005];
int dyn[1005][1005];

int main(){
	while(scanf("%d%d",&n,&m)==2){
		pos[0] = 1;
		for(int i = 1; i <= m; i++){
			scanf("%d",&pos[i]);
		}
		pos[m+1] = n;
		m += 2;

		for(int i = m-1; i >= 0; i--){
			dyn[i][i+1] = 0;
			for(int j = i+2; j < m; j++){
				dyn[i][j] = INF;
				int uk = -1;
				for(int k = i+1; k < j; k++){
					if(dyn[i][j] > dyn[i][k] + dyn[k+1][j]){
						dyn[i][j] = dyn[i][k] + dyn[k][j];
						uk = k;
					}
				}
				dyn[i][j] += pos[j]-pos[i]+1;
				printf("%d %d : %d(%d)\n",i,j,dyn[i][j],uk);
			}
		}
	}
}