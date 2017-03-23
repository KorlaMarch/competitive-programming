#include "stdio.h"
#include "algorithm"

#define INF 2000000000

int n,s,mx;
int h[2005];
int score[2005][1005];
int dyn[2][20005];

int main(){
	scanf("%d%d",&n,&s);
	for(int i = 1; i <= n; i++){
		const int ind = i%2;
		scanf("%d",&h[i]);
		for(int j = 1; j <= h[i]; j++){
			scanf("%d",&score[i][j]);
			score[i][j] += score[i][j-1];
		}

		for(int j = 0; j < i; j++){
			dyn[ind][j] = -INF;
		}
		// for(int j = i, k = 0; j <= s; j++){
		// 	if(j) dyn[ind][j] = dyn[!ind][j-k-1] + score[i][k];
		// 	else dyn[ind][j] = 0;

		// 	while(k+1 <= h[i] && j-k-2 >=0 && dyn[!ind][j-k-2] + score[i][k+1] > dyn[ind][j]){
		// 		k++;
		// 		dyn[ind][j] = dyn[!ind][j-k-1] + score[i][k];
		// 	}
		// 	//printf("%d %d : %d %d\n",i,j,dyn[ind][j],mxP);
		// 	mx = std::max(mx,dyn[ind][j]);
		// }
		for(int j = i; j <= s; j++){
			dyn[ind][j] = dyn[!ind][j-1];
			int mxP = 0;
			int k;
			for(k = 1; k <= h[i] && j-k-1>=0; k++){
				if(dyn[ind][j] < dyn[!ind][j-k-1] + score[i][k]){
					mxP = k;
					dyn[ind][j] = dyn[!ind][j-k-1] + score[i][k];
				}
			}
			if(k<=h[i]){
				if(dyn[ind][j] < score[i][k]){
					mxP = k;
					dyn[ind][j] = score[i][k];
				}
			}
			printf("%d %d : %d %d\n",i,j,dyn[ind][j],mxP);
			mx = std::max(mx,dyn[ind][j]);
		}
	}
	printf("%d\n",mx);
}